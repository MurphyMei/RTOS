#include "public.h"

void start_task(void *pdata)    //��ʼ����
{
	OS_CPU_SR cpu_sr=0;
	pdata=pdata;
	OSStatInit();  //��ʼ��ͳ������
	OS_ENTER_CRITICAL();  //�����ٽ������ж��޷����
	OSTaskCreate(touch_task,(void *)0,(OS_STK *)&TOUCH_TASK_STK[TOUCH_STK_SIZE-1]
	,TOUCH_TASK_PRIO);	
	OSTaskSuspend(START_TASK_PRIO);   //������ʼ����
	OS_EXIT_CRITICAL();  //�˳��ٽ������жϿ��Դ��
}
