#include "main.h"
#include "led.h"
#include "stdbool.h"//bool


//TIM6_定时中断_中断函数
extern unsigned int key[4][3];
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

//TIM2-ch1 和 TIM3-ch1中断回调函数
extern int frequency1;
extern int frequency2;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);


//按键中断
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
