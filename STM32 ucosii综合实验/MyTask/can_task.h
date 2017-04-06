#ifndef _can_task_H
#define _can_task_H
#include "public.h"

#define CAN_TASK_PRIO 20     //开始任务优先级
#define CAN_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	CAN_TASK_STK[CAN_STK_SIZE];	  //创建任务堆栈空间

void can_task(void *pdata);
void GUI_DisplayData1(uint8_t num);	   


#endif
