#ifndef _led_task_H
#define _led_task_H
#include "public.h"

#define LED1_TASK_PRIO 2     //��ʼ�������ȼ�
#define LED1_STK_SIZE 64     //���������ջ��С
static OS_STK 	LED1_TASK_STK[LED1_STK_SIZE];	  //���������ջ�ռ�

void led1_task(void *pdata);



#endif
