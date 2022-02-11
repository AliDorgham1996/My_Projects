#ifndef GHS_H_
#define GHS_H_

/* Includes start */
/* RTOS Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
/* Drivers */
#include "Internal_EEPROM.h"
#include "BasicIO.h"
#include "LCD.h"
#include "uart.h"
#include "ADC.h"

/* Includes end */
#define EEPROM_THRESOLD_ADDRESS   0x01
#define ALARM_LED 		LED1
//#define TEMP_PIN 		PA0

/* Display Macros */
#define DISP_MAIN_L0		(u8*)"C:    T:    AS: "
#define DISP_MAIN_L1		(u8*)"  TC:C    AT:T  "
/* Row:1-2, col: 1-16 */
#define DISP_CTEMP_ROW		1
#define DISP_CTEMP_COL		3
#define DISP_TTEMP_ROW		1
#define DISP_TTEMP_COL		9
#define DISP_AS_ROW			1
#define DISP_AS_COL			16

#define DISP_CONFIG_L0		(u8*)"      T:        "
#define DISP_CONFIG_L1		(u8*)"  OK:O    CN:C  "

#define DISP_ALARM_L0		(u8*)" !!!ALARMING!!! "
#define DISP_ALARM_L1		(u8*)"      AS:S      "
// main -> alarm -> main variable overwritten
/* OS Objects */
#define E_MAIN_SCREEN 				(1<<0)
#define E_ALARM_SCREEN				(1<<1)
#define E_CONFIG_SCREEN				(1<<2)
#define E_CTEMP_UPDATE				(1<<3)
#define E_TTEMP_UPDATE				(1<<4)
#define E_TTEMP_DIGIT_DISP			(1<<5)
#define E_ALARM_STATUS_UPDATE		(1<<6)
#define E_ALARM						(1<<7)

#define E_DISP_EVENTS 				(0x7F)


/* States */
typedef enum{
	SS_MAIN,
	SS_CONFIG,
	SS_ALARM
}SystemState_t;

typedef struct{
	SystemState_t SysState;
	u8 AlarmStatus; /* 'D' or 'E' */
	u8 CTemp;
	u8 TTemp;
}TAS_t;

/*Functions or tasks prototype*/
void T_Alarm(void* ptr);
void T_Temp(void* ptr);
void T_UserTerm(void* ptr);
void T_EventTerm(void *ptr);
void T_Display(void* ptr);
void T_SysCheck(void* ptr);

void System_Init(void);

#endif /* GHS_H_ */
