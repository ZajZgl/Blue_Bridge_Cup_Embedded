#include "bADC.h"

//��ģת��ADC,��ȡ��ѹֵ
double getADC(ADC_HandleTypeDef *pin)//ADC_HandleTypeDef�ܽ�����
{
	unsigned int adc;
	HAL_ADC_Start(pin);//����ADC
	adc=HAL_ADC_GetValue(pin);
	return adc*3.3/4096;//3.3:����ѹ��4096��12bit,2��12����
}
