#ifndef _eeprom_task_H
#define _eeprom_task_H
#include "public.h"

#define EEPROM_TASK_PRIO 7     //��ʼ�������ȼ�
#define EEPROM_STK_SIZE 64     //���������ջ��С
static OS_STK 	EEPROM_TASK_STK[EEPROM_STK_SIZE];	  //���������ջ�ռ�

void eeprom_task(void *pdata);



#endif
