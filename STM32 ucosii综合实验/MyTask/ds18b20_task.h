#ifndef _ds18b20_task_H
#define _ds18b20_task_H
#include "public.h"

#define TEMP_TASK_PRIO 6     //��ʼ�������ȼ�
#define TEMP_STK_SIZE 64     //���������ջ��С
static OS_STK 	TEMP_TASK_STK[TEMP_STK_SIZE];	  //���������ջ�ռ�

void ds18b20_task(void *pdata);



#endif
