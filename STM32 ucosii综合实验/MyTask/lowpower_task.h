#ifndef _lowpower_task_H
#define _lowpower_task_H
#include "public.h"

#define LOW_TASK_PRIO 12     //开始任务优先级
#define LOW_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	LOW_TASK_STK[LOW_STK_SIZE];	  //创建任务堆栈空间

void low_task(void *pdata);



#endif
