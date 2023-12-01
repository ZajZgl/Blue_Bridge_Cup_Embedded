#include "interrupt.h"

//TIM6_定时中断_中断函数

unsigned int key[4][3]={0};

//判断 key[i][0]==0/1  按键实时状态
//判断 key[i][1]>4 按键是否按下
//key[i][2]按键按下次数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM6)
	{
		//开关检测
		key[0][0]=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);//读取按键状态
		key[1][0]=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);//按下时读数为零
		key[2][0]=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
		key[3][0]=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
		for(int i=0;i<4;i++)
		{
			if(key[i][0]==0)//判断是否按下
				key[i][1]++;
			else
				key[i][1]=0;
			
			if(key[i][1]==4)//判断按下时长，消抖
			{
				key[i][2]++;//按键按下次数
			}
			else
				;
		}
	}
}

//TIM2-ch1 和 TIM3-ch1中断回调函数
int time_count_1=0;//计数值
int frequency1=0;//频率

int time_count_2=0;//计数值
int frequency2=0;//频率

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM2)
	{
		time_count_1 = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);//读取计数器值
		__HAL_TIM_SetCounter(htim,0);//计数器清零 
		frequency1 = (80000000/80)/time_count_1;//计算频率
		HAL_TIM_IC_Start(htim,TIM_CHANNEL_1);//重新开启定时器
	}
	if(htim->Instance==TIM3)
	{
		time_count_2 = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);
		__HAL_TIM_SetCounter(htim,0); 
		frequency2 = (80000000/80)/time_count_2;
		HAL_TIM_IC_Start(htim,TIM_CHANNEL_1);//重新开启定时器
	}
}

