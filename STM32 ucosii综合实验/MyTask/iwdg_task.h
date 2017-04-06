#ifndef _iwdg_task_H
#define _iwdg_task_H
#include "public.h"

#define IWDG_TASK_PRIO 10     //开始任务优先级
#define IWDG_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	IWDG_TASK_STK[IWDG_STK_SIZE];	  //创建任务堆栈空间

void iwdg_task(void *pdata);



#endif
