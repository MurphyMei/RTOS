#ifndef _eeprom_task_H
#define _eeprom_task_H
#include "public.h"

#define EEPROM_TASK_PRIO 7     //开始任务优先级
#define EEPROM_STK_SIZE 64     //设置任务堆栈大小
static OS_STK 	EEPROM_TASK_STK[EEPROM_STK_SIZE];	  //创建任务堆栈空间

void eeprom_task(void *pdata);



#endif
