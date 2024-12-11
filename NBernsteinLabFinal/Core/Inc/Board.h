/*
 * Board.h
 *
 *  Created on: Dec 2, 2024
 *      Author: noahbernstein
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_
#include <stdint.h>
#include <stdbool.h>

#include "LCD_Driver.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

#define X_START 45
#define Y_START 10
#define X_DISPLAY_START -20
#define Y_DISPLAY_START 100
#define CELL_WIDTH 15
#define CELL_HEIGHT 15
#define GRID_WIDTH (CELL_WIDTH * BOARD_WIDTH)
#define GRID_HEIGHT (CELL_HEIGHT * BOARD_HEIGHT)

#define I_BLOCK_COLOR 0x07FF	 // cyan
#define O_BLOCK_COLOR 0xFFE0	 // yellow
#define T_BLOCK_COLOR 0xF81F	 // Magenta
#define S_BLOCK_COLOR 0x07E0	 // Green
#define Z_BLOCK_COLOR 0xF800	 // Red
#define J_BLOCK_COLOR 0x001F	 // blue
#define L_BLOCK_COLOR 0xFD20	 // Orange
#define BLANK_BLOCK_COLOR 0xFFFF // White

typedef struct
{

	bool gameOver;
	uint32_t startTime;
	char gameBoard[BOARD_HEIGHT][BOARD_WIDTH]; // gameBoard[y][x]
} Board;

Board boardInit();
void drawBoard(Board *board);
uint16_t getColorFromChar(char c);


#endif /* INC_BOARD_H_ */
