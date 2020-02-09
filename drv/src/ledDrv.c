////////////////////////////////////////////////////////////
// this file is used for s3c2440 timer configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-26
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include 	"devRegs.h"
#include 	"ledDrv.h"


void led_init(enum GPIO gpio)
{
	switch(gpio)
	{
	case GPIOA:
		break;
	case GPIOB:
		break;
	case GPIOC:
		break;
	case GPIOD:
		break;
	case GPIOE:
		break;
	case GPIOF:
		GPFCON = 0x1500;
		break;
	case GPIOG:
		break;
	case GPIOH:
		break;
	default:
		break;
	}
}

void led_switch(enum GPIO gpio, uint8_t lednum, enum STATE state)
{
	switch(gpio)
	{
	case GPIOA:
		break;
	case GPIOB:
		break;
	case GPIOC:
		break;
	case GPIOD:
		break;
	case GPIOE:
		break;
	case GPIOF:
		if (state == LED_OFF)
		{
			GPFDAT = GPFDAT | (1 << lednum);
		}
		else
		{
			GPFDAT = GPFDAT & (~(1 << lednum));
		}
		break;
	case GPIOG:
		break;
	case GPIOH:
		break;
	default:
		break;
	}
}

