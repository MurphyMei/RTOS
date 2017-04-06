#ifndef _sd_task_H
#define _sd_task_H
#include "public.h"

#define SD_TASK_PRIO 14     //开始任务优先级
#define SD_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	SD_TASK_STK[SD_STK_SIZE];	  //创建任务堆栈空间

void sd_task(void *pdata);



#endif
