#ifndef _usart_task_H
#define _usart_task_H
#include "public.h"

#define COM1_TASK_PRIO 18     //��ʼ�������ȼ�
#define COM1_STK_SIZE 64     //���������ջ��С
static OS_STK 	COM1_TASK_STK[COM1_STK_SIZE];	  //���������ջ�ռ�

void com_task(void *pdata);



#endif
