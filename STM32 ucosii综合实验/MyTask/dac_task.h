#ifndef _dac_task_H
#define _dac_task_H
#include "public.h"

#define DA_TASK_PRIO 17     //开始任务优先级
#define DA_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	DA_TASK_STK[DA_STK_SIZE];	  //创建任务堆栈空间

void da_task(void *pdata);



#endif
