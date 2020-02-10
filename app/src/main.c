
/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "regs_opt.h"

#include "i2cTask.h"
#include "ledTask.h"
#include "uartTask.h"
#include "ledDrv.h"
#include "pll.h"


void main(void)
{
	pll_init();
	led_init(GPIOF);
	
	vI2CTaskInit();
	vLEDTaskInit();
	vUARTTaskInit();

	vTaskStartScheduler();
}

