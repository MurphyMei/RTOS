#ifndef _sram_task_H
#define _sram_task_H
#include "public.h"

#define SRAM_TASK_PRIO 16     //开始任务优先级
#define SRAM_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	SRAM_TASK_STK[SRAM_STK_SIZE];	  //创建任务堆栈空间

void sram_task(void *pdata);



#endif
