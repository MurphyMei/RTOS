#ifndef _rs485_task_H
#define _rs485_task_H
#include "public.h"

#define COM2_TASK_PRIO 19     //��ʼ�������ȼ�
#define COM2_STK_SIZE 64     //���������ջ��С
static OS_STK 	COM2_TASK_STK[COM2_STK_SIZE];	  //���������ջ�ռ�

void rs485_task(void *pdata);



#endif
