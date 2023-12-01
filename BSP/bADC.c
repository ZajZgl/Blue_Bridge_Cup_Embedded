#include "bADC.h"

//数模转换ADC,读取电压值
double getADC(ADC_HandleTypeDef *pin)//ADC_HandleTypeDef管脚类型
{
	unsigned int adc;
	HAL_ADC_Start(pin);//开启ADC
	adc=HAL_ADC_GetValue(pin);
	return adc*3.3/4096;//3.3:最大电压，4096：12bit,2的12次幂
}
