#ifndef _adc_task_H
#define _adc_task_H
#include "public.h"

#define ADC_TASK_PRIO 4     //��ʼ�������ȼ�
#define ADC_STK_SIZE 64     //���������ջ��С
static OS_STK 	ADC_TASK_STK[ADC_STK_SIZE];	  //���������ջ�ռ�

void adc_task(void *pdata);



#endif
