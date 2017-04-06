#ifndef _touch_task_H
#define _touch_task_H
#include "public.h"

#define TOUCH_TASK_PRIO 1     //开始任务优先级
#define TOUCH_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	TOUCH_TASK_STK[TOUCH_STK_SIZE];	  //创建任务堆栈空间

void touch_task(void *pdata);



#endif
