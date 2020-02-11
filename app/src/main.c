
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
#include "rcu.h"


void main(void)
{
	rcu_init();
	led_init(GPIOF);
	
	vI2CTaskInit();
	vLEDTaskInit();
	vUARTTaskInit();

	vTaskStartScheduler();
}

