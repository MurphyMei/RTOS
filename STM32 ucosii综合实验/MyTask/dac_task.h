#ifndef _dac_task_H
#define _dac_task_H
#include "public.h"

#define DA_TASK_PRIO 17     //��ʼ�������ȼ�
#define DA_STK_SIZE 64     //���������ջ��С
static OS_STK 	DA_TASK_STK[DA_STK_SIZE];	  //���������ջ�ռ�

void da_task(void *pdata);



#endif
