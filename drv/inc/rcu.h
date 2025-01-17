////////////////////////////////////////////////////////////
// this file is used for RISCV GD32VF103 PLL configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-09
//


#ifndef RCU_H
#define	RCU_H


#define		RCU				RCU_BASE

/* registers definitions */
#define RCU_CTL			REG32(RCU + 0x00U)        /*!< control register */
#define RCU_CFG0		REG32(RCU + 0x04U)        /*!< clock configuration register 0 */
#define RCU_INT			REG32(RCU + 0x08U)        /*!< clock interrupt register */
#define RCU_APB2RST		REG32(RCU + 0x0CU)        /*!< APB2 reset register */
#define RCU_APB1RST		REG32(RCU + 0x10U)        /*!< APB1 reset register */
#define RCU_AHBEN		REG32(RCU + 0x14U)        /*!< AHB1 enable register */
#define RCU_APB2EN		REG32(RCU + 0x18U)        /*!< APB2 enable register */
#define RCU_APB1EN		REG32(RCU + 0x1CU)        /*!< APB1 enable register */
#define RCU_BDCTL		REG32(RCU + 0x20U)        /*!< backup domain control register */
#define RCU_RSTSCK		REG32(RCU + 0x24U)        /*!< reset source / clock register */
#define RCU_AHBRST		REG32(RCU + 0x28U)        /*!< AHB reset register */
#define RCU_CFG1		REG32(RCU + 0x2CU)        /*!< clock configuration register 1 */
#define RCU_DSV			REG32(RCU + 0x34U)        /*!< deep-sleep mode voltage register */


/* RCU_CTL bits */
#define		RCU_CTL_PLL2STB			BIT(29)
#define		RCU_CTL_PLL2EN			BIT(28)
#define		RCU_CTL_PLL1STB			BIT(27)
#define		RCU_CTL_PLL1EN			BIT(26)
#define		RCU_CTL_PLLSTB			BIT(25)
#define		RCU_CTL_PLLEN			BIT(24)
#define		RCU_CTL_CKMEN			BIT(19)
#define		RCU_CTL_HXTALBPS		BIT(18)
#define		RCU_CTL_HXTALSTB		BIT(17)
#define		RCU_CTL_HXTALEN			BIT(16)
#define		RCU_CTL_IRC8MSTB		BIT(1)
#define		RCU_CTL_IRC8MEN			BIT(0)

/* RCU_CFG0 bits */
#define		RCU_CFG0_PLLMF4			BIT(29)
#define		RCU_CFG0_ADCPSC2		BIT(28)
#define		RCU_CFG0_CKOUT0SEL(x)	((x) << 24)
#define		RCU_CFG0_USBFSPSC(x)	((x) << 22)
#define		RCU_CFG0_PLLMF(x)		((x) << 18)
#define		RCU_CFG0_PREDV0_LSB		BIT(17)
#define		RCU_CFG0_PLLSEL			BIT(16)
#define		RCU_CFG0_ADCPSC(x)		((x) << 14)
#define		RCU_CFG0_APB2PSC(x)		((x) << 11)
#define		RCU_CFG0_APB1PSC(x)		((x) << 8)
#define		RCU_CFG0_AHBPSC(x)		((x) << 4)
#define		RCU_CFG0_SCSS(x)		((x) << 2)
#define		RCU_CFG0_SCS(x)			((x) << 0)

/* RCU_INT bits */
#define		RCU_INT_CKMIC			BIT(23)
#define		RCU_INT_PLL2STBIC		BIT(22)
#define		RCU_INT_PLL1STBIC		BIT(21)
#define		RCU_INT_PLLSTBIC		BIT(20)
#define		RCU_INT_HXTALSTBIC		BIT(19)
#define		RCU_INT_IRC8MSTBIC		BIT(18)
#define		RCU_INT_LXTALSTBIC		BIT(17)
#define		RCU_INT_IRC40KSTBIC		BIT(16)
#define		RCU_INT_PLL2STBIE		BIT(14)
#define		RCU_INT_PLL1STBIE		BIT(13)
#define		RCU_INT_PLLSTBIE		BIT(12)
#define		RCU_INT_HXTALSTBIE		BIT(11)
#define		RCU_INT_IRC8MSTBIE		BIT(10)
#define		RCU_INT_LXTALSTBIE		BIT(9)
#define		RCU_INT_IRC40KSTBIE		BIT(8)
#define		RCU_INT_CKMIF			BIT(7)
#define		RCU_INT_PLL2STBIF		BIT(6)
#define		RCU_INT_PLL1STBIF		BIT(5)
#define		RCU_INT_PLLSTBIF		BIT(4)		
#define		RCU_INT_HXTALSTBIF		BIT(3)
#define		RCU_INT_IRC8MSTBIF		BIT(2)
#define		RCU_INT_LXTALSTBIF		BIT(1)
#define		RCU_INT_IRC40KSTBIF		BIT(0)

/* RCU_APB2RST bits */
#define		RCU_APB2RST_USART0RST	BIT(14)
#define		RCU_APB2RST_SPI0RST		BIT(12)
#define		RCU_APB2RST_TIMER0RST	BIT(11)
#define		RCU_APB2RST_ADC1RST		BIT(10)
#define		RCU_APB2RST_ADC0RST		BIT(9)
#define		RCU_APB2RST_PERST		BIT(6)
#define		RCU_APB2RST_PDRST		BIT(5)
#define		RCU_APB2RST_PCRST		BIT(4)
#define		RCU_APB2RST_PBRST		BIT(3)
#define		RCU_APB2RST_PARST		BIT(2)
#define		RCU_APB2RST_AFRST		BIT(0)

/* RCU_APB1RST bits */
#define		RCU_APB1RST_DACRST		BIT(29)
#define		RCU_APB1RST_PMURST		BIT(28)
#define		RCU_APB1RST_BKPIRST		BIT(27)
#define		RCU_APB1RST_CAN1RST		BIT(26)
#define		RCU_APB1RST_CAN0RST		BIT(25)
#define		RCU_APB1RST_I2C1RST		BIT(22)
#define		RCU_APB1RST_I2C0RST		BIT(21)
#define		RCU_APB1RST_UART4RST	BIT(20)
#define		RCU_APB1RST_UART3RST	BIT(19)
#define		RCU_APB1RST_USART2RST	BIT(18)
#define		RCU_APB1RST_USART1RST	BIT(17)
#define		RCU_APB1RST_SPI2RST		BIT(15)
#define		RCU_APB1RST_SPI1RST		BIT(14)
#define		RCU_APB1RST_WWDGTRST	BIT(11)
#define		RCU_APB1RST_TIMER6RST	BIT(5)
#define		RCU_APB1RST_TIMER5RST	BIT(4)
#define		RCU_APB1RST_TIMER4RST	BIT(3)
#define		RCU_APB1RST_TIMER3RST	BIT(2)
#define		RCU_APB1RST_TIMER2RST	BIT(1)
#define		RCU_APB1RST_TIMER1RST	BIT(0)

/* RCU_AHBEN bits */
#define		RCU_AHBEN_USBFSEN		BIT(12)
#define		RCU_AHBEN_EXMCEN		BIT(8)
#define		RCU_AHBEN_CRCEN			BIT(6)
#define		RCU_AHBEN_FMCSPEN		BIT(4)
#define		RCU_AHBEN_SRAMSPEN		BIT(2)
#define		RCU_AHBEN_DMA1EN		BIT(1)
#define		RCU_AHBEN_DMA0EN		BIT(0)

/* RCU_APB2EN bits */
#define		RCU_APB2EN_USART0EN		BIT(14)
#define		RCU_APB2EN_SPI0EN		BIT(12)
#define		RCU_APB2EN_TIMER0EN		BIT(11)
#define		RCU_APB2EN_ADC1EN		BIT(10)
#define		RCU_APB2EN_ADC0EN		BIT(9)
#define		RCU_APB2EN_PEEN			BIT(6)
#define		RCU_APB2EN_PDEN			BIT(5)
#define		RCU_APB2EN_PCEN			BIT(4)
#define		RCU_APB2EN_PBEN			BIT(3)
#define 	RCU_APB2EN_PAEN			BIT(2)
#define		RCU_APB2EN_AFEN			BIT(0)

/* RCU_APB1EN bits */
#define		RCU_APB1EN_DACEN		BIT(29)
#define		RCU_APB1EN_PMUEN		BIT(28)
#define		RCU_APB1EN_BKPIEN		BIT(27)
#define		RCU_APB1EN_CAN1EN		BIT(26)
#define		RCU_APB1EN_CAN0EN		BIT(25)
#define		RCU_APB1EN_I2C1EN		BIT(22)
#define		RCU_APB1EN_I2C0EN		BIT(21)
#define		RCU_APB1EN_UART4EN		BIT(20)
#define		RCU_APB1EN_UART3EN		BIT(19)
#define		RCU_APB1EN_USART2EN		BIT(18)
#define		RCU_APB1EN_USART1EN		BIT(17)
#define		RCU_APB1EN_SPI2EN		BIT(15)
#define		RCU_APB1EN_SPI1EN		BIT(14)
#define		RCU_APB1EN_WWDGTEN		BIT(11)
#define		RCU_APB1EN_TIMER6EN		BIT(5)
#define		RCU_APB1EN_TIMER5EN		BIT(4)
#define		RCU_APB1EN_TIMER4EN		BIT(3)
#define		RCU_APB1EN_TIMER3EN		BIT(2)
#define		RCU_APB1EN_TIMER2EN		BIT(1)
#define		RCU_APB1EN_TIMER1EN		BIT(0)

/* RCU_BDCTL bits */
#define		RCU_BDCTL_BKPRST		BIT(16)
#define		RCU_BDCTL_RTCEN			BIT(15)
#define		RCU_BDCTL_RTCSRC(x)		((x) << 8)
#define		RCU_BDCTL_LXTALBPS		BIT(2)
#define		RCU_BDCTL_LXTALSTB		BIT(1)
#define		RCU_BDCTL_LXTALEN		BIT(0)

/* RCU_RSTSCK bits */
#define		RCU_RSTSCK_LPRSTF		BIT(31)
#define		RCU_RSTSCK_WWDGTRSTF	BIT(30)
#define		RCU_RSTSCK_FWDGTRSTF	BIT(29)
#define		RCU_RSTSCK_SWRSTF		BIT(28)
#define		RCU_RSTSCK_PORRSTF		BIT(27)
#define		RCU_RSTSCK_EPRSTF		BIT(26)
#define 	RCU_RSTSCK_RSTFC		BIT(24)
#define		RCU_RSTSCK_IRC40KSTB	BIT(1)
#define		RCU_RSTSCK_IRC40KEN		BIT(0)

/* RCU_AHBRST bits */
#define		RCU_AHBRST_USBFSRST		BIT(12)

/* RCU_CFG1 bits */
#define		RCU_CFG1_I2S2SEL		BIT(18)
#define		RCU_CFG1_I2S1SEL		BIT(17)
#define		RCU_CFG1_PREDV0SEL		BIT(16)
#define		RCU_CFG1_PLL2MF(x)		((x) << 12)
#define		RCU_CFG1_PLL1MF(x)		((x) << 8)
#define		RCU_CFG1_PREDV1(x)		((x) << 4)
#define		RCU_CFG1_PREDV0(x)		((x) << 0)

/* RCU_DSV bits */
#define		RCU_DSV_DSLPVS(x)		((x) << 0)



//CTL mask value
#define		RCU_CTL_MASK_IRC8MCALIB	BITS(8, 15)
#define		RCU_CTL_MASK_IRC8MADJ	BITS(3, 7)

//CFG0 mask value
#define		RCU_CFG0_MASK_PLLMF4	BIT(29)
#define		RCU_CFG0_MASK_CKOUT0SEL	BITS(24, 27)
#define		RCU_CFG0_MASK_USBFSPSC	BITS(22, 23)
#define		RCU_CFG0_MASK_PLLMF		BITS(18, 21)
#define		RCU_CFG0_MASK_ADCPSC	BITS(14, 15)
#define		RCU_CFG0_MASK_APB2PSC	BITS(11, 13)
#define		RCU_CFG0_MASK_APB1PSC	BITS(8, 10)
#define		RCU_CFG0_MASK_AHBPSC	BITS(4, 7)
#define		RCU_CFG0_MASK_SCSS		BITS(2, 3)
#define		RCU_CFG0_MASK_SCS		BITS(0, 1)

//BDL mask value
#define		RCU_BDCTL_MASK_RTCSRC	BITS(8, 9)

//CFG1 mask value
#define		RCU_CFG1_MASK_PLL2MF	BITS(12, 15)
#define		RCU_CFG1_MASK_PLL1MF	BITS(8, 11)
#define		RCU_CFG1_MASK_PREDV1	BITS(4, 7)
#define		RCU_CFG1_MASK_PREDV0	BITS(0, 3)

//DSV mask value
#define		RCU_DSV_MASK_DSLPVS		BITS(0, 1)



#define		APB1RST_REG_OFFSET		0x10U
#define		APB2RST_REG_OFFSET		0x0CU
#define		AHBRST_REG_OFFSET		0x28U

#define		APB1EN_REG_OFFSET		0x1CU
#define		APB2EN_REG_OFFSET		0x18U
#define		AHBEN_REG_OFFSET		0x14U

#define 	RCU_REGIDX_BIT(regidx, bitpos)	(((uint32_t)(regidx) << 16) | (uint32_t)(bitpos))
#define 	RCU_REG(reg)			HWREG(REG32(RCU + ((uint32_t)(reg) >> 16)))
#define		REG_POS(pos)			((uint32_t)(pos) & 0xFFFFU)


/* peripherals reset */
typedef enum {
	/* AHB peripherals */
	RCU_USBFSRST = RCU_REGIDX_BIT(AHBRST_REG_OFFSET, 12U),

	/* APB1 peripherals */
	RCU_TIMER1RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 0U),
	RCU_TIMER2RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 1U),
	RCU_TIMER3RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 2U),
	RCU_TIMER4RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 3U),
	RCU_TIMER5RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 4U),
	RCU_TIMER6RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 5U),
	RCU_WWDGTRST  = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 11U),
	RCU_SPI1RST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 14U),
	RCU_SPI2RST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 15U),
	RCU_USART1RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 17U),
	RCU_USART2RST = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 18U),
	RCU_UART3RST  = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 19U),
	RCU_UART4RST  = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 20U),
	RCU_I2C0RST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 21U),
	RCU_I2C1RST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 22U),
	RCU_CAN0RST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 25U),
	RCU_CAN1RST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 26U),
	RCU_BKPIRST   = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 27U),
	RCU_PMURST    = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 28U),
	RCU_DACRST    = RCU_REGIDX_BIT(APB1RST_REG_OFFSET, 29U),

	/* APB2 peripherals */
	RCU_AFIORST   = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 0U),
	RCU_GPIOARST  = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 2U),
	RCU_GPIOBRST  = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 3U),
	RCU_GPIOCRST  = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 4U),
	RCU_GPIODRST  = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 5U),
	RCU_GPIOERST  = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 6U),
	RCU_ADC0RST   = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 9U), 
	RCU_ADC1RST   = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 10U),
	RCU_TIMER0RST = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 11U),
	RCU_SPI0RST   = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 12U),
	RCU_USART0RST = RCU_REGIDX_BIT(APB2RST_REG_OFFSET, 14U),

} perip_reset_enum;


/* peripherals clock enable */
typedef enum {
	/* AHB peripherals */
	RCU_USBFSEN = RCU_REGIDX_BIT(AHBEN_REG_OFFSET, 12U),

	/* APB1 peripherals */
	RCU_TIMER1EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 0U),
	RCU_TIMER2EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 1U),
	RCU_TIMER3EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 2U),
	RCU_TIMER4EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 3U),
	RCU_TIMER5EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 4U),
	RCU_TIMER6EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 5U),
	RCU_WWDGTEN  = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 11U),
	RCU_SPI1EN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 14U),
	RCU_SPI2EN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 15U),
	RCU_USART1EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 17U),
	RCU_USART2EN = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 18U),
	RCU_UART3EN  = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 19U),
	RCU_UART4EN  = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 20U),
	RCU_I2C0EN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 21U),
	RCU_I2C1EN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 22U),
	RCU_CAN0EN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 25U),
	RCU_CAN1EN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 26U),
	RCU_BKPIEN   = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 27U),
	RCU_PMUEN    = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 28U),
	RCU_DACEN    = RCU_REGIDX_BIT(APB1EN_REG_OFFSET, 29U),

	/* APB2 peripherals */
	RCU_AFEN     = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 0U),
	RCU_GPIOAEN  = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 2U),
	RCU_GPIOBEN  = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 3U),
	RCU_GPIOCEN  = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 4U),
	RCU_GPIODEN  = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 5U),
	RCU_GPIOEEN  = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 6U),
	RCU_ADC0EN   = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 9U), 
	RCU_ADC1EN   = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 10U),
	RCU_TIMER0EN = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 11U),
	RCU_SPI0EN   = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 12U),
	RCU_USART0EN = RCU_REGIDX_BIT(APB2EN_REG_OFFSET, 14U),

} perip_clk_enable_enum;


typedef enum
{
	CLKSRC_NULL 		= 0x00U,
	CLKSRC_CK_SYS 		= 0x04U,
	CLKSRC_IRC8M		= 0x05U,
	CLKSRC_HXTAL		= 0x06U,
	CLKSRC_CK_PLL_DIV2 	= 0x07U,
	CLKSRC_CK_PLL1 		= 0x08U,
	CLKSRC_CK_PLL2_DIV2 = 0x09U,
	CLKSRC_EXT1 		= 0x0AU,
	CLKSRC_CK_PLL2 		= 0x0BU,
}clkout_src_enum;


typedef struct 
{
	volatile uint32_t *ctl;
	volatile uint32_t *cfg0;
	volatile uint32_t *intt;
	volatile uint32_t *apb2rst;
	volatile uint32_t *apb1rst;
	volatile uint32_t *ahben;
	volatile uint32_t *apb2en;
	volatile uint32_t *apb1en;
	volatile uint32_t *bdctl;
	volatile uint32_t *rstsck;
	volatile uint32_t *ahbrst;
	volatile uint32_t *cfg1;
	volatile uint32_t *dsv;
}rcu_reg_cfg;


extern void clkout_select(clkout_src_enum clk_src);
extern void rcu_init(void);
extern void perip_reset_enable(perip_reset_enum perip);
extern void perip_reset_disable(perip_reset_enum perip);
extern void perip_clk_enable(perip_clk_enable_enum perip);
extern void perip_clk_disable(perip_clk_enable_enum perip);
extern void _system_init(void);

#endif //RCU_H