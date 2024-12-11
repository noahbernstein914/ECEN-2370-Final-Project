/*
 * GameDriver.h
 *
 *  Created on: Dec 2, 2024
 *      Author: noahbernstein
 */

#ifndef INC_GAMEDRIVER_H_
#define INC_GAMEDRIVER_H_
#include "Shape.h"
#include "Board.h"
#include "Scheduler.h"
#include "stm32f4xx_hal_rng.h"
#include "stmpe811.h"

#include "LCD_Driver.h"
#include <stdio.h>


void gameLoop(void);
void titleScreen(void);
void endScreen(uint16_t timePlayed);

#endif /* INC_GAMEDRIVER_H_ */
