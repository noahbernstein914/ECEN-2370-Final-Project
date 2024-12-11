/*
 * Shape.c
 *
 *  Created on: Dec 2, 2024
 *      Author: noahbernstein
 */

#include "Shape.h"

// tetriminoes[type][orientation][y][x]
const int8_t TETROMINOES[7][4][4][4] = {
    // I_PIECE
    {
        
        {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}},
        
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0}}},
    // O_PIECE
    {
        {{0, 1, 1, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        {{0, 1, 1, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 1, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}},
    // T_PIECE
    {
        
        {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}}},
    // S_PIECE
    {
        
        {
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}},
         
        {
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
         
        {
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}}},
    // Z_PIECE
    {
        
        {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}},
         
        {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
         
        {
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}}},
    // J_PIECE
    {
        
        {
            {1, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}}},
    // L_PIECE
    {
        
        {
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}},
        
        {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}},
        
        {
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}}}};

Shape createShape(uint8_t type, Board *board)
{
    Shape newShape;
    newShape.type = type;
    newShape.orientation = 0;
    newShape.color = getColorForType(type);
    newShape.x = INITIAL_X_POSITION;
    newShape.y = INITIAL_Y_POSITION;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (board->gameBoard[y][x] != 'b')
            {
                board->gameOver = true;
            }
            newShape.blocks[y][x] = TETROMINOES[type][newShape.orientation][y][x];
        }
    }
    return newShape;
}

void rotateShape(Shape *shape, Board *board)
{
    clearShape(shape, board);
    shape->orientation = (shape->orientation + 1) % 4;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            shape->blocks[y][x] = TETROMINOES[shape->type][shape->orientation][y][x];
        }
    }
    drawShape(shape, board);
}

void fillShape(Shape *shape, Board *board)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (shape->blocks[y][x])
            {
                board->gameBoard[shape->y + y][shape->x + x] = typeToChar(shape->type);
            }
        }
    }
}

void drawShape(Shape *shape, Board *board)
{
    fillShape(shape, board);
    drawBoard(board);
}


void displayShape(Shape *shape, Board *board)
{
    fillShape(shape, board);
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            char cell = board->gameBoard[y][x];
            if (cell != 'b')
            {
                uint16_t drawX = X_DISPLAY_START + x * (2 * CELL_WIDTH); 
                uint16_t drawY = Y_DISPLAY_START + y * (2 * CELL_HEIGHT);
                uint16_t color = getColorFromChar(cell);
                LCD_Draw_Filled_Rectangle(drawX, drawY, 2 * CELL_WIDTH, 2 * CELL_HEIGHT, color);
            }
        }
    }
}


void unFillShape(Shape *shape, Board *board)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (shape->blocks[y][x])
            {
                board->gameBoard[shape->y + y][shape->x + x] = 'b';
            }
        }
    }
}

void clearShape(Shape *shape, Board *board)
{
    unFillShape(shape, board);
    drawBoard(board);
}



uint16_t getColorForType(uint8_t type)
{
    switch (type)
    {
    case I_PIECE:
        return I_PIECE_COLOR;
    case O_PIECE:
        return O_PIECE_COLOR;
    case T_PIECE:
        return T_PIECE_COLOR;
    case S_PIECE:
        return S_PIECE_COLOR;
    case Z_PIECE:
        return Z_PIECE_COLOR;
    case J_PIECE:
        return J_PIECE_COLOR;
    case L_PIECE:
        return L_PIECE_COLOR;
    default:
        return 0xffff;
    }
}

char typeToChar(uint8_t type)
{
    switch (type)
    {
    case I_PIECE:
        return 'i';
    case O_PIECE:
        return 'o';
    case T_PIECE:
        return 't';
    case S_PIECE:
        return 's';
    case Z_PIECE:
        return 'z';
    case J_PIECE:
        return 'j';
    case L_PIECE:
        return 'l';
    default:
        return 'b';
    }
}

void moveDown(Shape *shape, Board *board)
{
    unFillShape(shape, board);
    shape->y += 1;
    drawShape(shape, board);
}

void moveLeft(Shape *shape, Board *board)
{
    clearShape(shape, board);
    shape->x -= 1;
    drawShape(shape, board);
}

void moveRight(Shape *shape, Board *board)
{
    clearShape(shape, board);
    shape->x += 1;
    drawShape(shape, board);
}

bool canFall(Shape *shape, Board *board)
{

    unFillShape(shape, board);
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (shape->blocks[y][x])
            {
                if (shape->y + y + 1 >= BOARD_HEIGHT)
                {
                    fillShape(shape, board);
                    return false;
                }

                if (board->gameBoard[shape->y + y + 1][shape->x + x] != 'b')
                {
                    fillShape(shape, board);
                    return false;
                }
            }
        }
    }
    fillShape(shape, board);
    return true;
}
