////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-13
//
#ifndef TIMER_H
#define TIMER_H

//TIMER0 regs
#define		TIMER0_CTL0			REG32(TIMER0_BASE + 0x00U)
#define		TIMER0_CTL1			REG32(TIMER0_BASE + 0x04U)
#define		TIMER0_SMCFG		REG32(TIMER0_BASE + 0x08U)
#define		TIMER0_DMAINTEN		REG32(TIMER0_BASE + 0x0CU)
#define		TIMER0_INTF			REG32(TIMER0_BASE + 0x10U)
#define		TIMER0_SWEVG		REG32(TIMER0_BASE + 0x14U)
#define		TIMER0_CHCTL0		REG32(TIMER0_BASE + 0x18U)
#define		TIMER0_CHCTL1		REG32(TIMER0_BASE + 0x1CU)
#define		TIMER0_CHCTL2		REG32(TIMER0_BASE + 0x20U)
#define		TIMER0_CNT			REG32(TIMER0_BASE + 0x24U)
#define		TIMER0_PSC			REG32(TIMER0_BASE + 0x28U)
#define		TIMER0_CAR			REG32(TIMER0_BASE + 0x2CU)
#define		TIMER0_CREP			REG32(TIMER0_BASE + 0x30U)
#define		TIMER0_CH0CV		REG32(TIMER0_BASE + 0x34U)
#define		TIMER0_CH1CV		REG32(TIMER0_BASE + 0x38U)
#define		TIMER0_CH2CV		REG32(TIMER0_BASE + 0x3CU)
#define		TIMER0_CH3CV		REG32(TIMER0_BASE + 0x40U)
#define		TIMER0_CCHP			REG32(TIMER0_BASE + 0x44U)
#define		TIMER0_DMACFG		REG32(TIMER0_BASE + 0x48U)
#define		TIMER0_DMATB		REG32(TIMER0_BASE + 0x4CU)


//TIMERn: n=1,2,3,4,5,6 regs
#define		TIMER_CTL0(n)		REG32(TIMER1_BASE + 0x00U + (n-1) * 0x400U)
#define		TIMER_CTL1(n)		REG32(TIMER1_BASE + 0x04U + (n-1) * 0x400U)
#define		TIMER_SMCFG(n)		REG32(TIMER1_BASE + 0x08U + (n-1) * 0x400U)
#define		TIMER_DMAINTEN(n)	REG32(TIMER1_BASE + 0x0CU + (n-1) * 0x400U)
#define		TIMER_INTF(n)		REG32(TIMER1_BASE + 0x10U + (n-1) * 0x400U)
#define		TIMER_SWEVG(n)		REG32(TIMER1_BASE + 0x14U + (n-1) * 0x400U)
#define		TIMER_CHCTL0(n)		REG32(TIMER1_BASE + 0x18U + (n-1) * 0x400U)
#define		TIMER_CHCTL1(n)		REG32(TIMER1_BASE + 0x1CU + (n-1) * 0x400U)
#define		TIMER_CHCTL2(n)		REG32(TIMER1_BASE + 0x20U + (n-1) * 0x400U)
#define		TIMER_CNT(n)		REG32(TIMER1_BASE + 0x24U + (n-1) * 0x400U)
#define		TIMER_PSC(n)		REG32(TIMER1_BASE + 0x28U + (n-1) * 0x400U)
#define		TIMER_CAR(n)		REG32(TIMER1_BASE + 0x2CU + (n-1) * 0x400U)
#define		TIMER_CH0CV(n)		REG32(TIMER1_BASE + 0x34U + (n-1) * 0x400U)
#define		TIMER_CH1CV(n)		REG32(TIMER1_BASE + 0x38U + (n-1) * 0x400U)
#define		TIMER_CH2CV(n)		REG32(TIMER1_BASE + 0x3CU + (n-1) * 0x400U)
#define		TIMER_CH3CV(n)		REG32(TIMER1_BASE + 0x40U + (n-1) * 0x400U)
#define		TIMER_DMACFG(n)		REG32(TIMER1_BASE + 0x48U + (n-1) * 0x400U)
#define		TIMER_DMATB(n)		REG32(TIMER1_BASE + 0x4CU + (n-1) * 0x400U)



/* bits definitions */
/* TIMER_CTL0 */
#define TIMER_CTL0_CEN					BIT(0)
#define TIMER_CTL0_UPDIS				BIT(1)
#define TIMER_CTL0_UPS					BIT(2)
#define TIMER_CTL0_SPM					BIT(3)
#define TIMER_CTL0_DIR					BIT(4)
#define TIMER_CTL0_CAM_MASK				BITS(5,6)
#define	TIMER_CTL0_CAM(x)				(((x) & 0x3U) << 5)
#define TIMER_CTL0_ARSE					BIT(7)
#define TIMER_CTL0_CKDIV_MASK			BITS(8,9)
#define TIMER_CTL0_CKDIV(x)				(((x) & 0x3U) << 8)


/* TIMER_CTL1 */
#define TIMER_CTL1_CCSE					BIT(0)
#define TIMER_CTL1_CCUC					BIT(2)
#define TIMER_CTL1_DMAS					BIT(3)
#define TIMER_CTL1_MMC_MASK				BITS(4,6)
#define TIMER_CTL1_MMC(x)				(((x) & 0x7U) << 4)
#define TIMER_CTL1_TI0S					BIT(7)
#define TIMER_CTL1_ISO0					BIT(8)
#define TIMER_CTL1_ISO0N				BIT(9)
#define TIMER_CTL1_ISO1					BIT(10)
#define TIMER_CTL1_ISO1N				BIT(11)
#define TIMER_CTL1_ISO2					BIT(12)
#define TIMER_CTL1_ISO2N				BIT(13)
#define TIMER_CTL1_ISO3					BIT(14)

/* TIMER_SMCFG */
#define TIMER_SMCFG_SMC_MASK			BITS(0,2)
#define TIMER_SMCFG_SMC(x)				((x) & 0x7U)
#define TIMER_SMCFG_TRGS_MASK			BITS(4,6)
#define TIMER_SMCFG_TRGS(x)				(((x) & 0x7U) << 4)
#define TIMER_SMCFG_MSM					BIT(7)
#define TIMER_SMCFG_ETFC_MASK			BITS(8,11)
#define TIMER_SMCFG_ETFC(x)				(((x) & 0xFU) << 8)
#define TIMER_SMCFG_ETPSC_MASK			BITS(12,13)
#define TIMER_SMCFG_ETPSC(x)			(((x) & 0x3U) << 12)
#define TIMER_SMCFG_SMC1				BIT(14)
#define TIMER_SMCFG_ETP					BIT(15)

/* TIMER_DMAINTEN */
#define TIMER_DMAINTEN_UPIE				BIT(0)
#define TIMER_DMAINTEN_CH0IE			BIT(1)
#define TIMER_DMAINTEN_CH1IE			BIT(2)
#define TIMER_DMAINTEN_CH2IE			BIT(3)
#define TIMER_DMAINTEN_CH3IE			BIT(4)
#define TIMER_DMAINTEN_CMTIE			BIT(5)
#define TIMER_DMAINTEN_TRGIE			BIT(6)
#define TIMER_DMAINTEN_BRKIE			BIT(7)
#define TIMER_DMAINTEN_UPDEN			BIT(8)
#define TIMER_DMAINTEN_CH0DEN			BIT(9)
#define TIMER_DMAINTEN_CH1DEN			BIT(10)
#define TIMER_DMAINTEN_CH2DEN			BIT(11)
#define TIMER_DMAINTEN_CH3DEN			BIT(12)
#define TIMER_DMAINTEN_CMTDEN			BIT(13)
#define TIMER_DMAINTEN_TRGDEN			BIT(14)

/* TIMER_INTF */
#define TIMER_INTF_UPIF					BIT(0)
#define TIMER_INTF_CH0IF				BIT(1)
#define TIMER_INTF_CH1IF				BIT(2)
#define TIMER_INTF_CH2IF				BIT(3)
#define TIMER_INTF_CH3IF				BIT(4)
#define TIMER_INTF_CMTIF				BIT(5)
#define TIMER_INTF_TRGIF				BIT(6)
#define TIMER_INTF_BRKIF				BIT(7)
#define TIMER_INTF_CH0OF				BIT(9)
#define TIMER_INTF_CH1OF				BIT(10)
#define TIMER_INTF_CH2OF				BIT(11)
#define TIMER_INTF_CH3OF				BIT(12)

/* TIMER_SWEVG */
#define TIMER_SWEVG_UPG					BIT(0)
#define TIMER_SWEVG_CH0G				BIT(1)
#define TIMER_SWEVG_CH1G				BIT(2)
#define TIMER_SWEVG_CH2G				BIT(3)
#define TIMER_SWEVG_CH3G				BIT(4)
#define TIMER_SWEVG_CMTG				BIT(5)
#define TIMER_SWEVG_TRGG				BIT(6)
#define TIMER_SWEVG_BRKG				BIT(7)

/* TIMER_CHCTL0 */
/* output compare mode */
#define TIMER_CHCTL0_CH0MS_MASK			BITS(0,1)
#define TIMER_CHCTL0_CH0MS(x)			((x) & 0x3U)
#define TIMER_CHCTL0_CH0COMFEN			BIT(2)
#define TIMER_CHCTL0_CH0COMSEN			BIT(3)
#define TIMER_CHCTL0_CH0COMCTL_MASK		BITS(4,6)
#define TIMER_CHCTL0_CH0COMCTL(x)		(((x) & 0x7U) << 4)
#define TIMER_CHCTL0_CH0COMCEN			BIT(7)
#define TIMER_CHCTL0_CH1MS_MASK			BITS(8,9)
#define TIMER_CHCTL0_CH1MS(x)			(((x) & 0x3U) << 8)
#define TIMER_CHCTL0_CH1COMFEN			BIT(10)
#define TIMER_CHCTL0_CH1COMSEN			BIT(11)
#define TIMER_CHCTL0_CH1COMCTL_MASK		BITS(12,14)
#define TIMER_CHCTL0_CH1COMCTL(x)		(((x) & 0x7U) << 12)
#define TIMER_CHCTL0_CH1COMCEN			BIT(15)
/* input capture mode */
#define TIMER_CHCTL0_CH0CAPPSC_MASK		BITS(2,3)
#define TIMER_CHCTL0_CH0CAPPSC(x)		(((x) & 0x3U) << 2)
#define TIMER_CHCTL0_CH0CAPFLT_MASK		BITS(4,7)
#define TIMER_CHCTL0_CH0CAPFLT(x)		(((x) & 0xFU) << 4)
#define TIMER_CHCTL0_CH1CAPPSC_MASK		BITS(10,11)
#define TIMER_CHCTL0_CH1CAPPSC(x)		(((x) & 0x3U) << 10)
#define TIMER_CHCTL0_CH1CAPFLT_MASK		BITS(12,15)
#define TIMER_CHCTL0_CH1CAPFLT(x)		(((x) & 0xFU) << 12)


/* TIMER_CHCTL1 */
/* output compare mode */
#define TIMER_CHCTL1_CH2MS_MASK			BITS(0,1)
#define TIMER_CHCTL1_CH2MS(x)			((x) & 0x3U)
#define TIMER_CHCTL1_CH2COMFEN			BIT(2)
#define TIMER_CHCTL1_CH2COMSEN			BIT(3)
#define TIMER_CHCTL1_CH2COMCTL_MASK		BITS(4,6)
#define TIMER_CHCTL1_CH2COMCTL(x)		(((x) & 0x7U) << 4)
#define TIMER_CHCTL1_CH2COMCEN			BIT(7)
#define TIMER_CHCTL1_CH3MS_MASK			BITS(8,9)
#define TIMER_CHCTL1_CH3MS(x)			(((x) & 0x3U) << 8)
#define TIMER_CHCTL1_CH3COMFEN			BIT(10)
#define TIMER_CHCTL1_CH3COMSEN			BIT(11)
#define TIMER_CHCTL1_CH3COMCTL_MASK		BITS(12,14)
#define TIMER_CHCTL1_CH3COMCTL(x)		(((x) & 0x7U) << 12)
#define TIMER_CHCTL1_CH3COMCEN			BIT(15)
/* input capture mode */
#define TIMER_CHCTL1_CH2CAPPSC_MASK		BITS(2,3)
#define TIMER_CHCTL1_CH2CAPPSC(x)		(((x) & 0x3U) << 2)
#define TIMER_CHCTL1_CH2CAPFLT_MASK		BITS(4,7)
#define TIMER_CHCTL1_CH2CAPFLT(x)		(((x) & 0xFU) << 4)
#define TIMER_CHCTL1_CH3CAPPSC_MASK		BITS(10,11)
#define TIMER_CHCTL1_CH3CAPPSC(x)		(((x) & 0x3U) << 10)
#define TIMER_CHCTL1_CH3CAPFLT_MASK		BITS(12,15)
#define TIMER_CHCTL1_CH3CAPFLT(x)		(((x) & 0xFU) << 12)


/* TIMER_CHCTL2 */
#define TIMER_CHCTL2_CH0EN               BIT(0)
#define TIMER_CHCTL2_CH0P                BIT(1)
#define TIMER_CHCTL2_CH0NEN              BIT(2)
#define TIMER_CHCTL2_CH0NP               BIT(3)
#define TIMER_CHCTL2_CH1EN               BIT(4)
#define TIMER_CHCTL2_CH1P                BIT(5)
#define TIMER_CHCTL2_CH1NEN              BIT(6)
#define TIMER_CHCTL2_CH1NP               BIT(7)
#define TIMER_CHCTL2_CH2EN               BIT(8)
#define TIMER_CHCTL2_CH2P                BIT(9)
#define TIMER_CHCTL2_CH2NEN              BIT(10)
#define TIMER_CHCTL2_CH2NP               BIT(11)
#define TIMER_CHCTL2_CH3EN               BIT(12)
#define TIMER_CHCTL2_CH3P                BIT(13)


/* TIMER_CNT */
#define TIMER_CNT_CNT                    BITS(0,15)

/* TIMER_PSC */
#define TIMER_PSC_PSC                    BITS(0,15)

/* TIMER_CAR */
#define TIMER_CAR_CARL                   BITS(0,15)

/* TIMER_CREP */
#define TIMER_CREP_CREP                  BITS(0,7)

/* TIMER_CH0CV */
#define TIMER_CH0CV_CH0VAL               BITS(0,15)

/* TIMER_CH1CV */
#define TIMER_CH1CV_CH1VAL               BITS(0,15)

/* TIMER_CH2CV */
#define TIMER_CH2CV_CH2VAL               BITS(0,15)

/* TIMER_CH3CV */
#define TIMER_CH3CV_CH3VAL               BITS(0,15)

/* TIMER_CCHP */
#define TIMER_CCHP_DTCFG                 BITS(0,7)
#define TIMER_CCHP_PROT                  BITS(8,9)
#define TIMER_CCHP_IOS                   BIT(10)
#define TIMER_CCHP_ROS                   BIT(11)
#define TIMER_CCHP_BRKEN                 BIT(12)
#define TIMER_CCHP_BRKP                  BIT(13)
#define TIMER_CCHP_OAEN                  BIT(14)
#define TIMER_CCHP_POEN                  BIT(15)

/* TIMER_DMACFG */
#define TIMER_DMACFG_DMATA               BITS(0,4)
#define TIMER_DMACFG_DMATC               BITS(8,12)

/* TIMER_DMATB */
#define TIMER_DMATB_DMATB                BITS(0,15)


#define TIMER_COUNTER_UP				((uint16_t)0x0000U)
#define TIMER_COUNTER_DOWN				((uint16_t)TIMER_CTL0_DIR)



typedef enum
{
	TIMER0 = 0x00,
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5,
	TIMER6
}timer_enum;


typedef struct
{
	volatile uint32_t *ctl0;
	volatile uint32_t *ctl1;
	volatile uint32_t *smcfg;
	volatile uint32_t *dmainten;
	volatile uint32_t *intf;
	volatile uint32_t *swevg;
	volatile uint32_t *chctl0;
	volatile uint32_t *chctl1;
	volatile uint32_t *chctl2;
	volatile uint32_t *cnt;
	volatile uint32_t *psc;
	volatile uint32_t *car;
	volatile uint32_t *crep;
	volatile uint32_t *ch0cv;
	volatile uint32_t *ch1cv;
	volatile uint32_t *ch2cv;
	volatile uint32_t *ch3cv;
	volatile uint32_t *cchp;
	volatile uint32_t *dmacfg;
	volatile uint32_t *dmatb;
}timer_reg_struct;

/*
typedef struct
{
	volatile uint32_t *ctl0;
	volatile uint32_t *ctl1;
	volatile uint32_t *smcfg;
	volatile uint32_t *dmainten;
	volatile uint32_t *intf;
	volatile uint32_t *swevg;
	volatile uint32_t *chctl0;
	volatile uint32_t *chctl1;
	volatile uint32_t *chctl2;
	volatile uint32_t *cnt;
	volatile uint32_t *psc;
	volatile uint32_t *car;
	volatile uint32_t *ch0cv;
	volatile uint32_t *ch1cv;
	volatile uint32_t *ch2cv;
	volatile uint32_t *ch3cv;
	volatile uint32_t *dmacfg;
	volatile uint32_t *dmatb;
}timern_reg_struct;
*/

extern uint32_t get_timer_counter(timer_enum timer);
extern void timer_config(timer_enum timer, uint32_t interval);

#endif //TIMER_H
