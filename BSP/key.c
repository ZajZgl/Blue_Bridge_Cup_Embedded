#include "key.h"

struct keys key[4]={0,0,0,0,0};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//中断服务函数
{
	if(htim->Instance==TIM3)
	{
		key[0].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);//读取按键状态
		key[1].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
		key[2].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
		key[3].key_sta=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
		for(int i=0;i<4;i++)
		{
			switch (key[i].judge_sta)
			{
				case 0://判断是否按下
				{
					if(key[i].key_sta == 0)
					{
						key[i].judge_sta=1;
						key[i].key_time=0;
					}
				}break;
				
				case 1://再次判断是否按下——消抖
				{
					if(key[i].key_sta == 0) 
					{
						key[i].judge_sta=2;
						
					}
					else key[i].judge_sta=0;
				}break;
				case 2:
				{
					if(key[i].key_sta == 1) //按键抬起后标志置1
					{
						key[i].judge_sta=0;//key[i].single_flag在主函数中置零
						if(key[i].key_time<70)//长按时间
						{							
							key[i].single_flag=1;//标志短按键按下
							key[i].key_time=0;
						}
					}
					else//按键未抬起
					{
						key[i].key_time++;
						if(key[i].key_time>70)//长按时间
						{							
							key[i].single_long_flag=1;//标志长按键按下
							key[i].key_time=0;
						}
					}
				}break;
			}
		}
	}
}
