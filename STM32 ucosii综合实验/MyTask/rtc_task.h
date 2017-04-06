#ifndef _rtc_task_H
#define _rtc_task_H
#include "public.h"

#define RTC_TASK_PRIO 8     //开始任务优先级
#define RTC_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	RTC_TASK_STK[RTC_STK_SIZE];	  //创建任务堆栈空间

void rtc_time_task(void *pdata);



#endif
