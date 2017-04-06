#include "public.h"


uint8_t ShowData1[5] = {'0', 'x', '0', '0', 0};
uint8_t CAN_SendData1[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}; //最后两位用来存放发送ID和接收ID
uint8_t *Mode1;
const uint8_t CAN_ModeNormal1[9] = {"正常模式"};
const uint8_t CAN_ModeLoopBack1[9] = {"环回模式"};

void GUI_DisplayData1(uint8_t num)
{
    uint8_t addr;
    
    for(addr=0; addr<10; addr++)
    {   
        if(addr < 8)
        {
            /* 如果接收到数据，显示数据 */
            /* 将读取到的16位数据转换成可以显示的ASCII码 */
            ShowData1[2] = CAN_RX_BUFF[addr] >> 4;
            if(ShowData1[2] > 9)
            {
                ShowData1[2] += '7';  //当大于9时，用ABCDEF来表示
            }
            else
            {
                ShowData1[2] += '0';    
            }
            ShowData1[3] = CAN_RX_BUFF[addr] & 0x0F;
            if(ShowData1[3] > 9)
            {
                ShowData1[3] += '7';  //当大于9时，用ABCDEF来表示
            }
            else
            {
                ShowData1[3] += '0';    
            }
            /* 显示接收到的数据 */
            GUI_Show12Char(208, (126 + addr * 21), ShowData1, RED, BLACK);
        }
        
        /* 将要发送的16位数据转换成可以显示的ASCII码 */
        ShowData1[2] = CAN_SendData1[addr] >> 4;
        if(ShowData1[2] > 9)
        {
            ShowData1[2] += '7';    //当大于9时，用ABCDEF来表示
        }
        else
        {
            ShowData1[2] += '0';    
        }
        ShowData1[3] = CAN_SendData1[addr] & 0x0F;
        if(ShowData1[3] > 9)
        {
            ShowData1[3] += '7';    //当大于9时，用ABCDEF来表示
        }
        else
        {
            ShowData1[3] += '0';    
        }

        if(addr < 8)
        {
            /* 显示发送数据，选择高亮位置 */
            if(num == addr)
            {
                GUI_Show12Char(88, (126 + addr * 21), ShowData1, GREEN, BLACK);
            }
            else
            {
                GUI_Show12Char(88, (126 + addr * 21), ShowData1, RED, BLACK);
            }
        }
        else //显示ID部分
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

void can_task(void *pdata)    //任务
{	
	uint8_t m, receiveId,canMode;
	m = 10;
    canMode = 1; //要设置canMode不等于CAN_SendData[10],以便进入循环一开始就初始化
	
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10, 10, "注：默认接收ID0,波特率为450KHZ", BLUE, BLACK);

		    GUI_Show12Char(76, 63, "CAN通信实验", RED, BLACK);
		    /* 显示工作模式 */
		    GUI_Show12Char(0, 84, "CAN工作模式：", RED, BLACK);
		
		    /* 显示发送接收ID */
		    GUI_Show12Char(0, 105, "发送ID:", RED, BLACK);
		    GUI_Show12Char(120, 105, "接收ID:", RED, BLACK);
		    
		    /* 显示发送和接收数据的8位数 */    
		    GUI_Show12Char(0, 126, "发送第一位：", RED, BLACK);
		    GUI_Show12Char(120, 126, "接收第一位：", RED, BLACK);
		    GUI_Show12Char(0, 147, "发送第二位：", RED, BLACK);
		    GUI_Show12Char(120, 147, "接收第二位：", RED, BLACK);
		    GUI_Show12Char(0, 168, "发送第三位：", RED, BLACK);
		    GUI_Show12Char(120, 168, "接收第三位：", RED, BLACK);
		    GUI_Show12Char(0, 189, "发送第四位：", RED, BLACK);
		    GUI_Show12Char(120, 189, "接收第四位：", RED, BLACK);
		    GUI_Show12Char(0, 210, "发送第五位：", RED, BLACK);
		    GUI_Show12Char(120, 210, "接收第五位：", RED, BLACK);
		    GUI_Show12Char(0, 231, "发送第六位：", RED, BLACK);
		    GUI_Show12Char(120, 231, "接收第六位：", RED, BLACK);
		    GUI_Show12Char(0, 252, "发送第七位：", RED, BLACK);
		    GUI_Show12Char(120, 252, "接收第七位：", RED, BLACK);
		    GUI_Show12Char(0, 273, "发送第八位：", RED, BLACK);
		    GUI_Show12Char(120, 273, "接收第八位：", RED, BLACK);
		    GUI_Show12Char(0, 294, "上键：高亮部分加一", BLUE, BLACK);
		    GUI_Show12Char(0, 315, "下键：高亮部分减一", BLUE, BLACK);
		    GUI_Show12Char(0, 336, "左键：高亮部分向下移动一位", BLUE, BLACK);
		    GUI_Show12Char(0, 357, "右键：发送数据", BLUE, BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}
		
		/* 修改模式 */
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
        /* 如果接收ID改变，就重新设置接收ID */
        if(receiveId != CAN_SendData1[9])
        {
            receiveId = CAN_SendData1[9];
            if(receiveId != 0x00)
            {
                CAN1_Config16BitFilter(CAN_SendData1[9], 0x00);
            }                
        }
		/* 显示数据 */
        GUI_DisplayData1(m);

		if(k_up==1)	  //判断按键k_up是否按下
		{
			Delay_ms(10); //消抖处理
			if(k_up==1)	 //再次判断按键k_up是否按下
			{
				if(m == 10)
                {
                    CAN_SendData1[10] = ~CAN_SendData1[10];
                }
                else
                {
                    CAN_SendData1[m]++;   
                }
                GUI_Show12Char(175, 84, "等待发送", RED, BLACK);					
			}
			while(k_up); //等待按键松开
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
                GUI_Show12Char(175, 84, "等待发送", RED, BLACK);			
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
				CAN1_SendMesg(CAN_SendData1[8], 8, CAN_SendData1);//发送数据
                GUI_Show12Char(175, 84, "发送成功", BLUE, BLACK);			
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
