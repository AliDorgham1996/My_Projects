#include "TAS.h"

TAS_t	TAS = {SS_MAIN,'E',0,100};

/*OS Services*/
extern EventGroupHandle_t	egEvents;
extern xSemaphoreHandle 	bsCheck;
extern xQueueHandle			TRM_Queue;

/* Variables */
u8 digitCounter = 0;
u8 digitValue = 0;

void TAS_DispScreen(SystemState_t state){
	switch (state)
	{
	case SS_MAIN:
		LCD_DispStrXY(1,1,DISP_MAIN_L0);
		LCD_DispStrXY(2,1,DISP_MAIN_L1);
		break;
	case SS_CONFIG:
		LCD_DispStrXY(1,1,DISP_CONFIG_L0);
		LCD_DispStrXY(2,1,DISP_CONFIG_L1);
		break;
	case SS_ALARM:
		LCD_DispStrXY(1,1,DISP_ALARM_L0);
		LCD_DispStrXY(2,1,DISP_ALARM_L1);
		break;
	}
}

void T_Alarm(void* ptr)
{
	Uart_SendStr("T_Alarm Started ...\r\n");
	EventBits_t	ebBits = NULL;
	while(1){
		ebBits = xEventGroupWaitBits(egEvents,(E_ALARM),0,0,portMAX_DELAY);
		if(ebBits&(E_ALARM)){
			Buz_On();
			vTaskDelay(500);
			Buz_Off();
			vTaskDelay(500);
		}
	}
}
void T_Temp(void* ptr)
{
	Uart_SendStr("T_Temp Started ...\r\n");
	u16 temp = 0;
	while(1){
		temp = ADC_Read(ADC_CH0);
		temp = (temp/1023.0)*150;
		if(temp != TAS.CTemp ){
			TAS.CTemp = temp;
			if(TAS.SysState == SS_MAIN){
				xEventGroupSetBits(egEvents,E_CTEMP_UPDATE);
			}
			xSemaphoreGive(bsCheck);
		}
		vTaskDelay(100);
	}
}
void T_SysCheck(void* ptr)
{
	Uart_SendStr("T_SysCheck Started ...\r\n");
	while(1){
		if(xSemaphoreTake(bsCheck,portMAX_DELAY)){
			if(TAS.AlarmStatus == 'E' && TAS.CTemp >= TAS.TTemp){
				TAS.SysState = SS_ALARM;
				xEventGroupSetBits(egEvents,(E_ALARM_SCREEN)); // to T_Display
				xEventGroupSetBits(egEvents,(E_ALARM)); // to T_Alarm
			}
			else if(TAS.SysState == SS_ALARM && (TAS.AlarmStatus == 'D' || TAS.CTemp < TAS.TTemp)){
				xEventGroupClearBits(egEvents,(E_ALARM)); // stop Alarming in T_Alarm
				TAS.SysState = SS_MAIN;
				xEventGroupSetBits(egEvents,(E_MAIN_SCREEN|E_CTEMP_UPDATE|E_TTEMP_UPDATE|E_ALARM_STATUS_UPDATE));
			}
		}
	}
}

void T_Display(void* ptr)
{
	EventBits_t			ebBits = NULL;
	Uart_SendStr("T_Display Started ...\r\n");
	while(1)
	{
		ebBits = xEventGroupWaitBits(egEvents,(E_DISP_EVENTS),1,0,portMAX_DELAY);
		if(ebBits&E_MAIN_SCREEN){
			TAS_DispScreen(SS_MAIN);
		}
		if(ebBits&E_ALARM_SCREEN){
			TAS_DispScreen(SS_ALARM);
		}
		if(ebBits&E_CONFIG_SCREEN){
			TAS_DispScreen(SS_CONFIG);
		}
		if(ebBits&E_CTEMP_UPDATE){
			if(TAS.SysState == SS_MAIN)
			LCD_DispIntXY(DISP_CTEMP_ROW,DISP_CTEMP_COL,TAS.CTemp);
		}
		if(ebBits&E_TTEMP_UPDATE){
			if(TAS.SysState == SS_MAIN)
			LCD_DispIntXY(DISP_TTEMP_ROW,DISP_TTEMP_COL,TAS.TTemp);
		}
		if(ebBits&E_TTEMP_DIGIT_DISP){
			if(TAS.SysState == SS_CONFIG)
			LCD_DispCharXY(DISP_TTEMP_ROW, (DISP_TTEMP_COL + digitCounter), digitValue);
		}
		if(ebBits&E_ALARM_STATUS_UPDATE){
			if(TAS.SysState == SS_MAIN)
			LCD_DispCharXY(DISP_AS_ROW,DISP_AS_COL,TAS.AlarmStatus);
		}
	}
}

void T_EventTerm(void *ptr)
{
	u8 ch;
	u8 recTTemp;
	Int_EEPROM_Read(EEPROM_THRESOLD_ADDRESS , &recTTemp);
	Uart_SendStr("T_EventTerm Started ...\r\n");
	while(1)
	{
		if(xQueueReceive(TRM_Queue, &ch, portMAX_DELAY))
		{
			switch (TAS.SysState)
			{
				case SS_MAIN:
				{
					if (ch == 'C')
					{
						TAS.SysState = SS_CONFIG;
						digitCounter = 0;
						recTTemp = 0;
						xEventGroupSetBits(egEvents,E_CONFIG_SCREEN);
					}
					else if (ch == 'T')
					{
						if(TAS.AlarmStatus == 'E')
						{ // toggle alarm status
						TAS.AlarmStatus = 'D';
						//
						}
						else
						{
							TAS.AlarmStatus = 'E';
							// recheck is a must
						}
						xEventGroupSetBits(egEvents,E_ALARM_STATUS_UPDATE);
						xSemaphoreGive(bsCheck);
					}					
				}
				break;
				case SS_ALARM:
				{
					if (ch == 'S')
					{
						TAS.AlarmStatus = 'D';
						xSemaphoreGive(bsCheck);
					}
				}	
				break;		
				case SS_CONFIG:
				{
					if(ch == 'O')
					{
						TAS.TTemp = recTTemp;
						EEPROM_Update(EEPROM_THRESOLD_ADDRESS,TAS.TTemp);
						TAS.SysState = SS_MAIN;
						xEventGroupSetBits(egEvents,(E_MAIN_SCREEN|E_CTEMP_UPDATE|E_TTEMP_UPDATE|E_ALARM_STATUS_UPDATE));
						xSemaphoreGive(bsCheck);
					}
					else if(ch == 'C')
					{
						TAS.SysState = SS_MAIN;
						xEventGroupSetBits(egEvents,(E_MAIN_SCREEN|E_CTEMP_UPDATE|E_TTEMP_UPDATE|E_ALARM_STATUS_UPDATE));
					}
					else if( ch >= '0' && ch <= '9' && digitCounter < 3)
					{
						digitCounter++;
						recTTemp = recTTemp*10 + (ch - '0');
						digitValue = ch;
						xEventGroupSetBits(egEvents,E_TTEMP_DIGIT_DISP);
					}
				}
				break;			
			}			
		}
	}
}

void T_UserTerm(void* ptr)
{
	u8 ch = 0;
	Uart_SendStr("T_UserTerm Started ...\r\n");
	while(1){
		if(Uart_ReceiveByte_Unblock(&ch))
		{
			xQueueSend(TRM_Queue, &ch, portMAX_DELAY);
		}
		vTaskDelay(100);
	}
}
