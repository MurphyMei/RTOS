#ifndef _start_task_H
#define _start_task_H
#include "public.h"

#define START_TASK_PRIO 60     //��ʼ�������ȼ�
#define START_STK_SIZE 64     //���������ջ��С
static OS_STK 	START_TASK_STK[START_STK_SIZE];	  //���������ջ�ռ�

void start_task(void *pdata);



#endif
