#ifndef _rtc_task_H
#define _rtc_task_H
#include "public.h"

#define RTC_TASK_PRIO 8     //��ʼ�������ȼ�
#define RTC_STK_SIZE 64     //���������ջ��С
static OS_STK 	RTC_TASK_STK[RTC_STK_SIZE];	  //���������ջ�ռ�

void rtc_time_task(void *pdata);



#endif
