#include "composite.h"
unsigned int view_i=0;
unsigned int a6_pwm=10;
unsigned int a7_pwm=10;

void key_funct_menu(void)//²Ëµ¥
{
	if(key[0].single_flag==1)
	{
		key[0].single_flag=0;
		view_i=0;
	}
	else if(key[1].single_flag==1)
	{
		key[1].single_flag=0;
		view_i=1;
	}
	else if(key[2].single_flag==1)
	{
		key[2].single_flag=0;
		view_i=2;
	}
	else if(key[3].single_flag==1)
	{
		key[3].single_flag=0;
		view_i=3;
	}
	else ;
	view(view_i);
}
void key_pwm(void)
{
	if(key[0].single_flag==1)
	{
		key[0].single_flag=0;
		if(a6_pwm<90) a6_pwm+=10;
		else a6_pwm=10;
	}
	if(key[1].single_flag==1)
	{
		key[1].single_flag=0;
		if(a7_pwm<90) a7_pwm+=10;
		else a7_pwm=10;
	}
	__HAL_TIM_SetCompare(&htim16,TIM_CHANNEL_1,a6_pwm);
	__HAL_TIM_SetCompare(&htim17,TIM_CHANNEL_1,a7_pwm);
	char lcd_text[30];
	LCD_Clear(White);
	sprintf(lcd_text," view<%d> ",a6_pwm);
	LCD_DisplayStringLine(Line4, (unsigned char *)lcd_text);
	sprintf(lcd_text," view<%d> ",a7_pwm);
	LCD_DisplayStringLine(Line5, (unsigned char *)lcd_text);
}
void view(unsigned int vi)
{
	if(vi==0)
	{
		char lcd_text[30];
		LCD_Clear(White);
		sprintf(lcd_text," view<%d> ",vi);
		LCD_DisplayStringLine(Line4, (unsigned char *)lcd_text);
	}
	else if(vi==1)
	{
		char lcd_text[30];
		LCD_Clear(White);
		sprintf(lcd_text," view<%d> ",vi);
		LCD_DisplayStringLine(Line4, (unsigned char *)lcd_text);
	}
	else if(vi==2)
	{
		char lcd_text[30];
		LCD_Clear(White);
		sprintf(lcd_text," view<%d> ",vi);
		LCD_DisplayStringLine(Line4, (unsigned char *)lcd_text);
	}
	else if(vi==3)
	{
		char lcd_text[30];
		LCD_Clear(White);
		sprintf(lcd_text," view<%d> ",vi);
		LCD_DisplayStringLine(Line4, (unsigned char *)lcd_text);
	}
	else ;
}
