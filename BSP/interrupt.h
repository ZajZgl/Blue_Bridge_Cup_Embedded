#include "main.h"
#include "led.h"
#include "stdbool.h"//bool


//TIM6_��ʱ�ж�_�жϺ���
extern unsigned int key[4][3];
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

//TIM2-ch1 �� TIM3-ch1�жϻص�����
extern int frequency1;
extern int frequency2;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);


//�����ж�
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
