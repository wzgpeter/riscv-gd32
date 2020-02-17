////////////////////////////////////////////////////////////
// this file is used for RISCV GD32VF103 PLL configuration
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-09
//

#include 	"FreeRTOS.h"
#include 	"task.h"
#include 	"regs_opt.h"
#include 	"devRegs.h"
#include 	"rcu.h"
#include	"interrupt.h"

static rcu_reg_cfg rcu_reg = 
{
	RCU_CTL,
	RCU_CFG0,
	RCU_INT,
	RCU_APB2RST,
	RCU_APB1RST,
	RCU_AHBEN,
	RCU_APB2EN,
	RCU_APB1EN,
	RCU_BDCTL,
	RCU_RSTSCK,
	RCU_AHBRST,
	RCU_CFG1,
	RCU_DSV
};


void rcu_init(void)
{
	uint32_t val;

	//enable HXTAL and wait stable
	HWREG(rcu_reg.ctl) |= RCU_CTL_HXTALEN;
	while(HWREG(rcu_reg.ctl) & RCU_CTL_HXTALSTB != RCU_CTL_HXTALSTB);

	HWREG(rcu_reg.cfg0) |= RCU_CFG0_AHBPSC(0);		//CK_AHB=CK_SYS
	HWREG(rcu_reg.cfg0) |= RCU_CFG0_APB2PSC(0);		//CK_APB2=CK_AHB
	HWREG(rcu_reg.cfg0) |= RCU_CFG0_APB1PSC(0);		//CK_APB1=CH_AHB

	//HXTAL=8MHz; SYS-CLK = 96MHz
	HWREG(rcu_reg.cfg0) &= ~(RCU_CFG0_MASK_PLLMF | RCU_CFG0_MASK_PLLMF4);	//clear the bits
	HWREG(rcu_reg.cfg0) |= RCU_CFG0_PLLMF(0x7) | RCU_CFG0_PLLMF4;			//PLL*24

	HWREG(rcu_reg.cfg1) &= ~(RCU_CFG1_PREDV0SEL | RCU_CFG1_MASK_PREDV0 | RCU_CFG1_MASK_PREDV1 | RCU_CFG1_MASK_PLL1MF);	//clear the bits
	HWREG(rcu_reg.cfg1) |= RCU_CFG1_PREDV0(1);								//HXTAL -> PREDV0; PREDV0 = HXTAL/2

	//enable PLL and wait stable
	HWREG(rcu_reg.ctl) |= RCU_CTL_PLLEN;
	while(HWREG(rcu_reg.ctl) & RCU_CTL_PLL1STB != RCU_CTL_PLL1STB);

	//set PLL as system clock and wait stable
	HWREG(rcu_reg.cfg0) &= ~RCU_CFG0_MASK_SCS;				//clear SCS bits
	HWREG(rcu_reg.cfg0) |= RCU_CFG0_SCS(0x2);				//CK_PLL as CK_SYS
	while(HWREG(rcu_reg.cfg0) & RCU_CFG0_SCSS(0x2) != RCU_CFG0_SCSS(0x2));
}

void clkout_select(clkout_src_enum clk_src)
{
	HWREG(rcu_reg.cfg0) |= RCU_CFG0_CKOUT0SEL(clk_src);
}


void perip_reset_enable(perip_reset_enum perip)
{
	RCU_REG(perip) |= BIT(REG_POS(perip));
}

void perip_reset_disable(perip_reset_enum perip)
{
	RCU_REG(perip) &= ~(BIT(REG_POS(perip)));
}


void perip_clk_enable(perip_clk_enable_enum perip)
{
	RCU_REG(perip) |= BIT(REG_POS(perip));
}

void perip_clk_disable(perip_clk_enable_enum perip)
{
	RCU_REG(perip) &= ~(BIT(REG_POS(perip)));
}

void _system_init(void)
{
	rcu_init();
	eclic_init(ECLIC_NUM_INTERRUPTS);
}

