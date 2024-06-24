#include "Setting.h"
#include "string.h"
#include "lcd.h"
#include "key.h"
#define line_max 9
#define line_min 1

Setvalue value[line_max];
//���ó�ʼ��
void Setting_Init(void)
{
	strcpy(value[0].Num_Temp, "0000000000");
	strcpy(value[1].Num_Temp, "0000000000");
	strcpy(value[2].Num_Temp, "0000000000");
	strcpy(value[3].Num_Temp, "0000000000");
	strcpy(value[0].name, "CH0:");
	strcpy(value[1].name, "CH1:");
	strcpy(value[2].name, "CH2:");
	strcpy(value[3].name, "CH3:");
	LCD_Clear();
	LCD_ShowString(1,45,0,"AD9959",16);
	LCD_ShowString(1,0,15,value[0].name,12);
	LCD_ShowString(1,95,15,"Hz",12);
	LCD_ShowString(1,30,15,value[0].Num_Temp,12);
	LCD_ShowString(1,0,27,value[1].name,12);
	LCD_ShowString(1,95,27,"Hz",12);
	LCD_ShowString(1,30,27,value[1].Num_Temp,12);
	LCD_ShowString(1,0,39,value[2].name,12);
	LCD_ShowString(1,95,39,"Hz",12);
	LCD_ShowString(1,30,39,value[2].Num_Temp,12);
	LCD_ShowString(1,0,51,value[3].name,12);
	LCD_ShowString(1,95,51,"Hz",12);
	LCD_ShowString(1,30,51,value[3].Num_Temp,12);
	
	LCD_Refresh_Gram();
	
	strcpy(value[line_max - 1].name, "   Back  ");
}
void Setting_Mode(bool *sta)
{
	
	if(*sta)
	{
		u8 Set_Key, line = 1, OK = 0, SELECT_L[4], SELECT_S[10];
		u8 value_num = 0;//ѡ�п��׼ֵ
		strcpy(SELECT_L, "1111");
		strcpy(SELECT_S, "1111111111");
		//ѡ�п�λ�ã��жϱ�ѡ��ѡ�ͬʱ����ʾ4�����ݣ���lineֵ������ǰ��ʾ�������б�ѡ����
		switch(line)
		{
			case 1:
			SELECT_L[0] = 0;
			break;
			case 2:
			SELECT_L[1] = 0;
			break;
			case 3:
			SELECT_L[2] = 0;
		  break;
			case 4:
			SELECT_L[3] = 0;
		  break;
		}
		//��ʼ����ʾ4������
		LCD_ShowString(SELECT_L[0],0,15,value[value_num].name,12);
		LCD_ShowString(SELECT_L[1],0,27,value[value_num + 1].name,12);
		LCD_ShowString(SELECT_L[2],0,39,value[value_num + 2].name,12);
		LCD_ShowString(SELECT_L[3],0,51,value[value_num + 3].name,12);
		LCD_Refresh_Gram();		//������ʾ��LCD
		//ѭ������
		while(1)
		{
			KeyRead();      //��ȡ����������������
			if(Keycode)                 //���а�������ʱ
			{
				if(Keycode == K_2_S)
				{
					*sta = 0;
					strcpy(SELECT_L, "1111");
					LCD_ShowString(SELECT_L[0],0,15,value[value_num].name,12);
					LCD_ShowString(SELECT_L[1],0,27,value[value_num + 1].name,12);
					LCD_ShowString(SELECT_L[2],0,39,value[value_num + 2].name,12);
					LCD_ShowString(SELECT_L[3],0,51,value[value_num + 3].name,12);
					LCD_Refresh_Gram();
					break;
				}
				if(Keycode == K_1_S)
				{
					line++;
					if(line > 4)
						line = 1;
				}
				if(Keycode == K_3_S)
				{
					line--;
					if(line < 1)
						line = 4;
				}
				strcpy(SELECT_L, "1111");
				switch(line)
				{
					case 1:
					SELECT_L[0] = 0;
					break;
					case 2:
					SELECT_L[1] = 0;
					break;
					case 3:
					SELECT_L[2] = 0;
					break;
					case 4:
					SELECT_L[3] = 0;
					break;
				}
				LCD_ShowString(SELECT_L[0],0,15,value[value_num].name,12);
					LCD_ShowString(SELECT_L[1],0,27,value[value_num + 1].name,12);
					LCD_ShowString(SELECT_L[2],0,39,value[value_num + 2].name,12);
					LCD_ShowString(SELECT_L[3],0,51,value[value_num + 3].name,12);
					LCD_Refresh_Gram();
			}
		}
				
   }
}
