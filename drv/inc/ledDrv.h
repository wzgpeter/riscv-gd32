////////////////////////////////////////////////////////////
// this file is used for s3c2440 timer configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-26
//

#ifndef DEV_LED_H
#define	DEV_LED_H

enum GPIO
{
	GPIOA = 0xA0,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOI,
};

enum STATE
{
	LED_ON = 0xAA,
	LED_OFF = 0x55,
};


extern void led_init(enum GPIO gpio);
extern void led_switch(enum GPIO gpio, uint8_t lednum, enum STATE state);

#endif //DEV_LED_H

