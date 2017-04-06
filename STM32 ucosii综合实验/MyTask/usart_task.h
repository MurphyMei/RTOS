#ifndef _usart_task_H
#define _usart_task_H
#include "public.h"

#define COM1_TASK_PRIO 18     //开始任务优先级
#define COM1_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	COM1_TASK_STK[COM1_STK_SIZE];	  //创建任务堆栈空间

void com_task(void *pdata);



#endif
