#include "public.h"

void hwjs_task(void *pdata)    //����
{	
	u8 dat[4],irdisp[9];
	u8 num[16]="0123456789ABCDEF";
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"����ң��ʵ��",YELLOW,BLACK);
			GUI_Show12Char(10,30,"����ң�ؼ��룺",YELLOW,BLACK);
			GUI_Show12Char(200,380,"����",YELLOW,BLACK);	
		}
		if(hw_jsbz==1)	//���������յ�
		{
			hw_jsbz=0;	   //����
			dat[0]=hw_jsm>>24;
			dat[1]=(hw_jsm>>16)&0xff;
			dat[2]=(hw_jsm>>8)&0xff;
			dat[3]=hw_jsm&0xff;
			hw_jsm=0;					//����������
			irdisp[0]=num[dat[0]/16];//��ʾ��λ
			irdisp[1]=num[dat[0]%16];//��ʾ��λ  
			irdisp[2]=num[dat[1]/16];
			irdisp[3]=num[dat[1]%16];	 //ͬһ��ң������2���ֽڵ������������ǲ���ı�ģ��ı��ֻ�������뼰����
			irdisp[4]=num[dat[2]/16];
			irdisp[5]=num[dat[2]%16];
			irdisp[6]=num[dat[3]/16];
			irdisp[7]=num[dat[3]%16];
			irdisp[8]='\0';
			GUI_Show12Char(113,30,irdisp,YELLOW,BLACK);
		}

		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(HW_TASK_PRIO);					
		}
	}
	
}
