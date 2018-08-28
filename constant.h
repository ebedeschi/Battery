/*
 * constant.h
 *
 *  Created on: 21 feb 2018
 *      Author: Emanuele
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

#define HAVE_HWSERIAL1 1

#define LED 8
#define RN_RESET 9
#define BAT_ADC_EN PIN_A1
#define BAT_ADC PIN_A5
#define DS18B20_PIN 11

/*! @enum DeviceState
 */
enum DeviceState
{
    DEVICE_STATE_INIT = 0,
    DEVICE_STATE_JOIN = 1,
    DEVICE_STATE_SEND = 2,
    DEVICE_STATE_SLEEP = 3
};

#endif /* CONSTANT_H_ */
