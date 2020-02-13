
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

#include "interrupt.h"
#include "timer.h"

void main(void)
{
	volatile uint32_t curr_cnt= 0;

	rcu_init();
//	led_init(GPIOF);

	glob_interrupt_enable();
	eclic_set_nlbits(ECLIC_GROUP_LEVEL3_PRIO1);
	eclic_irq_enable(TIMER1_IRQn, 1, 0);
	timer_config(TIMER1, 10);

	while(1)
	{
		curr_cnt = get_timer_counter(TIMER1);
		if (curr_cnt == 0)
			break;
	};

	vI2CTaskInit();
	vLEDTaskInit();
	vUARTTaskInit();

	vTaskStartScheduler();
}

