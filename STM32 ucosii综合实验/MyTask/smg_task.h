#ifndef _smg_task_H
#define _smg_task_H
#include "public.h"

#define SMG_TASK_PRIO 3     //��ʼ�������ȼ�
#define SMG_STK_SIZE 64     //���������ջ��С
static OS_STK 	SMG_TASK_STK[SMG_STK_SIZE];	  //���������ջ�ռ�

void smg_task(void *pdata);



#endif
