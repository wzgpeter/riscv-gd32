
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
#include "gd32vf103_gpio.h"


void main(void)
{
	volatile uint32_t curr_cnt= 0;

/*
	gpio_deinit(GPIOC);
	gpio_afio_deinit();

	perip_clk_enable(RCU_GPIOCEN);
	perip_clk_enable(RCU_GPIODEN);
	gpio_init(GPIOC, GPIO_MODE_AF_OD, GPIO_OSPEED_50MHZ, GPIO_PIN_15);
*/

	glob_interrupt_enable();
	eclic_set_nlbits(ECLIC_GROUP_LEVEL3_PRIO1);
	eclic_irq_enable(TIMER1_IRQn, 1, 0);
	timer_config(TIMER1, 10);

	clkout_select(CLKSRC_CK_PLL_DIV2);

	while(1)
	{
		curr_cnt = get_timer_counter(TIMER1);
		if (curr_cnt == 0)
			continue;
	};

	vI2CTaskInit();
	vLEDTaskInit();
	vUARTTaskInit();

	vTaskStartScheduler();
}

