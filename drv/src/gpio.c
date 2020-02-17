////////////////////////////////////////////////////////////
// this file is used for s3c2440 timer configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-26
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include 	"devRegs.h"
#include 	"regs_opt.h"
#include	"rcu.h"
#include 	"gpio.h"

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

//GPIO reg list
#define		GPIO_CTL0(group)		REG32(GPIOA_BASE + (group-1) * 0x400 + 0x00)
#define		GPIO_CTL1(group)		REG32(GPIOA_BASE + (group-1) * 0x400 + 0x04)
#define		GPIO_ISTAT(group)		REG32(GPIOA_BASE + (group-1) * 0x400 + 0x08)
#define		GPIO_OCTL(group)		REG32(GPIOA_BASE + (group-1) * 0x400 + 0x0C)
#define		GPIO_BOP(group)			REG32(GPIOA_BASE + (group-1) * 0x400 + 0x10)
#define		GPIO_BC(group)			REG32(GPIOA_BASE + (group-1) * 0x400 + 0x14)
#define		GPIO_LOCK(group)		REG32(GPIOA_BASE + (group-1) * 0x400 + 0x18)

//AFIO reg list
#define		AFIO_EC					REG32(AFIO_BASE + 0x00)
#define		AFIO_PCF0				REG32(AFIO_BASE + 0x04)
#define		AFIO_EXTISS0			REG32(AFIO_BASE + 0x08)
#define		AFIO_EXTISS1			REG32(AFIO_BASE + 0x0C)
#define		AFIO_EXTISS2			REG32(AFIO_BASE + 0x10)
#define		AFIO_EXTISS3			REG32(AFIO_BASE + 0x14)
#define		AFIO_PCF1				REG32(AFIO_BASE + 0x1C)

static void gpio_reset(gpio_group_enum group)
{
	switch(group)
	{
	case GPIOA:
		perip_reset_enable(RCU_GPIOARST);
		perip_reset_disable(RCU_GPIOARST);
		break;
	case GPIOB:
		perip_reset_enable(RCU_GPIOBRST);
		perip_reset_disable(RCU_GPIOBRST);
		break;
	case GPIOC:
		perip_reset_enable(RCU_GPIOCRST);
		perip_reset_disable(RCU_GPIOCRST);		
		break;
	case GPIOD:
		perip_reset_enable(RCU_GPIODRST);
		perip_reset_disable(RCU_GPIODRST);
		break;
	case GPIOE:
		perip_reset_enable(RCU_GPIOERST);
		perip_reset_disable(RCU_GPIOERST);
		break;
	case AFIO:
		perip_reset_enable(RCU_AFIORST);
		perip_reset_disable(RCU_AFIORST);
		break;
	default:
		break;
	}
}

void gpio_init(void)
{
	gpio_group_enum i;

	for(i=GPIOA; i<GPIO_GROUP_NUM; i++)
	{
		gpio_reset(i);
	}
}

#define		CTL_MD_MASK(port)		((uint32_t)(0x0F << ((port) * 4)))
#define		CTL_MD_SET(port, val)	((uint32_t)((val) << ((port) * 4)))


uint8_t gpio_cfg(gpio_group_enum group, uint32_t port, uint32_t mode, uint32_t speed)
{
	uint32_t reg;
	uint32_t val;

	if(port >= PORT_MAX)
		return false;

	val = (mode & 0x03) | ((speed & 0x03) << 2);

	if(port <= 0x8U)
	{
		reg  = HWREG(GPIO_CTL0(group));
		reg &= CTL_MD_MASK(port);
		reg |= CTL_MD_SET(port, val);
		HWREG(GPIO_CTL0(group)) = reg;
	}
	else //8< port <= 15
	{
		reg = HWREG(GPIO_CTL1(group));
		reg &= CTL_MD_MASK(port-8);
		reg |= CTL_MD_SET(port-8, val);
		HWREG(GPIO_CTL0(group)) = reg;
	}

	return true;
}

void gpio_write(gpio_group_enum group, uint32_t port, uint32_t val)
{
}

uint32_t gpio_read(gpio_group_enum group, uint32_t port)
{
}


