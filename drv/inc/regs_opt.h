////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-09
//
#ifndef REGS_OP_H
#define REGS_OP_H

#define		RCU_BASE		0x40021000

#define		AFIO_BASE		0x40010000
#define		GPIOA_BASE		0x40010800
#define		GPIOB_BASE		0x40010C00
#define		GPIOC_BASE		0x40011000
#define		GPIOD_BASE		0x40011400
#define		GPIOE_BASE		0x40011800


#define		HWREG(addr)		(*addr)

#define		REG32(addr)		((volatile uint32_t *)(uint32_t)(addr))

#define	BIT(x)					((uint32_t)((uint32_t)0x1U<<(x)))
#define BITS(start, end)		((0xFFFFFFFFUL << (start)) & (0xFFFFFFFFUL >> (31U - (uint32_t)(end))))

#endif //REGS_OP_H