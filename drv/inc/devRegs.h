////////////////////////////////////////////////////////////
// this file is used for s3c2440 timer configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-14
//

#ifndef	DEV_REGS_H
#define DEV_REGS_H

//Interrupt Configuration Registers

//the interrupt sources for all interrupts
#define		INT_OFFSET_ADC			(31)
#define		INT_OFFSET_RTC			(30)
#define		INT_OFFSET_SPI1			(29)
#define		INT_OFFSET_UART0		(28)
#define		INT_OFFSET_IIC			(27)
#define		INT_OFFSET_USBH			(26)
#define		INT_OFFSET_USBD			(25)
#define		INT_OFFSET_NFCON		(24)
#define		INT_OFFSET_UART1		(23)
#define		INT_OFFSET_SPI0			(22)
#define		INT_OFFSET_SDI			(21)
#define		INT_OFFSET_DMA3			(20)
#define		INT_OFFSET_DMA2			(19)
#define		INT_OFFSET_DMA1			(18)
#define		INT_OFFSET_DMA0			(17)
#define		INT_OFFSET_LCD			(16)
#define		INT_OFFSET_UART2		(15)
#define		INT_OFFSET_TIMER4		(14)
#define		INT_OFFSET_TIMER3		(13)
#define		INT_OFFSET_TIMER2		(12)
#define		INT_OFFSET_TIMER1		(11)
#define		INT_OFFSET_TIMER0		(10)
#define		INT_OFFSET_WDT_AC97		(9)
#define		INT_OFFSET_TICK			(8)
#define		INT_OFFSET_NBATT_FLT	(7)
#define		INT_OFFSET_CAM			(6)
#define		INT_OFFSET_EINT8_23		(5)
#define		INT_OFFSET_EINT4_7		(4)
#define		INT_OFFSET_EINT3		(3)
#define		INT_OFFSET_EINT2		(2)
#define		INT_OFFSET_EINT1		(1)

//the bit mapping for all interrupts
#define		INT_ADC			((unsigned int)(1<<31))
#define		INT_RTC			((unsigned int)(1<<30))
#define		INT_SPI1		((unsigned int)(1<<29))
#define		INT_UART0		((unsigned int)(1<<28))
#define		INT_IIC			((unsigned int)(1<<27))
#define		INT_USBH		((unsigned int)(1<<26))
#define		INT_USBD		((unsigned int)(1<<25))
#define		INT_NFCON		((unsigned int)(1<<24))
#define		INT_UART1		((unsigned int)(1<<23))
#define		INT_SPI0		((unsigned int)(1<<22))
#define		INT_SDI			((unsigned int)(1<<21))
#define		INT_DMA3		((unsigned int)(1<<20))
#define		INT_DMA2		((unsigned int)(1<<19))
#define		INT_DMA1		((unsigned int)(1<<18))
#define		INT_DMA0		((unsigned int)(1<<17))
#define		INT_LCD			((unsigned int)(1<<16))
#define		INT_UART2		((unsigned int)(1<<15))
#define		INT_TIMER4		((unsigned int)(1<<14))
#define		INT_TIMER3		((unsigned int)(1<<13))
#define		INT_TIMER2		((unsigned int)(1<<12))
#define		INT_TIMER1		((unsigned int)(1<<11))
#define		INT_TIMER0		((unsigned int)(1<<10))
#define		INT_WDT_AC97	((unsigned int)(1<<9))
#define		INT_TICK		((unsigned int)(1<<8))
#define		INT_NBATT_FLT	((unsigned int)(1<<7))
#define		INT_CAM			((unsigned int)(1<<6))
#define		INT_EINT8_23	((unsigned int)(1<<5))
#define		INT_EINT4_7		((unsigned int)(1<<4))
#define		INT_EINT3		((unsigned int)(1<<3))
#define		INT_EINT2		((unsigned int)(1<<2))
#define		INT_EINT1		((unsigned int)(1<<1))


#define		SRCPND		(*(volatile unsigned int *)0x4A000000)
#define		INTMOD		(*(volatile unsigned int *)0x4A000004)
#define		INTMSK		(*(volatile unsigned int *)0x4A000008)
#define		INTPND		(*(volatile unsigned int *)0x4A000010)
#define		INTOFFSET	(*(volatile unsigned int *)0x4A000014)
#define		SUBSRCPND	(*(volatile unsigned int *)0x4A000018)
#define		INTSUBMSK	(*(volatile unsigned int *)0x4A00001C)

//=====================================================================

//Timer Configuration Registers
#define		TCFG0		(*(volatile unsigned int *)0x51000000)
#define		TCFG1		(*(volatile unsigned int *)0x51000004)
#define		TCON		(*(volatile unsigned int *)0x51000008)

#define		TCNTB0		(*(volatile unsigned int *)0x5100000C)
#define		TCMPB0		(*(volatile unsigned int *)0x51000010)

#define		TCNTB1		(*(volatile unsigned int *)0x51000018)
#define		TCMPB1		(*(volatile unsigned int *)0x5100001C)

#define		TCNTB2		(*(volatile unsigned int *)0x51000024)
#define		TCMPB2		(*(volatile unsigned int *)0x51000028)

#define		TCNTB3		(*(volatile unsigned int *)0x51000030)
#define		TCMPB3		(*(volatile unsigned int *)0x51000034)

#define		TCNTB4		(*(volatile unsigned int *)0x5100003C)
#define		TCNTO4		(*(volatile unsigned int *)0x51000040)


//=====================================================================
// GPIO 

#define		GPACON		(*(volatile unsigned int *)0x56000000)
#define		GPADAT		(*(volatile unsigned int *)0x56000004)

#define		GPBCON		(*(volatile unsigned int *)0x56000010)
#define		GPBDAT		(*(volatile unsigned int *)0x56000014)
#define		GPBUP		(*(volatile unsigned int *)0x56000018)

#define		GPCCON		(*(volatile unsigned int *)0x56000020)
#define		GPCDAT		(*(volatile unsigned int *)0x56000024)
#define		GPCUP		(*(volatile unsigned int *)0x56000028)

#define		GPDCON		(*(volatile unsigned int *)0x56000030)
#define		GPDDAT		(*(volatile unsigned int *)0x56000034)
#define		GPDUP		(*(volatile unsigned int *)0x56000038)

#define		GPECON		(*(volatile unsigned int *)0x56000040)
#define		GPEDAT		(*(volatile unsigned int *)0x56000044)
#define		GPEUP		(*(volatile unsigned int *)0x56000048)

#define		GPFCON		(*(volatile unsigned int *)0x56000050)
#define		GPFDAT		(*(volatile unsigned int *)0x56000054)
#define		GPFUP		(*(volatile unsigned int *)0x56000058)

#define		GPGCON		(*(volatile unsigned int *)0x56000060)
#define		GPGDAT		(*(volatile unsigned int *)0x56000064)
#define		GPGUP		(*(volatile unsigned int *)0x56000068)

#define		GPHCON		(*(volatile unsigned int *)0x56000070)
#define		GPHDAT		(*(volatile unsigned int *)0x56000074)
#define		GPHUP		(*(volatile unsigned int *)0x56000078)

#define		GPJCON		(*(volatile unsigned int *)0x560000D0)
#define		GPJDAT		(*(volatile unsigned int *)0x560000D4)
#define		GPJUP		(*(volatile unsigned int *)0x560000D8)


#endif //DEV_REGS_H

