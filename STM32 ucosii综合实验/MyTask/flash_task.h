#ifndef _flash_task_H
#define _flash_task_H
#include "public.h"

#define FLASH_TASK_PRIO 13     //��ʼ�������ȼ�
#define FLASH_STK_SIZE 64     //���������ջ��С
static OS_STK 	FLASH_TASK_STK[FLASH_STK_SIZE];	  //���������ջ�ռ�

void flash_task(void *pdata);



#endif
