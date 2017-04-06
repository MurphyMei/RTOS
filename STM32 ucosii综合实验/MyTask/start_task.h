#ifndef _start_task_H
#define _start_task_H
#include "public.h"

#define START_TASK_PRIO 60     //开始任务优先级
#define START_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	START_TASK_STK[START_STK_SIZE];	  //创建任务堆栈空间

void start_task(void *pdata);



#endif
