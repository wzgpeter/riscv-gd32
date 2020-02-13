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


uint8_t	irq_register(BaseType_t (*func)(void), uint8_t int_offset)
{


	return pdTRUE;
}


void do_irq(void)
{

}


void glob_interrupt_disable(void)
{
	asm volatile(" 	li		t0, 0x00000008 \n\t "
				 "	csrc 	mstatus, t0 "
		);
}

void glob_interrupt_enable(void)
{
	asm volatile(" 	li		t0, 0x00000008 \n\t "
				 "	csrs 	mstatus, t0 "
		);
}


#define _AC(X,Y)        (X##Y)
#define ECLICINTCTLBITS				4
#define ECLIC_CFG_OFFSET			0x0
#define ECLIC_INT_IE_OFFSET			_AC(0x1001,UL)
#define ECLIC_INT_CTRL_OFFSET		_AC(0x1003,UL)
#define ECLIC_ADDR_BASE				0xd2000000
#define ECLIC_CFG_NLBITS_MASK		_AC(0x1E,UL)
#define ECLIC_CFG_NLBITS_LSB		(1u)


void eclic_enable_interrupt (uint32_t source) 
{
	*(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_INT_IE_OFFSET+source*4) = 1;
}
void eclic_set_intctrl (uint32_t source, uint8_t intctrl)
{
	*(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_INT_CTRL_OFFSET+source*4) = intctrl;
}
uint8_t eclic_get_intctrl  (uint32_t source)
{
	return *(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_INT_CTRL_OFFSET+source*4);
}
void eclic_set_cliccfg (uint8_t cliccfg){
  *(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_CFG_OFFSET) = cliccfg;
}
uint8_t eclic_get_cliccfg ()
{
	return *(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_CFG_OFFSET);
}
void eclic_set_nlbits(uint8_t nlbits) 
{
  //shift nlbits to correct position
  uint8_t nlbits_shifted = nlbits << ECLIC_CFG_NLBITS_LSB;

  //read the current cliccfg 
  uint8_t old_cliccfg = eclic_get_cliccfg();
  uint8_t new_cliccfg = (old_cliccfg & (~ECLIC_CFG_NLBITS_MASK)) | (ECLIC_CFG_NLBITS_MASK & nlbits_shifted); 

  eclic_set_cliccfg(new_cliccfg);
}
uint8_t eclic_get_nlbits(void) 
{
	//extract nlbits
	uint8_t nlbits = eclic_get_cliccfg();
	nlbits = (nlbits & ECLIC_CFG_NLBITS_MASK) >> ECLIC_CFG_NLBITS_LSB;
	return nlbits;
}


void eclic_set_irq_lvl_abs(uint32_t source, uint8_t lvl_abs) 
{
	//extract nlbits
	uint8_t nlbits = eclic_get_nlbits();
	if (nlbits > ECLICINTCTLBITS) 
	{
		nlbits = ECLICINTCTLBITS;
	}

	//shift lvl_abs into correct bit position
	uint8_t lvl = lvl_abs << (8-nlbits);

	//write to clicintctrl
	uint8_t current_intctrl = eclic_get_intctrl(source);
	//shift intctrl left to mask off unused bits
	current_intctrl = current_intctrl << nlbits;
	//shift intctrl into correct bit position
	current_intctrl = current_intctrl >> nlbits;

	eclic_set_intctrl(source, (current_intctrl | lvl));
}

uint8_t eclic_set_irq_priority(uint32_t source, uint8_t priority) 
{
	//extract nlbits
	uint8_t nlbits = eclic_get_nlbits();
	if (nlbits >= ECLICINTCTLBITS) 
	{
		nlbits = ECLICINTCTLBITS;
		return 0;
	}

	//shift priority into correct bit position
	priority = priority << (8 - ECLICINTCTLBITS);

	//write to eclicintctrl
	uint8_t current_intctrl = eclic_get_intctrl(source);
	//shift intctrl right to mask off unused bits
	current_intctrl = current_intctrl >> (8-nlbits);
	//shift intctrl into correct bit position
	current_intctrl = current_intctrl << (8-nlbits);

	eclic_set_intctrl(source, (current_intctrl | priority));

	return priority;
}


void eclic_irq_enable(uint32_t source, uint8_t lvl_abs, uint8_t priority)
{
    eclic_enable_interrupt(source);
    eclic_set_irq_lvl_abs(source, lvl_abs);		//set interrupt's level
    eclic_set_irq_priority(source, priority);	//set interrupt's priority
}


