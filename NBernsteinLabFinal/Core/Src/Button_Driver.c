#include <stdbool.h>
#include "stm32f4xx_hal.h"


void BUTTON_Enable_Clock()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
}
void BUTTON_Init()
{
    GPIO_InitTypeDef pinConfig = {0};
    pinConfig.Pin = GPIO_PIN_0;
    pinConfig.Mode = GPIO_MODE_INPUT;
    pinConfig.Pull = GPIO_NOPULL;
    pinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
    BUTTON_Enable_Clock();
    HAL_GPIO_Init(GPIOA, &pinConfig);
}

bool BUTTON_Pressed_Value()
{
    /*
    #define BUTTON_PORT_VALUE 0
    #define BUTTON_PIN_NUMBER 0
    #define BUTTON_PRESSED 1
    #define BUTTON_NOT_PRESSED 0*/

    uint8_t button_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
    if (button_state == GPIO_PIN_1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BUTTON_Init_InterruptMode()
{
    GPIO_InitTypeDef pinConfig = {0};
    pinConfig.Pin = GPIO_PIN_0;
    pinConfig.Mode = GPIO_MODE_IT_RISING_FALLING;
    pinConfig.Pull = GPIO_NOPULL;
    pinConfig.Speed = GPIO_SPEED_FREQ_HIGH;
    BUTTON_Enable_Clock();
    HAL_GPIO_Init(GPIOA, &pinConfig);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
