#ifndef _beep_task_H
#define _beep_task_H
#include "public.h"

#define BEEP_TASK_PRIO 2     //��ʼ�������ȼ�
#define BEEP_STK_SIZE 64     //���������ջ��С
static OS_STK 	BEEP_TASK_STK[BEEP_STK_SIZE];	  //���������ջ�ռ�

void beep_task(void *pdata);



#endif
