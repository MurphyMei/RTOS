#ifndef _ds18b20_task_H
#define _ds18b20_task_H
#include "public.h"

#define TEMP_TASK_PRIO 6     //开始任务优先级
#define TEMP_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	TEMP_TASK_STK[TEMP_STK_SIZE];	  //创建任务堆栈空间

void ds18b20_task(void *pdata);



#endif
