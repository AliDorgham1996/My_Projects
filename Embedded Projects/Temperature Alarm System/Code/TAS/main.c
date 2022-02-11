#include "TAS.h"

TaskHandle_t th_T_Temp;
TaskHandle_t th_T_Display;
TaskHandle_t th_T_UserTerm;
TaskHandle_t th_T_EventTerm;
TaskHandle_t th_T_Alarm;
TaskHandle_t th_T_SysCheck;

EventGroupHandle_t	egEvents 	= NULL;
xSemaphoreHandle 	bsCheck 	= NULL;
xQueueHandle		TRM_Queue   = NULL;

extern TAS_t	TAS ;

void main(void){
	/* Init system */
	system_init();
	/*Create OS Objects*/
	bsCheck = xSemaphoreCreateBinary();
	TRM_Queue = xQueueCreate(10,1);
	egEvents = xEventGroupCreate();
	/*Create tasks*/
	xTaskCreate(T_Alarm,	"T_Alarm",		100,NULL,6,&th_T_Alarm);
	xTaskCreate(T_UserTerm,	"T_UserTerm",	100,NULL,5,&th_T_UserTerm);
	xTaskCreate(T_EventTerm,"T_EventTerm",	100,NULL,4,&th_T_EventTerm);
	xTaskCreate(T_SysCheck,	"T_SysCheck",	100,NULL,3,&th_T_SysCheck);
	xTaskCreate(T_Temp,		"T_Temp",		100,NULL,2,&th_T_Temp);
	xTaskCreate(T_Display,	"T_Display",	100,NULL,1,&th_T_Display);
	/* os services init */
	xEventGroupSetBits(egEvents,(E_MAIN_SCREEN|E_CTEMP_UPDATE|E_TTEMP_UPDATE|E_ALARM_STATUS_UPDATE));
	/* start os */
	vTaskStartScheduler();
}
void system_init(void){
	Buz_Init();
	ADC_Init();
	LCD_Init();
	Uart_Init(9600);
	Uart_SendStr("System Started ...\r\n");
	Int_EEPROM_Read(EEPROM_THRESOLD_ADDRESS,&TAS.TTemp);
}
