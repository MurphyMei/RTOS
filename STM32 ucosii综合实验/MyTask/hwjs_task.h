#ifndef _hwjs_task_H
#define _hwjs_task_H
#include "public.h"

#define HW_TASK_PRIO 9     //��ʼ�������ȼ�
#define HW_STK_SIZE 64     //���������ջ��С
static OS_STK 	HW_TASK_STK[HW_STK_SIZE];	  //���������ջ�ռ�

void hwjs_task(void *pdata);



#endif
