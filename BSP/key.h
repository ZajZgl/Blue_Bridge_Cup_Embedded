#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"
#include "stdbool.h"//bool
struct keys
{
	unsigned judge_sta;
	bool key_sta;
	bool single_flag;
	bool single_long_flag;
	unsigned int key_time;
};
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);//中断服务函数


#endif
