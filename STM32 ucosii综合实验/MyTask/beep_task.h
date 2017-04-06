#ifndef _beep_task_H
#define _beep_task_H
#include "public.h"

#define BEEP_TASK_PRIO 2     //开始任务优先级
#define BEEP_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	BEEP_TASK_STK[BEEP_STK_SIZE];	  //创建任务堆栈空间

void beep_task(void *pdata);



#endif
