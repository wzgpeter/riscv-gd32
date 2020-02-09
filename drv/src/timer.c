////////////////////////////////////////////////////////////
// this file is used for s3c2440 timer configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-13
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include 	"devRegs.h"
#include	"interrupt.h"
#include	"timer.h"


void timer0_init(void)
{
	irq_register(xTaskIncrementTick, INT_OFFSET_TIMER0);

	//TIMER0 interrupt enable
	INTMSK &= ~(INT_TIMER0);

	//PCLK/(prescaler value + 1)/(divider value) = 50MHz/125/8 = 50000
	TCFG0 = 124;	//prescaler value + 1 = 125
	TCFG1 = 0x02;	//divider value = 8

	TCNTB0 = 24;	//the timer0 interrupt is 1ms interval

	TCON |= (1<<1);	//update manually
	TCON = 0x9;		//auto-load to clear update manually; start timer0
}

