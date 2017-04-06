#include "public.h"

void start_task(void *pdata)    //开始任务
{
	OS_CPU_SR cpu_sr=0;
	pdata=pdata;
	OSStatInit();  //初始化统计任务
	OS_ENTER_CRITICAL();  //进入临界区，中断无法打断
	OSTaskCreate(touch_task,(void *)0,(OS_STK *)&TOUCH_TASK_STK[TOUCH_STK_SIZE-1]
	,TOUCH_TASK_PRIO);	
	OSTaskSuspend(START_TASK_PRIO);   //挂起起始任务
	OS_EXIT_CRITICAL();  //退出临界区，中断可以打断
}
