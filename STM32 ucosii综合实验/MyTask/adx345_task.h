#ifndef _adx345_task_H
#define _adx345_task_H
#include "public.h"

#define ADX345_TASK_PRIO 15     //开始任务优先级
#define ADX345_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	ADX345_TASK_STK[ADX345_STK_SIZE];	  //创建任务堆栈空间

void adx345_task(void *pdata);



#endif
