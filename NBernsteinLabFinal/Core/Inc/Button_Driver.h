/*
 *  Button_Driver.h
 *
 *  Created on: Sep 24, 2024
 *      Author: noahbernstein
 */
#include <stdbool.h>
#include "stm32f4xx_hal.h"

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#define BUTTON_PORT_VALUE 0
#define BUTTON_PIN_NUMBER 0
#define BUTTON_PRESSED 1
#define BUTTON_NOT_PRESSED 0

void BUTTON_Init();
void BUTTON_Enable_Clock();
bool BUTTON_Pressed_Value();
void BUTTON_Init_InterruptMode();

#endif /* BUTTON_DRIVER_H_ */
