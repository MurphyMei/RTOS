#ifndef _can_task_H
#define _can_task_H
#include "public.h"

#define CAN_TASK_PRIO 20     //��ʼ�������ȼ�
#define CAN_STK_SIZE 64     //���������ջ��С
static OS_STK 	CAN_TASK_STK[CAN_STK_SIZE];	  //���������ջ�ռ�

void can_task(void *pdata);
void GUI_DisplayData1(uint8_t num);	   


#endif
