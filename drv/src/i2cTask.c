//*************************************************************************************
//*************************************************************************************
//File Name: i2cTask.c
//Notes:
//Author: wu, zhigang
//Date:   May-6-2017
//*************************************************************************************
//*************************************************************************************

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include "i2cTask.h"
#include "ledDrv.h"


TaskHandle_t xI2cTaskHandle = NULL;


static void vI2cTimrCallBack(TimerHandle_t xTimHandle)
{
	//TODO ...
}


void vI2CTask(void *pvParameters)
{
	TickType_t xLastExecutionTime;
	BaseType_t xResult;
	TickType_t xTicksToWait;
	const UBaseType_t AutoReload = pdTRUE;
	BaseType_t I2CTimerID;
	enum STATE state = LED_OFF;
	TimerHandle_t xTimHandle;

	xLastExecutionTime = xTaskGetTickCount();

	xTicksToWait = pdMS_TO_TICKS(200);
	I2CTimerID = 0x22;

	taskENTER_CRITICAL();
	xTimHandle = xTimerCreate("I2CTimer", xTicksToWait, AutoReload, &I2CTimerID, vI2cTimrCallBack);
	taskEXIT_CRITICAL();

	xResult = xTimerStart(xTimHandle, xTicksToWait);

	while( 1 )
	{
		vTaskDelayUntil( &xLastExecutionTime, xTicksToWait );
	
		led_switch(GPIOF, 5, state = (state == LED_ON ? LED_OFF : LED_ON));
	}
}



void vI2CTaskInit(void)
{
	xTaskCreate( vI2CTask, "I2C", configMINIMAL_STACK_SIZE, NULL, mainI2C_TASK_PRIORITY, &xI2cTaskHandle );
}

