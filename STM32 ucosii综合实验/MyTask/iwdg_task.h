#ifndef _iwdg_task_H
#define _iwdg_task_H
#include "public.h"

#define IWDG_TASK_PRIO 10     //��ʼ�������ȼ�
#define IWDG_STK_SIZE 64     //���������ջ��С
static OS_STK 	IWDG_TASK_STK[IWDG_STK_SIZE];	  //���������ջ�ռ�

void iwdg_task(void *pdata);



#endif
