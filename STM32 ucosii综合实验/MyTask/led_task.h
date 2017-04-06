#ifndef _led_task_H
#define _led_task_H
#include "public.h"

#define LED1_TASK_PRIO 2     //开始任务优先级
#define LED1_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	LED1_TASK_STK[LED1_STK_SIZE];	  //创建任务堆栈空间

void led1_task(void *pdata);



#endif
