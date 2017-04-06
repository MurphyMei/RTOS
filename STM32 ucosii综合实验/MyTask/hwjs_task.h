#ifndef _hwjs_task_H
#define _hwjs_task_H
#include "public.h"

#define HW_TASK_PRIO 9     //开始任务优先级
#define HW_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	HW_TASK_STK[HW_STK_SIZE];	  //创建任务堆栈空间

void hwjs_task(void *pdata);



#endif
