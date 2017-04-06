#ifndef _rs485_task_H
#define _rs485_task_H
#include "public.h"

#define COM2_TASK_PRIO 19     //开始任务优先级
#define COM2_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	COM2_TASK_STK[COM2_STK_SIZE];	  //创建任务堆栈空间

void rs485_task(void *pdata);



#endif
