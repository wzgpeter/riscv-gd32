//*************************************************************************************
//*************************************************************************************
//File Name: ledTask.c
//Notes:
//Author: wu, zhigang
//Date:   May-6-2017
//*************************************************************************************
//*************************************************************************************

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include "ledTask.h"
#include "gpio.h"

TaskHandle_t xLedTaskHandle = NULL;


static void vLedTimrCallBack(TimerHandle_t xTimHandle)
{
	//TODO ...
}


void vLEDTask(void *pvParameters)
{
	TickType_t xLastExecutionTime;
	BaseType_t xResult;
	TickType_t xTicksToWait;
	const UBaseType_t AutoReload = pdTRUE;
	BaseType_t LEDTimerID;
	TimerHandle_t xTimHandle;

	xLastExecutionTime = xTaskGetTickCount();


	xTicksToWait = pdMS_TO_TICKS(500);
	LEDTimerID = 0x33;
	
	taskENTER_CRITICAL();
	xTimHandle = xTimerCreate("LEDTimer", xTicksToWait, AutoReload, &LEDTimerID, vLedTimrCallBack);
	taskEXIT_CRITICAL();

	xResult = xTimerStart(xTimHandle, xTicksToWait);

	while( 1 )
	{
		vTaskDelayUntil( &xLastExecutionTime, xTicksToWait );

		//led_switch(GPIOF, 4, state = (state == LED_ON ? LED_OFF : LED_ON));
	}
}



void vLEDTaskInit(void)
{
	xTaskCreate( vLEDTask, "LED", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, &xLedTaskHandle );
}



