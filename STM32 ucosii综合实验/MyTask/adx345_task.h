#ifndef _adx345_task_H
#define _adx345_task_H
#include "public.h"

#define ADX345_TASK_PRIO 15     //��ʼ�������ȼ�
#define ADX345_STK_SIZE 64     //���������ջ��С
static OS_STK 	ADX345_TASK_STK[ADX345_STK_SIZE];	  //���������ջ�ռ�

void adx345_task(void *pdata);



#endif
