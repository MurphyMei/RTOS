#ifndef _key_task_H
#define _key_task_H
#include "public.h"

#define BUTTON_TASK_PRIO 5     //��ʼ�������ȼ�
#define BUTTON_STK_SIZE 64     //���������ջ��С
static OS_STK 	BUTTON_TASK_STK[BUTTON_STK_SIZE];	  //���������ջ�ռ�

void button_task(void *pdata);



#endif
