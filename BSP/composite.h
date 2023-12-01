#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__
#include "tim.h"

#include "main.h"
#include "led.h"
#include "lcd.h"
#include "key.h"
#include "stdio.h"
extern unsigned int view_i;
extern struct keys key[];
extern unsigned int a6_pwm;
extern unsigned int a7_pwm;
void key_pwm(void);
void key_funct_menu(void);
void view(unsigned int vi);

#endif
