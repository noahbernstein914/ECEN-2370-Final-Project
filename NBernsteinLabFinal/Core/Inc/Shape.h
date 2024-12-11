/*
 * Shape.h
 *
 *  Created on: Dec 2, 2024
 *      Author: noahbernstein
 */

#ifndef SHAPES_H_
#define SHAPES_H_

#include <stdint.h>
#include "LCD_Driver.h"
#include "Board.h"

#define INITIAL_X_POSITION 3
#define INITIAL_Y_POSITION 0

#define I_PIECE 0
#define O_PIECE 1
#define T_PIECE 2
#define S_PIECE 3
#define Z_PIECE 4
#define J_PIECE 5
#define L_PIECE 6

#define I_PIECE_COLOR 0x07FF // cyan
#define O_PIECE_COLOR 0xFFE0 // yellow
#define T_PIECE_COLOR 0xF81F // Magenta
#define S_PIECE_COLOR 0x07E0 // Green
#define Z_PIECE_COLOR 0xF800 // Red
#define J_PIECE_COLOR 0x001F // blue
#define L_PIECE_COLOR 0xFD20 // Orange

typedef struct
{
    uint8_t type;        //0-6
    uint8_t orientation; //0-3
    uint16_t color;      
    int8_t blocks[4][4]; //4x4 matrix made of 1s and 0s for enabled squares
    int x;               
    int y;              
} Shape;

Shape createShape(uint8_t type, Board *board);
void drawShape(Shape *shape, Board *board);
void displayShape(Shape *shape, Board *board);
void fillShape(Shape *shape, Board *board);
void clearShape(Shape *shape, Board *board);
void clearDisplayShape(Shape *shape, Board *board);
void unFillShape(Shape *shape, Board *board);
void rotateShape(Shape *shape, Board *board);
void moveDown(Shape *shape, Board *board);
void moveLeft(Shape *shape, Board *board);
void moveRight(Shape *shape, Board *board);
char typeToChar(uint8_t type);
bool canFall(Shape *shape, Board *board);

uint16_t getColorForType(uint8_t type);

#endif /* SHAPES_H_ */
