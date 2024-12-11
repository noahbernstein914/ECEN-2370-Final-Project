/*
 * Board.c
 *
 *  Created on: Dec 2, 2024
 *      Author: noahbernstein
 */
#include "Board.h"

Board boardInit()
{
    Board newBoard;
    newBoard.gameOver = false;
    newBoard.startTime = 0;
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            newBoard.gameBoard[y][x] = 'b'; // b for blank
        }
    }
    return newBoard;
}

uint16_t getColorFromChar(char c)
{
    switch (c)
    {
    case 'i':
        return I_BLOCK_COLOR;
    case 'o':
        return O_BLOCK_COLOR;
    case 't':
        return T_BLOCK_COLOR;
    case 's':
        return S_BLOCK_COLOR;
    case 'z':
        return Z_BLOCK_COLOR;
    case 'j':
        return J_BLOCK_COLOR;
    case 'l':
        return L_BLOCK_COLOR;
    case 'b':
        return BLANK_BLOCK_COLOR;
    default:
        return 0x1224; 
    }
}

void drawBoard(Board *board)
{
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            char cell = board->gameBoard[y][x];
            uint16_t drawX = X_START + x * CELL_WIDTH;
            uint16_t drawY = Y_START + y * CELL_HEIGHT;
            uint16_t color = getColorFromChar(cell);
            LCD_Draw_Filled_Rectangle(drawX, drawY, CELL_WIDTH, CELL_HEIGHT, color);
        }
    }

    for (uint16_t lineX = X_START; lineX <= X_START + GRID_WIDTH; lineX += CELL_WIDTH)
    {
        LCD_Draw_Vertical_Line(lineX, Y_START, GRID_HEIGHT, LCD_COLOR_BLACK);
    }
    for (uint16_t lineY = Y_START; lineY <= Y_START + GRID_HEIGHT; lineY += CELL_HEIGHT)
    {
        LCD_Draw_Horizontal_Line(X_START, lineY, GRID_WIDTH, LCD_COLOR_BLACK);
    }
}
