#ifndef _touch_task_H
#define _touch_task_H
#include "public.h"

#define TOUCH_TASK_PRIO 1     //��ʼ�������ȼ�
#define TOUCH_STK_SIZE 64     //���������ջ��С
static OS_STK 	TOUCH_TASK_STK[TOUCH_STK_SIZE];	  //���������ջ�ռ�

void touch_task(void *pdata);



#endif
