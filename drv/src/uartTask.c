//*************************************************************************************
//*************************************************************************************
//File Name: uart.c
//Notes:
//Author: wu, zhigang
//Date:   May-6-2017
//*************************************************************************************
//*************************************************************************************

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "uartTask.h"
#include "gpio.h"


TaskHandle_t xUartTaskHandle = NULL;



static void vUartTimrCallBack(TimerHandle_t xTimHandle)
{
	//TODO ...
}


void vUARTTask(void *pvParameters)
{
	TickType_t xLastExecutionTime;
	BaseType_t xResult;
	TickType_t xTicksToWait;
	const UBaseType_t AutoReload = pdTRUE;
	BaseType_t UARTTimerID;
	TimerHandle_t xTimHandle;

	xLastExecutionTime = xTaskGetTickCount();

	xTicksToWait = pdMS_TO_TICKS(100);
	UARTTimerID = 0x11;
	
	taskENTER_CRITICAL();
	xTimHandle = xTimerCreate("UARTTimer", xTicksToWait, AutoReload, &UARTTimerID, vUartTimrCallBack);
	taskEXIT_CRITICAL();

	xResult = xTimerStart(xTimHandle, xTicksToWait);

	while( 1 )
	{
		vTaskDelayUntil( &xLastExecutionTime, xTicksToWait );
		
		//led_switch(GPIOF, 6, state = (state == LED_ON ? LED_OFF : LED_ON));
	}
}


void vUARTTaskInit( void )
{
	xTaskCreate( vUARTTask, "UART", configMINIMAL_STACK_SIZE, NULL, mainUART_TASK_PRIORITY, &xUartTaskHandle );
}



