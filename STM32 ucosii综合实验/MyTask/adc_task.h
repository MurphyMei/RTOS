#ifndef _adc_task_H
#define _adc_task_H
#include "public.h"

#define ADC_TASK_PRIO 4     //开始任务优先级
#define ADC_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	ADC_TASK_STK[ADC_STK_SIZE];	  //创建任务堆栈空间

void adc_task(void *pdata);



#endif
