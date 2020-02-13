////////////////////////////////////////////////////////////
// this file is used for s3c2440 timer configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-12
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include 	"devRegs.h"
#include	"regs_opt.h"
#include	"interrupt.h"
#include	"timer.h"
#include 	"rcu.h"


static timer_reg_struct timer_regs[] =
{
	//TIMER0
	{
		TIMER0_CTL0,
		TIMER0_CTL1,
		TIMER0_SMCFG,
		TIMER0_DMAINTEN,
		TIMER0_INTF,
		TIMER0_SWEVG,
		TIMER0_CHCTL0,
		TIMER0_CHCTL1,
		TIMER0_CHCTL2,
		TIMER0_CNT,
		TIMER0_PSC,
		TIMER0_CAR,
		TIMER0_CREP,
		TIMER0_CH0CV,
		TIMER0_CH1CV,
		TIMER0_CH2CV,
		TIMER0_CH3CV,
		TIMER0_CCHP,
		TIMER0_DMACFG,
		TIMER0_DMATB
	},
	//TIMER1
	{
		TIMER_CTL0(1),
		TIMER_CTL1(1),
		TIMER_SMCFG(1),
		TIMER_DMAINTEN(1),
		TIMER_INTF(1),
		TIMER_SWEVG(1),
		TIMER_CHCTL0(1),
		TIMER_CHCTL1(1),
		TIMER_CHCTL2(1),
		TIMER_CNT(1),
		TIMER_PSC(1),
		TIMER_CAR(1),
		NULL,
		TIMER_CH0CV(1),
		TIMER_CH1CV(1),
		TIMER_CH2CV(1),
		TIMER_CH3CV(1),
		NULL,
		TIMER_DMACFG(1),
		TIMER_DMATB(1)
	},
	//TIMER2
	{
		TIMER_CTL0(2),
		TIMER_CTL1(2),
		TIMER_SMCFG(2),
		TIMER_DMAINTEN(2),
		TIMER_INTF(2),
		TIMER_SWEVG(2),
		TIMER_CHCTL0(2),
		TIMER_CHCTL1(2),
		TIMER_CHCTL2(2),
		TIMER_CNT(2),
		TIMER_PSC(2),
		TIMER_CAR(2),
		NULL,
		TIMER_CH0CV(2),
		TIMER_CH1CV(2),
		TIMER_CH2CV(2),
		TIMER_CH3CV(2),
		NULL,
		TIMER_DMACFG(2),
		TIMER_DMATB(2)
	},
	//TIMER3
	{
		TIMER_CTL0(3),
		TIMER_CTL1(3),
		TIMER_SMCFG(3),
		TIMER_DMAINTEN(3),
		TIMER_INTF(3),
		TIMER_SWEVG(3),
		TIMER_CHCTL0(3),
		TIMER_CHCTL1(3),
		TIMER_CHCTL2(3),
		TIMER_CNT(3),
		TIMER_PSC(3),
		TIMER_CAR(3),
		NULL,
		TIMER_CH0CV(3),
		TIMER_CH1CV(3),
		TIMER_CH2CV(3),
		TIMER_CH3CV(3),
		NULL,
		TIMER_DMACFG(3),
		TIMER_DMATB(3)
	},
	//TIMER4
	{
		TIMER_CTL0(4),
		TIMER_CTL1(4),
		TIMER_SMCFG(4),
		TIMER_DMAINTEN(4),
		TIMER_INTF(4),
		TIMER_SWEVG(4),
		TIMER_CHCTL0(4),
		TIMER_CHCTL1(4),
		TIMER_CHCTL2(4),
		TIMER_CNT(4),
		TIMER_PSC(4),
		TIMER_CAR(4),
		NULL,
		TIMER_CH0CV(4),
		TIMER_CH1CV(4),
		TIMER_CH2CV(4),
		TIMER_CH3CV(4),
		NULL,
		TIMER_DMACFG(4),
		TIMER_DMATB(4)
	},
	//TIMER5
	{
		TIMER_CTL0(5),
		TIMER_CTL1(5),
		TIMER_SMCFG(5),
		TIMER_DMAINTEN(5),
		TIMER_INTF(5),
		TIMER_SWEVG(5),
		TIMER_CHCTL0(5),
		TIMER_CHCTL1(5),
		TIMER_CHCTL2(5),
		TIMER_CNT(5),
		TIMER_PSC(5),
		TIMER_CAR(5),
		NULL,
		TIMER_CH0CV(5),
		TIMER_CH1CV(5),
		TIMER_CH2CV(5),
		TIMER_CH3CV(5),
		NULL,
		TIMER_DMACFG(5),
		TIMER_DMATB(5)
	},
	//TIMER6
	{
		TIMER_CTL0(6),
		TIMER_CTL1(6),
		TIMER_SMCFG(6),
		TIMER_DMAINTEN(6),
		TIMER_INTF(6),
		TIMER_SWEVG(6),
		TIMER_CHCTL0(6),
		TIMER_CHCTL1(6),
		TIMER_CHCTL2(6),
		TIMER_CNT(6),
		TIMER_PSC(6),
		TIMER_CAR(6),
		NULL,
		TIMER_CH0CV(6),
		TIMER_CH1CV(6),
		TIMER_CH2CV(6),
		TIMER_CH3CV(6),
		NULL,
		TIMER_DMACFG(6),
		TIMER_DMATB(6)
	}
};

void TIMER1_IRQHandler(void)
{
	return;
}

static void timer_init(timer_enum timer, uint32_t interval_ms)
{
	timer_reg_struct *ptimer;

	switch(timer)
	{
	case TIMER0:	
		break;

	case TIMER1:
	case TIMER2:
	case TIMER3:
	case TIMER4:
		ptimer = &timer_regs[timer];
		HWREG(ptimer->psc)  = 9599;		//sys_clk = CK_TIMER = 96MHz -> PSC_CLK = 10KHz
		HWREG(ptimer->ctl0) &= ~(TIMER_CTL0_DIR | TIMER_CTL0_CAM_MASK);
		HWREG(ptimer->ctl0) |= TIMER_CTL0_CAM(0) | TIMER_COUNTER_UP;
		HWREG(ptimer->car)   = (uint16_t)10;	//10KHz freq will cause 1000Hz int event

		//reset CKDIV bit
		HWREG(ptimer->ctl0) &= ~(TIMER_CTL0_CKDIV_MASK);
		HWREG(ptimer->ctl0) |= TIMER_CTL0_CKDIV(0);

		//enable interrupt
		HWREG(ptimer->dmainten) |= TIMER_DMAINTEN_UPIE;

		//enable timer
		HWREG(ptimer->ctl0) |= TIMER_CTL0_CEN;
		break;

	case TIMER5:
	case TIMER6:
		break;
	default:
		break;
	}
}


static void timer_deinit(timer_enum timer)
{
    switch(timer)
	{
    case TIMER0:
        /* reset TIMER0 */
        perip_reset_enable(RCU_TIMER0RST);
        perip_reset_disable(RCU_TIMER0RST);
        break;

    case TIMER1:
        /* reset TIMER1 */
        perip_reset_enable(RCU_TIMER1RST);
        perip_reset_disable(RCU_TIMER1RST);
        break;

    case TIMER2:
        /* reset TIMER2 */
        perip_reset_enable(RCU_TIMER2RST);
        perip_reset_disable(RCU_TIMER2RST);
        break;

    case TIMER3:
        /* reset TIMER3 */
        perip_reset_enable(RCU_TIMER3RST);
        perip_reset_disable(RCU_TIMER3RST);
        break;

    case TIMER4:
        /* reset TIMER4 */
        perip_reset_enable(RCU_TIMER4RST);
        perip_reset_disable(RCU_TIMER4RST);
        break;

    case TIMER5:
        /* reset TIMER5 */
        perip_reset_enable(RCU_TIMER5RST);
        perip_reset_disable(RCU_TIMER5RST);
        break;

    case TIMER6:
        /* reset TIMER6 */
        perip_reset_enable(RCU_TIMER6RST);
        perip_reset_disable(RCU_TIMER6RST);
        break;

    default:
        break;
    }
}


static void timer_clk_enable(timer_enum timer)
{
	switch(timer)
	{
	case TIMER0:
		perip_clk_enable(RCU_TIMER0EN);
		break;
	case TIMER1:
		perip_clk_enable(RCU_TIMER1EN);
		break;
	case TIMER2:
		perip_clk_enable(RCU_TIMER2EN);
		break;
	case TIMER3:
		perip_clk_enable(RCU_TIMER3EN);
		break;
	case TIMER4:
		perip_clk_enable(RCU_TIMER4EN);
		break;
	case TIMER5:
		perip_clk_enable(RCU_TIMER5EN);
		break;
	case TIMER6:
		perip_clk_enable(RCU_TIMER6EN);
		break;
	default:
		break;
	}
}

void timer_config(timer_enum timer, uint32_t interval)
{
	timer_clk_enable(timer);
	timer_deinit(timer);
	timer_init(timer, interval);
}

uint32_t get_timer_counter(timer_enum timer)
{
	timer_reg_struct *ptimer = &timer_regs[timer];

	return HWREG(ptimer->cnt);
}


