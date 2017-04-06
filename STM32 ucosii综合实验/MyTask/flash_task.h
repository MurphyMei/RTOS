#ifndef _flash_task_H
#define _flash_task_H
#include "public.h"

#define FLASH_TASK_PRIO 13     //开始任务优先级
#define FLASH_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	FLASH_TASK_STK[FLASH_STK_SIZE];	  //创建任务堆栈空间

void flash_task(void *pdata);



#endif
