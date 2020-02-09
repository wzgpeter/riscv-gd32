
/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

#include "i2cTask.h"
#include "ledTask.h"
#include "uartTask.h"

#include 	"ledDrv.h"

#define		MPLL_200MHz		( (0x5C<<12) | (0x01<<4) | (0x02) )
#define		CLKDIVN			(*(volatile unsigned int *)(0x4C000014))
#define		MPLLCON			(*(volatile unsigned int *)(0x4C000004))


void pllInit(void)
{
	CLKDIVN = 0x03;				//FCLK:HCLK:PCLK = 1:2:4
	MPLLCON = MPLL_200MHz;		//FCLK=200MHz, HCLK=100MHz, PCLK=50MHz
}

void main(void)
{
	pllInit();
	led_init(GPIOF);
	
	vI2CTaskInit();
	vLEDTaskInit();
	vUARTTaskInit();

	vTaskStartScheduler();
}

