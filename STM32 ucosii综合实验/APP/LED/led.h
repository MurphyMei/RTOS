#ifndef _led_H
#define _led_H

#include "public.h"

#define LED GPIO_Pin_All
void LED_Init(void);
void led_display(void);
void led_huayang(void);
void led_sansuo(void);

#endif 
