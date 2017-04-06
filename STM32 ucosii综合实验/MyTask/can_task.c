#include "public.h"


uint8_t ShowData1[5] = {'0', 'x', '0', '0', 0};
uint8_t CAN_SendData1[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}; //�����λ������ŷ���ID�ͽ���ID
uint8_t *Mode1;
const uint8_t CAN_ModeNormal1[9] = {"����ģʽ"};
const uint8_t CAN_ModeLoopBack1[9] = {"����ģʽ"};

void GUI_DisplayData1(uint8_t num)
{
    uint8_t addr;
    
    for(addr=0; addr<10; addr++)
    {   
        if(addr < 8)
        {
            /* ������յ����ݣ���ʾ���� */
            /* ����ȡ����16λ����ת���ɿ�����ʾ��ASCII�� */
            ShowData1[2] = CAN_RX_BUFF[addr] >> 4;
            if(ShowData1[2] > 9)
            {
                ShowData1[2] += '7';  //������9ʱ����ABCDEF����ʾ
            }
            else
            {
                ShowData1[2] += '0';    
            }
            ShowData1[3] = CAN_RX_BUFF[addr] & 0x0F;
            if(ShowData1[3] > 9)
            {
                ShowData1[3] += '7';  //������9ʱ����ABCDEF����ʾ
            }
            else
            {
                ShowData1[3] += '0';    
            }
            /* ��ʾ���յ������� */
            GUI_Show12Char(208, (126 + addr * 21), ShowData1, RED, BLACK);
        }
        
        /* ��Ҫ���͵�16λ����ת���ɿ�����ʾ��ASCII�� */
        ShowData1[2] = CAN_SendData1[addr] >> 4;
        if(ShowData1[2] > 9)
        {
            ShowData1[2] += '7';    //������9ʱ����ABCDEF����ʾ
        }
        else
        {
            ShowData1[2] += '0';    
        }
        ShowData1[3] = CAN_SendData1[addr] & 0x0F;
        if(ShowData1[3] > 9)
        {
            ShowData1[3] += '7';    //������9ʱ����ABCDEF����ʾ
        }
        else
        {
            ShowData1[3] += '0';    
        }

        if(addr < 8)
        {
            /* ��ʾ�������ݣ�ѡ�����λ�� */
            if(num == addr)
            {
                GUI_Show12Char(88, (126 + addr * 21), ShowData1, GREEN, BLACK);
            }
            else
            {
                GUI_Show12Char(88, (126 + addr * 21), ShowData1, RED, BLACK);
            }
        }
        else //��ʾID����
        {
            if(addr == 8)
            {
                if(num == 8)
                {
                    GUI_Show12Char(52, 105, ShowData1, GREEN, BLACK); 
                }
                else
                {
                    GUI_Show12Char(52, 105, ShowData1, RED, BLACK);
                }
            }
            if(addr == 9)
            {
                if(num == 9)
                {
                    GUI_Show12Char(176, 105, ShowData1, GREEN, BLACK); 
                }
                else
                {
                    GUI_Show12Char(176, 105, ShowData1, RED, BLACK);
                }
            }
        }        
    }
    if(num > 9)
    {
        GUI_Show12Char(104, 84, Mode1, GREEN, BLACK);
    }
    else
    {
        GUI_Show12Char(104, 84, Mode1, RED, BLACK);        
    }
}

void can_task(void *pdata)    //����
{	
	uint8_t m, receiveId,canMode;
	m = 10;
    canMode = 1; //Ҫ����canMode������CAN_SendData[10],�Ա����ѭ��һ��ʼ�ͳ�ʼ��
	
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10, 10, "ע��Ĭ�Ͻ���ID0,������Ϊ450KHZ", BLUE, BLACK);

		    GUI_Show12Char(76, 63, "CANͨ��ʵ��", RED, BLACK);
		    /* ��ʾ����ģʽ */
		    GUI_Show12Char(0, 84, "CAN����ģʽ��", RED, BLACK);
		
		    /* ��ʾ���ͽ���ID */
		    GUI_Show12Char(0, 105, "����ID:", RED, BLACK);
		    GUI_Show12Char(120, 105, "����ID:", RED, BLACK);
		    
		    /* ��ʾ���ͺͽ������ݵ�8λ�� */    
		    GUI_Show12Char(0, 126, "���͵�һλ��", RED, BLACK);
		    GUI_Show12Char(120, 126, "���յ�һλ��", RED, BLACK);
		    GUI_Show12Char(0, 147, "���͵ڶ�λ��", RED, BLACK);
		    GUI_Show12Char(120, 147, "���յڶ�λ��", RED, BLACK);
		    GUI_Show12Char(0, 168, "���͵���λ��", RED, BLACK);
		    GUI_Show12Char(120, 168, "���յ���λ��", RED, BLACK);
		    GUI_Show12Char(0, 189, "���͵���λ��", RED, BLACK);
		    GUI_Show12Char(120, 189, "���յ���λ��", RED, BLACK);
		    GUI_Show12Char(0, 210, "���͵���λ��", RED, BLACK);
		    GUI_Show12Char(120, 210, "���յ���λ��", RED, BLACK);
		    GUI_Show12Char(0, 231, "���͵���λ��", RED, BLACK);
		    GUI_Show12Char(120, 231, "���յ���λ��", RED, BLACK);
		    GUI_Show12Char(0, 252, "���͵���λ��", RED, BLACK);
		    GUI_Show12Char(120, 252, "���յ���λ��", RED, BLACK);
		    GUI_Show12Char(0, 273, "���͵ڰ�λ��", RED, BLACK);
		    GUI_Show12Char(120, 273, "���յڰ�λ��", RED, BLACK);
		    GUI_Show12Char(0, 294, "�ϼ����������ּ�һ", BLUE, BLACK);
		    GUI_Show12Char(0, 315, "�¼����������ּ�һ", BLUE, BLACK);
		    GUI_Show12Char(0, 336, "������������������ƶ�һλ", BLUE, BLACK);
		    GUI_Show12Char(0, 357, "�Ҽ�����������", BLUE, BLACK);
			GUI_Show12Char(200,380,"����",YELLOW,BLACK);
					
		}
		
		/* �޸�ģʽ */
        if(canMode != CAN_SendData1[10] )
        {
            canMode = CAN_SendData1[10];
            if(CAN_SendData1[10])
            {
               CAN1_Config(CAN_Mode_Normal);
               Mode1 = (uint8_t *)CAN_ModeNormal1;    
            }
            else
            {
                CAN1_Config(CAN_Mode_LoopBack);
                Mode1 = (uint8_t *)CAN_ModeLoopBack1;
            }
            CAN1_Config16BitFilter(CAN_SendData1[9], 0x00);    
        }
        /* �������ID�ı䣬���������ý���ID */
        if(receiveId != CAN_SendData1[9])
        {
            receiveId = CAN_SendData1[9];
            if(receiveId != 0x00)
            {
                CAN1_Config16BitFilter(CAN_SendData1[9], 0x00);
            }                
        }
		/* ��ʾ���� */
        GUI_DisplayData1(m);

		if(k_up==1)	  //�жϰ���k_up�Ƿ���
		{
			Delay_ms(10); //��������
			if(k_up==1)	 //�ٴ��жϰ���k_up�Ƿ���
			{
				if(m == 10)
                {
                    CAN_SendData1[10] = ~CAN_SendData1[10];
                }
                else
                {
                    CAN_SendData1[m]++;   
                }
                GUI_Show12Char(175, 84, "�ȴ�����", RED, BLACK);					
			}
			while(k_up); //�ȴ������ɿ�
		}
		if(k_down==0)
		{
			Delay_ms(10);
			if(k_down==0)
			{
				if(m == 10)
                {
                    CAN_SendData1[10] = ~CAN_SendData1[10];
                }
                else
                {
                    CAN_SendData1[m]--;    
                }
                GUI_Show12Char(175, 84, "�ȴ�����", RED, BLACK);			
			}
			while(!k_down);
		}
		if(k_left==0)
		{
			Delay_ms(10);
			if(k_left==0)
			{
				if(m == 10)
                {
                    m = 0;
                }
                else
                {
                    m++;
                }			
			}
			while(!k_left);
		}
		if(k_right==0)
		{
			Delay_ms(10);
			if(k_right==0)
			{
				CAN1_SendMesg(CAN_SendData1[8], 8, CAN_SendData1);//��������
                GUI_Show12Char(175, 84, "���ͳɹ�", BLUE, BLACK);			
			}
			while(!k_right);
		}		
		Delay_ms(10);

		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(CAN_TASK_PRIO);					
		}
	}
	
}
