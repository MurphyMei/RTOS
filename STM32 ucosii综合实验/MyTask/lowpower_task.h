#ifndef _lowpower_task_H
#define _lowpower_task_H
#include "public.h"

#define LOW_TASK_PRIO 12     //��ʼ�������ȼ�
#define LOW_STK_SIZE 64     //���������ջ��С
static OS_STK 	LOW_TASK_STK[LOW_STK_SIZE];	  //���������ջ�ռ�

void low_task(void *pdata);



#endif
