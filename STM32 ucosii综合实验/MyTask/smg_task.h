#ifndef _smg_task_H
#define _smg_task_H
#include "public.h"

#define SMG_TASK_PRIO 3     //开始任务优先级
#define SMG_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	SMG_TASK_STK[SMG_STK_SIZE];	  //创建任务堆栈空间

void smg_task(void *pdata);



#endif
