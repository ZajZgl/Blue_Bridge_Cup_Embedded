#include "interrupt.h"

//TIM6_��ʱ�ж�_�жϺ���

unsigned int key[4][3]={0};

//�ж� key[i][0]==0/1  ����ʵʱ״̬
//�ж� key[i][1]>4 �����Ƿ���
//key[i][2]�������´���
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM6)
	{
		//���ؼ��
		key[0][0]=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);//��ȡ����״̬
		key[1][0]=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);//����ʱ����Ϊ��
		key[2][0]=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2);
		key[3][0]=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
		for(int i=0;i<4;i++)
		{
			if(key[i][0]==0)//�ж��Ƿ���
				key[i][1]++;
			else
				key[i][1]=0;
			
			if(key[i][1]==4)//�жϰ���ʱ��������
			{
				key[i][2]++;//�������´���
			}
			else
				;
		}
	}
}

//TIM2-ch1 �� TIM3-ch1�жϻص�����
int time_count_1=0;//����ֵ
int frequency1=0;//Ƶ��

int time_count_2=0;//����ֵ
int frequency2=0;//Ƶ��

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM2)
	{
		time_count_1 = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);//��ȡ������ֵ
		__HAL_TIM_SetCounter(htim,0);//���������� 
		frequency1 = (80000000/80)/time_count_1;//����Ƶ��
		HAL_TIM_IC_Start(htim,TIM_CHANNEL_1);//���¿�����ʱ��
	}
	if(htim->Instance==TIM3)
	{
		time_count_2 = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);
		__HAL_TIM_SetCounter(htim,0); 
		frequency2 = (80000000/80)/time_count_2;
		HAL_TIM_IC_Start(htim,TIM_CHANNEL_1);//���¿�����ʱ��
	}
}

