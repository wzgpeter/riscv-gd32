
/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "regs_opt.h"

#include "i2cTask.h"
#include "ledTask.h"
#include "uartTask.h"
#include "gpio.h"
#include "rcu.h"

#include "interrupt.h"
#include "timer.h"


void main(void)
{
	volatile uint32_t curr_cnt= 0;

	eclic_set_nlbits(ECLIC_INTCTLBITS);
	eclic_irq_enable(TIMER1_IRQn, 1, 0);

	vI2CTaskInit();
//	vLEDTaskInit();
	vUARTTaskInit();

	vTaskStartScheduler();
}

