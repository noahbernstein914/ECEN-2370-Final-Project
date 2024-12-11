
#include "GameDriver.h"

void gameLoop(void)
{
    bool run = false;
    titleScreen();

    uint32_t displayNum = 0;

    STMPE811_TouchData touchData; 

    while (!run)
        {
            LCD_Draw_Filled_Rectangle(0, 80, 300, 100, 0xffff);
            Board displayBoard = boardInit();
            Shape currentShape = createShape(displayNum, &displayBoard);
        	displayShape(&currentShape, &displayBoard);
            uint32_t events = getScheduledEvents();
            if (events & BUTTON_TOGGLE_EVENT)
            {
                run = true;
                removeSchedulerEvent(BUTTON_TOGGLE_EVENT);
            }
            HAL_Delay(1000);
            displayNum++;
            if(displayNum==7){displayNum=0;}

        }


    LCD_Clear(0, LCD_COLOR_WHITE);
    RNG_HandleTypeDef hrng = {0};
    hrng.Instance = RNG;
    HAL_RNG_Init(&hrng);

    uint32_t random32bit = 7;
    Board newBoard = boardInit();
    newBoard.startTime = HAL_GetTick();
    while (run)
    {
        HAL_RNG_GenerateRandomNumber(&hrng, &random32bit);
        Shape currentShape = createShape((uint8_t)random32bit % 7, &newBoard);
        if (!newBoard.gameOver){
        drawShape(&currentShape, &newBoard);
        HAL_Delay(300);
        while (canFall(&currentShape, &newBoard))
        {
        	STMPE811_ReadTouch(&touchData);

        	if (touchData.pressed == STMPE811_State_Pressed)
				{
        		touchData.pressed = STMPE811_State_Released;
        		if(touchData.x>120)
        		{
        			moveLeft(&currentShape, &newBoard);
        		}
        		else
        		{
        			moveRight(&currentShape, &newBoard);

        		}
				}
            uint32_t events = getScheduledEvents();
            if (events & BUTTON_TOGGLE_EVENT)
            {
                rotateShape(&currentShape, &newBoard);
                removeSchedulerEvent(BUTTON_TOGGLE_EVENT);
            }
            moveDown(&currentShape, &newBoard);
            HAL_Delay(300);
        }
        HAL_Delay(100);

        }
        else
        {
            run = false;
        }
    }
    endScreen(HAL_GetTick() - newBoard.startTime);
}

void endScreen(uint16_t timePlayed)
{
    LCD_Clear(0, LCD_COLOR_BLACK);
    LCD_SetTextColor(LCD_COLOR_WHITE);
    LCD_SetFont(&Font16x24);
    LCD_DisplayChar(60, 100, 'G');
    LCD_DisplayChar(75, 100, 'A');
    LCD_DisplayChar(90, 100, 'M');
    LCD_DisplayChar(105, 100, 'E');
    LCD_DisplayChar(130, 100, 'O');
    LCD_DisplayChar(145, 100, 'V');
    LCD_DisplayChar(160, 100, 'E');
    LCD_DisplayChar(175, 100, 'R');
    LCD_SetFont(&Font12x12);
    LCD_DisplayChar(40, 150, 'T');
    LCD_DisplayChar(52, 150, 'i');
    LCD_DisplayChar(64, 150, 'm');
    LCD_DisplayChar(76, 150, 'e');
    LCD_DisplayChar(88, 150, ' ');
    LCD_DisplayChar(100, 150, 'P');
    LCD_DisplayChar(112, 150, 'l');
    LCD_DisplayChar(124, 150, 'a');
    LCD_DisplayChar(136, 150, 'y');
    LCD_DisplayChar(148, 150, 'e');
    LCD_DisplayChar(160, 150, 'd');
    LCD_DisplayChar(172, 150, ':');
    LCD_DisplayChar(184, 150, ' ');
    uint16_t seconds = timePlayed / 1000;
    char digits[5];
    int index = 0;
    if (seconds == 0)
    {
        digits[index++] = '0';
    }
    else
    {
        while (seconds > 0)
        {
            digits[index++] = (seconds % 10) + '0';
            seconds /= 10;
        }
    }
    uint16_t xPosition = 200;
    for (int i = index - 1; i >= 0; i--)
    {
        LCD_DisplayChar(xPosition, 150, digits[i]);
        xPosition += 12;
    }
    LCD_DisplayChar(xPosition, 150, ' ');
    xPosition += 12;
    LCD_DisplayChar(xPosition, 150, 's');
}

void titleScreen()
{
    LCD_Clear(0, LCD_COLOR_WHITE);

    LCD_SetTextColor(LCD_COLOR_RED);
    LCD_SetFont(&Font16x24);
    LCD_DisplayChar(40, 40, 'T');
    LCD_SetTextColor(LCD_COLOR_BLUE);
    LCD_DisplayChar(70, 40, 'E');
    LCD_SetTextColor(LCD_COLOR_MAGENTA);
    LCD_DisplayChar(100, 40, 'T');
    LCD_SetTextColor(LCD_COLOR_GREEN);
    LCD_DisplayChar(130, 40, 'R');
    LCD_SetTextColor(LCD_COLOR_YELLOW);
    LCD_DisplayChar(160, 40, 'I');
    LCD_SetTextColor(LCD_COLOR_BLUE);
    LCD_DisplayChar(190, 40, 'S');


    LCD_SetTextColor(LCD_COLOR_BLACK);

    LCD_SetFont(&Font16x24);
    LCD_DisplayChar(30, 250, 'P');
    LCD_DisplayChar(45, 250, 'r');
    LCD_DisplayChar(55, 250, 'e');
    LCD_DisplayChar(65, 250, 's');
    LCD_DisplayChar(75, 250, 's');
    LCD_DisplayChar(90, 250, ' ');
    LCD_DisplayChar(105, 250, 'b');
    LCD_DisplayChar(115, 250, 'u');
    LCD_DisplayChar(125, 250, 't');
    LCD_DisplayChar(135, 250, 't');
    LCD_DisplayChar(145, 250, 'o');
    LCD_DisplayChar(155, 250, 'n');
    LCD_DisplayChar(170, 250, ' ');
    LCD_DisplayChar(185, 250, 't');
    LCD_DisplayChar(195, 250, 'o');
    LCD_DisplayChar(210, 250, ' ');

    LCD_DisplayChar(95, 275, 's');
    LCD_DisplayChar(105, 275, 't');
    LCD_DisplayChar(115, 275, 'a');
    LCD_DisplayChar(125, 275, 'r');
    LCD_DisplayChar(135, 275, 't');
}
