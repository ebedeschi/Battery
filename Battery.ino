#include "constant.h"

int sensorValue = 0;  // variable to store the value coming from the sensor

// the setup function runs once when you press reset or power the board
void setup() {
	  pinMode(LED, OUTPUT);
	  digitalWrite(LED, LOW);
	  pinMode(RN_RESET, OUTPUT);
	  digitalWrite(RN_RESET, LOW);
	  pinMode(BAT_ADC_EN, OUTPUT);
	  digitalWrite(BAT_ADC_EN, LOW);
	  pinMode(0, OUTPUT);
	  digitalWrite(0, LOW);
	  pinMode(1, OUTPUT);
	  digitalWrite(1, LOW);
	  Serial.begin(9600);

	  digitalWrite(LED, HIGH);
	  delay(10000);
	  digitalWrite(LED, LOW);

	  Serial.println("Start");

	  analogReadResolution(12);
	  //digitalWrite(BAT_ADC_EN, HIGH);
}

// the loop function runs over and over again forever
void loop() {

	int sensorValue = 0;
	digitalWrite(BAT_ADC_EN, HIGH);
	delay(500);
	sensorValue = analogRead(BAT_ADC);
	digitalWrite(BAT_ADC_EN, LOW);
	Serial.print("ADC: ");
	Serial.print(sensorValue);
	Serial.print(" V: ");
	float v = ((float)sensorValue)*(0.0013427734375);
	Serial.print(v);
	Serial.print(" A: ");
	float a = ( ( (v-3) / 1.2) * 254 ) + 1;
	uint8_t level = 0;
	if(a<=0)
		level = 1;
	else if(a>=254)
		level = 254;
	else
		level = (uint8_t) a;
	Serial.print(level);

	Serial.print(" A10: ");
	float a_10 = ( ( (v) / 10) * 255 );
	uint8_t level_10 = 0;
	if(a_10<=0)
		level_10 = 0;
	else if(a_10>=255)
		level_10 = 255;
	else
		level_10 = (uint8_t) a_10;
	Serial.println(level_10);

	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);              // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);              // wait for a second
}

