#ifndef _sd_task_H
#define _sd_task_H
#include "public.h"

#define SD_TASK_PRIO 14     //��ʼ�������ȼ�
#define SD_STK_SIZE 64     //���������ջ��С
static OS_STK 	SD_TASK_STK[SD_STK_SIZE];	  //���������ջ�ռ�

void sd_task(void *pdata);



#endif
