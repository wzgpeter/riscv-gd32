////////////////////////////////////////////////////////////
// this file is used for gd32vf103 platform
//
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-13
//
// Notes:
//		
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include	"regs_opt.h"
#include 	"devRegs.h"
#include	"interrupt.h"


uint8_t	irq_register(BaseType_t (*func)(void), uint8_t int_offset)
{
	return pdTRUE;
}


void do_irq(void)
{

}


void glob_intr_disable(void)
{
	asm volatile(" 	li		t0, 0x00000008 \n\t "
				 "	csrc 	mstatus, t0 ");
}

void glob_intr_enable(void)
{
	asm volatile(" 	li		t0, 0x00000008 \n\t "
				 "	csrs 	mstatus, t0 ");
}


static void eclic_intr_enable(uint32_t irqId) 
{
	HWREG(ECLIC_INTIE(irqId)) = 0x1;
}

static void eclic_intr_disable(uint32_t irqId)
{
	HWREG(ECLIC_INTIE(irqId)) = 0x0;
}

void eclic_intctl_set(uint32_t irqId, uint8_t intctrl)
{
	HWREG(ECLIC_INTCTL(irqId)) = intctrl;
}

uint8_t eclic_intctl_get(uint32_t irqId)
{
	return HWREG(ECLIC_INTCTL(irqId));
}

void eclic_cliccfg_set(uint8_t cliccfg)
{
	HWREG(ECLIC_CFG) = cliccfg;
}

static uint8_t eclic_cliccfg_get(void)
{
	return HWREG(ECLIC_CFG);
}

void eclic_set_nlbits(uint8_t nlbits) 
{
	//shift nlbits to correct position
	uint8_t nlbits_shifted = nlbits << ECLIC_CFG_NLBITS_LSB;

	//read the current cliccfg 
	uint8_t old_cliccfg = eclic_cliccfg_get();
	uint8_t new_cliccfg = (old_cliccfg & (~ECLIC_CFG_NLBITS_MASK)) | (ECLIC_CFG_NLBITS_MASK & nlbits_shifted); 

	eclic_cliccfg_set(new_cliccfg);
}

uint8_t eclic_get_nlbits(void) 
{
	//extract nlbits
	uint8_t nlbits = eclic_cliccfg_get();
	nlbits = (nlbits & ECLIC_CFG_NLBITS_MASK) >> ECLIC_CFG_NLBITS_LSB;
	return nlbits;
}

void eclic_set_irq_level(uint32_t irqId, uint8_t level) 
{
	//extract nlbits
	uint8_t nlbits = eclic_get_nlbits();
	if (nlbits > ECLIC_INTCTLBITS) 
	{
		nlbits = ECLIC_INTCTLBITS;
	}

	uint8_t lvl = level << (8-nlbits);

	//update clicintctl
	uint8_t current_intctl = eclic_intctl_get(irqId);
	current_intctl = current_intctl << nlbits;
	current_intctl = current_intctl >> nlbits;
	eclic_intctl_set(irqId, (current_intctl | lvl));
}

uint8_t eclic_set_irq_priority(uint32_t irqId, uint8_t priority) 
{
	//extract nlbits
	uint8_t nlbits = eclic_get_nlbits();
	if (nlbits >= ECLIC_INTCTLBITS) 
	{
		nlbits = ECLIC_INTCTLBITS;
		return 0;
	}

	priority = priority << (8 - ECLIC_INTCTLBITS);

	//update clicintctl
	uint8_t current_intctl = eclic_intctl_get(irqId);
	current_intctl = current_intctl >> (8-nlbits);
	current_intctl = current_intctl << (8-nlbits);
	eclic_intctl_set(irqId, (current_intctl | priority));

	return priority;
}

void eclic_irq_enable(uint32_t irqId, uint8_t level, uint8_t priority)
{
    eclic_intr_enable(irqId);
    eclic_set_irq_level(irqId, level);
    eclic_set_irq_priority(irqId, priority);
}

void eclic_init(uint32_t irqId)
{
	typedef volatile uint32_t vuint32_t;

	HWREG(REG8(ECLIC_CFG)) = 0;
	HWREG(REG8(ECLIC_MTH)) = 0;

	//clear all IP/IE/ATTR/CTRL bits for all interrupt sources
	vuint32_t *ptr;
	vuint32_t *base = (vuint32_t *)(ECLIC_ADDR_BASE + ECLIC_INTIP_OFFSET);
	vuint32_t *upper = (vuint32_t *)(base + irqId*4);

	for (ptr=base; ptr < upper; ptr=ptr+4)
	{
		*ptr = 0;
	}
}

