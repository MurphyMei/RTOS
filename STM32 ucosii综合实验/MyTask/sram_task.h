#ifndef _sram_task_H
#define _sram_task_H
#include "public.h"

#define SRAM_TASK_PRIO 16     //��ʼ�������ȼ�
#define SRAM_STK_SIZE 64     //���������ջ��С
static OS_STK 	SRAM_TASK_STK[SRAM_STK_SIZE];	  //���������ջ�ռ�

void sram_task(void *pdata);



#endif
