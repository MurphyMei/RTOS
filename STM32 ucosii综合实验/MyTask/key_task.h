#ifndef _key_task_H
#define _key_task_H
#include "public.h"

#define BUTTON_TASK_PRIO 5     //开始任务优先级
#define BUTTON_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	BUTTON_TASK_STK[BUTTON_STK_SIZE];	  //创建任务堆栈空间

void button_task(void *pdata);



#endif
