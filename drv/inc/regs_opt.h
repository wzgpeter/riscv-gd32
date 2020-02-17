////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-09
//
#ifndef REGS_OP_H
#define REGS_OP_H

#define		RCU_BASE			0x40021000

#define		EXTI_BASE			0x40010400

#define		AFIO_BASE			0x40010000
#define		GPIOA_BASE			0x40010800
#define		GPIOB_BASE			0x40010C00
#define		GPIOC_BASE			0x40011000
#define		GPIOD_BASE			0x40011400
#define		GPIOE_BASE			0x40011800

#define		TIMER0_BASE			0x40012C00
#define		TIMER1_BASE			0x40000000
#define		TIMER2_BASE			0x40000400
#define		TIMER3_BASE			0x40000800
#define		TIMER4_BASE			0x40000C00
#define		TIMER5_BASE			0x40001000
#define		TIMER6_BASE			0x40001400

#define 	ECLIC_ADDR_BASE		0xd2000000


#define		HWREG(addr)			(*addr)
#define		REG8(addr)			((volatile uint8_t *)(uint32_t)(addr))
#define		REG16(addr)			((volatile uint16_t *)(uint32_t)(addr))
#define		REG32(addr)			((volatile uint32_t *)(uint32_t)(addr))


#define		BIT(x)				((uint32_t)((uint32_t)0x1U<<(x)))
#define 	BITS(start, end)	((0xFFFFFFFFUL << (start)) & (0xFFFFFFFFUL >> (31U - (uint32_t)(end))))

#endif //REGS_OP_H