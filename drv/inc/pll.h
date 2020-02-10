////////////////////////////////////////////////////////////
// this file is used for RISCV GD32VF103 PLL configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-09
//


#ifndef PLL_H
#define	PLL_H

#define		RCU_CTL_PLL2STB			(1 << 29)
#define		RCU_CTL_PLL2EN			(1 << 28)
#define		RCU_CTL_PLL1STB			(1 << 27)
#define		RCU_CTL_PLL1EN			(1 << 26)
#define		RCU_CTL_PLLSTB			(1 << 25)
#define		RCU_CTL_PLLEN			(1 << 24)
#define		RCU_CTL_CKMEN			(1 << 19)
#define		RCU_CTL_HXTALBPS		(1 << 18)
#define		RCU_CTL_HXTALSTB		(1 << 17)
#define		RCU_CTL_HXTALEN			(1 << 16)
#define		RCU_CTL_IRC8MSTB		(1 << 1)
#define		RCU_CTL_IRC8MEN			(1 << 0)
#define		RCU_CTL					0x0			//CTL reg offset


#define		RCU_CFG0_PLLMF4			(1 << 29)
#define		RCU_CFG0_ADCPSC2		(1 << 28)
#define		RCU_CFG0_CKOUT0SEL(x)	((x) << 24)
#define		RCU_CFG0_USBFSPSC(x)	((x) << 22)
#define		RCU_CFG0_PLLMF(x)		((x) << 18)
#define		RCU_CFG0_PREDV0_LSB		(1 << 17)
#define		RCU_CFG0_PLLSEL			(1 << 16)
#define		RCU_CFG0_ADCPSC(x)		((x) << 14)
#define		RCU_CFG0_APB2PSC(x)		((x) << 11)
#define		RCU_CFG0_APB1PSC(x)		((x) << 8)
#define		RCU_CFG0_AHBPSC(x)		((x) << 4)
#define		RCU_CFG0_SCSS(x)		((x) << 2)
#define		RCU_CFG0_SCS(x)			((x) << 0)
#define		RCU_CFG0				0x4			//CFG0 reg offset


#define		RCU_INT_CKMIC			(1 << 23)
#define		RCU_INT_PLL2STBIC		(1 << 22)
#define		RCU_INT_PLL1STBIC		(1 << 21)
#define		RCU_INT_PLLSTBIC		(1 << 20)
#define		RCU_INT_HXTALSTBIC		(1 << 19)
#define		RCU_INT_IRC8MSTBIC		(1 << 18)
#define		RCU_INT_LXTALSTBIC		(1 << 17)
#define		RCU_INT_IRC40KSTBIC		(1 << 16)
#define		RCU_INT_PLL2STBIE		(1 << 14)
#define		RCU_INT_PLL1STBIE		(1 << 13)
#define		RCU_INT_PLLSTBIE		(1 << 12)
#define		RCU_INT_HXTALSTBIE		(1 << 11)
#define		RCU_INT_IRC8MSTBIE		(1 << 10)
#define		RCU_INT_LXTALSTBIE		(1 << 9)
#define		RCU_INT_IRC40KSTBIE		(1 << 8)
#define		RCU_INT_CKMIF			(1 << 7)
#define		RCU_INT_PLL2STBIF		(1 << 6)
#define		RCU_INT_PLL1STBIF		(1 << 5)
#define		RCU_INT_PLLSTBIF		(1 << 4)		
#define		RCU_INT_HXTALSTBIF		(1 << 3)
#define		RCU_INT_IRC8MSTBIF		(1 << 2)
#define		RCU_INT_LXTALSTBIF		(1 << 1)
#define		RCU_INT_IRC40KSTBIF		(1 << 0)
#define		RCU_INT					0x8			//INT reg offset


#define		RCU_APB2RST_USART0RST	(1 << 14)
#define		RCU_APB2RST_SPI0RST		(1 << 12)
#define		RCU_APB2RST_TIMER0RST	(1 << 11)
#define		RCU_APB2RST_ADC1RST		(1 << 10)
#define		RCU_APB2RST_ADC0RST		(1 << 9)
#define		RCU_APB2RST_PERST		(1 << 6)
#define		RCU_APB2RST_PDRST		(1 << 5)
#define		RCU_APB2RST_PCRST		(1 << 4)
#define		RCU_APB2RST_PBRST		(1 << 3)
#define		RCU_APB2RST_PARST		(1 << 2)
#define		RCU_APB2RST_AFRST		(1 << 0)
#define		RCU_APB2RST				0xC			//APB2RST reg offset


#define		RCU_APB1RST_DACRST		(1 << 29)
#define		RCU_APB1RST_PMURST		(1 << 28)
#define		RCU_APB1RST_BKPIRST		(1 << 27)
#define		RCU_APB1RST_CAN1RST		(1 << 26)
#define		RCU_APB1RST_CAN0RST		(1 << 25)
#define		RCU_APB1RST_I2C1RST		(1 << 22)
#define		RCU_APB1RST_I2C0RST		(1 << 21)
#define		RCU_APB1RST_UART4RST	(1 << 20)
#define		RCU_APB1RST_UART3RST	(1 << 19)
#define		RCU_APB1RST_USART2RST	(1 << 18)
#define		RCU_APB1RST_USART1RST	(1 << 17)
#define		RCU_APB1RST_SPI2RST		(1 << 15)
#define		RCU_APB1RST_SPI1RST		(1 << 14)
#define		RCU_APB1RST_WWDGTRST	(1 << 11)
#define		RCU_APB1RST_TIMER6RST	(1 << 5)
#define		RCU_APB1RST_TIMER5RST	(1 << 4)
#define		RCU_APB1RST_TIMER4RST	(1 << 3)
#define		RCU_APB1RST_TIMER3RST	(1 << 2)
#define		RCU_APB1RST_TIMER2RST	(1 << 1)
#define		RCU_APB1RST_TIMER1RST	(1 << 0)
#define		RCU_APB1RST				0x10		//APB1RST reg offset


#define		RCU_AHBEN_USBFSEN		(1 << 12)
#define		RCU_AHBEN_EXMCEN		(1 << 8)
#define		RCU_AHBEN_CRCEN			(1 << 6)
#define		RCU_AHBEN_FMCSPEN		(1 << 4)
#define		RCU_AHBEN_SRAMSPEN		(1 << 2)
#define		RCU_AHBEN_DMA1EN		(1 << 1)
#define		RCU_AHBEN_DMA0EN		(1 << 0)
#define		RCU_AHBEN				0x14		//AHBEN reg offset


#define		RCU_APB2EN_USART0EN		(1 << 14)
#define		RCU_APB2EN_SPI0EN		(1 << 12)
#define		RCU_APB2EN_TIMER0EN		(1 << 11)
#define		RCU_APB2EN_ADC1EN		(1 << 10)
#define		RCU_APB2EN_ADC0EN		(1 << 9)
#define		RCU_APB2EN_PEEN			(1 << 6)
#define		RCU_APB2EN_PDEN			(1 << 5)
#define		RCU_APB2EN_PCEN			(1 << 4)
#define		RCU_APB2EN_PBEN			(1 << 3)
#define 	RCU_APB2EN_PAEN			(1 << 2)
#define		RCU_APB2EN_AFEN			(1 << 0)
#define		RCU_APB2EN				0x18		//APB1EN reg offset


#define		RCU_APB1EN_DACEN		(1 << 29)
#define		RCU_APB1EN_PMUEN		(1 << 28)
#define		RCU_APB1EN_BKPIEN		(1 << 27)
#define		RCU_APB1EN_CAN1EN		(1 << 26)
#define		RCU_APB1EN_CAN0EN		(1 << 25)
#define		RCU_APB1EN_I2C1EN		(1 << 22)
#define		RCU_APB1EN_I2C0EN		(1 << 21)
#define		RCU_APB1EN_UART4EN		(1 << 20)
#define		RCU_APB1EN_UART3EN		(1 << 19)
#define		RCU_APB1EN_USART2EN		(1 << 18)
#define		RCU_APB1EN_USART1EN		(1 << 17)
#define		RCU_APB1EN_SPI2EN		(1 << 15)
#define		RCU_APB1EN_SPI1EN		(1 << 14)
#define		RCU_APB1EN_WWDGTEN		(1 << 11)
#define		RCU_APB1EN_TIMER6EN		(1 << 5)
#define		RCU_APB1EN_TIMER5EN		(1 << 4)
#define		RCU_APB1EN_TIMER4EN		(1 << 3)
#define		RCU_APB1EN_TIMER3EN		(1 << 2)
#define		RCU_APB1EN_TIMER2EN		(1 << 1)
#define		RCU_APB1EN_TIMER1EN		(1 << 0)
#define		RCU_APB1EN				0x1C		//APB1EN reg offset


#define		RCU_BDCTL_BKPRST		(1 << 16)
#define		RCU_BDCTL_RTCEN			(1 << 15)
#define		RCU_BDCTL_RTCSRC(x)		((x) << 8)
#define		RCU_BDCTL_LXTALBPS		(1 << 2)
#define		RCU_BDCTL_LXTALSTB		(1 << 1)
#define		RCU_BDCTL_LXTALEN		(1 << 0)
#define		RCU_BDCTL				0x20		//BDCTL reg offset


#define		RCU_RSTSCK_LPRSTF		(1 << 31)
#define		RCU_RSTSCK_WWDGTRSTF	(1 << 30)
#define		RCU_RSTSCK_FWDGTRSTF	(1 << 29)
#define		RCU_RSTSCK_SWRSTF		(1 << 28)
#define		RCU_RSTSCK_PORRSTF		(1 << 27)
#define		RCU_RSTSCK_EPRSTF		(1 << 26)
#define 	RCU_RSTSCK_RSTFC		(1 << 24)
#define		RCU_RSTSCK_IRC40KSTB	(1 << 1)
#define		RCU_RSTSCK_IRC40KEN		(1 << 0)
#define		RCU_RSTSCK				0x24		//RSTSCK reg offset


#define		RCU_AHBRST_USBFSRST		(1 << 12)
#define		RCU_AHBRST				0x28		//AHBRST reg offset


#define		RCU_CFG1_I2S2SEL		(1 << 18)
#define		RCU_CFG1_I2S1SEL		(1 << 17)
#define		RCU_CFG1_PREDV0SEL		(1 << 16)
#define		RCU_CFG1_PLL2MF(x)		((x) << 12)
#define		RCU_CFG1_PLL1MF(x)		((x) << 8)
#define		RCU_CFG1_PREDV1(x)		((x) << 4)
#define		RCU_CFG1_PREDV0(x)		((x) << 0)
#define		RCU_CFG1				0x2C		//CFG1 reg offset


#define		RCU_DSV_DSLPVS(x)		((x) << 0)
#define		RCU_DSV					0x34		//DSV reg offset


#define		RCU_BASE				0x40021000


static inline uint32_t pll_reg_read(uint32_t reg)
{
	return reg32_read(RCU_BASE + reg);
}

static inline void pll_reg_write(uint32_t reg, uint32_t val)
{
	reg32_write(RCU_BASE + reg, val);
}

extern void pll_init(void);

#endif //PLL_H
