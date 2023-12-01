#include "key.h"

struct keys key[4]={0,0,0,0,0};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//�жϷ�����
{
	if(htim->Instance==TIM3)
	{
		key[0].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);//��ȡ����״̬
		key[1].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
		key[2].key_sta=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
		key[3].key_sta=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
		for(int i=0;i<4;i++)
		{
			switch (key[i].judge_sta)
			{
				case 0://�ж��Ƿ���
				{
					if(key[i].key_sta == 0)
					{
						key[i].judge_sta=1;
						key[i].key_time=0;
					}
				}break;
				
				case 1://�ٴ��ж��Ƿ��¡�������
				{
					if(key[i].key_sta == 0) 
					{
						key[i].judge_sta=2;
						
					}
					else key[i].judge_sta=0;
				}break;
				case 2:
				{
					if(key[i].key_sta == 1) //����̧����־��1
					{
						key[i].judge_sta=0;//key[i].single_flag��������������
						if(key[i].key_time<70)//����ʱ��
						{							
							key[i].single_flag=1;//��־�̰�������
							key[i].key_time=0;
						}
					}
					else//����δ̧��
					{
						key[i].key_time++;
						if(key[i].key_time>70)//����ʱ��
						{							
							key[i].single_long_flag=1;//��־����������
							key[i].key_time=0;
						}
					}
				}break;
			}
		}
	}
}
