////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-14
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include 	"devRegs.h"
#include	"interrupt.h"
//#include 	"ledDrv.h"

#define		IRQ_VEC_NUM		(32)

BaseType_t (*irq_vec_table[IRQ_VEC_NUM])( void ) 
__attribute__((__section__(".irq_vector"))) = {
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL 
};


uint8_t	irq_register(BaseType_t (*func)(void), uint8_t int_offset)
{
	if (func == NULL)
		return pdFALSE;

	if (int_offset >= IRQ_VEC_NUM)
		return pdFALSE;

	irq_vec_table[int_offset] = func;

	return pdTRUE;
}


void do_irq(void)
{
	uint32_t IrqPnd, OffSet;
	BaseType_t (*irq_func)(void) = NULL;
	BaseType_t ret = pdFALSE;
//	static enum STATE state = LED_OFF;

	IrqPnd = SRCPND;
	OffSet = INTOFFSET;

	if (IrqPnd == 0)	//no interrupt is pending
		return;

	if (OffSet >= IRQ_VEC_NUM)
		return;

	irq_func = irq_vec_table[OffSet];

	ret = (*irq_func)();

	switch(OffSet)
	{
	case INT_OFFSET_TIMER0:
//		led_switch(GPIOF, 5, state = (state == LED_ON ? LED_OFF : LED_ON));
		break;
	default:
		break;
	}

	//clear corresponding interrupt pending bit
	SRCPND = IrqPnd;
	INTPND = IrqPnd;

	return;
}

