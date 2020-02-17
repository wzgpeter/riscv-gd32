////////////////////////////////////////////////////////////
// this file is used for gd32vf103 platform
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-14
//

#ifndef GPIO_H
#define	GPIO_H

#define		GPIO_INPUT_MODE			0x01

#define		GPIO_MODE_IN_ANALOG		0x00	/* Analog mode */
#define		GPIO_MODE_IN_FLOAT		0x01	/* Floating input */
#define		GPIO_MODE_IN_PULL		0x02	/* Input with pull-up/pull down */

#define		GPIO_MODE_OUT_PP		0x00	/* GPIO output with push-pull */
#define		GPIO_MODE_OUT_OD		0x01	/* GPIO output with open-drain */
#define		AFIO_MODE_OUT_PP		0x02	/* AFIO output with push-pull */
#define		AFIO_MODE_OUT_OD		0x03	/* AFIO output with open-drain */


typedef enum
{
	GPIOA = 0x00,
	GPIOB = 0x01,
	GPIOC = 0x02,
	GPIOD = 0x03,
	GPIOE = 0x04,
	AFIO  = 0x05,
	GPIO_GROUP_NUM
}gpio_group_enum;


typedef enum
{
	PORT0	= 0x0,
	PORT1 	= 0x1,
	PORT2	= 0x2,
	PORT3	= 0x3,
	PORT4	= 0x4,
	PORT5	= 0x5,
	PORT6	= 0x6,
	PORT7	= 0x7,
	PORT8 	= 0x8,
	PORT9	= 0x9,
	PORT10	= 0xA,
	PORT11	= 0xB,
	PORT12	= 0xC,
	PORT13 	= 0xD,
	PORT14	= 0xE,
	PORT15	= 0xF,
	PORT_MAX = 0x10
}gpio_port_enum;

extern void gpio_init(void);
extern uint8_t gpio_cfg(gpio_group_enum group, uint32_t port, uint32_t mode, uint32_t speed);
extern void gpio_write(gpio_group_enum group, uint32_t port, uint32_t val);
extern uint32_t gpio_read(gpio_group_enum group, uint32_t port);

#endif //GPIO_H
