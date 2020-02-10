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
#include 	"pll.h"


void pll_init(void)
{
	uint32_t val;

	//SYS CLOCK configuration = 96MHz
	val = reg32_read(RCU_CFG0);
	val |= RCU_CFG0_SCS(0x2) | RCU_CFG0_PLLSEL |
		   RCU_CFG0_PLLMF(0x7) | RCU_CFG0_PLLMF4 |		/* PLL*24 */
		   RCU_CFG0_PREDV0_LSB;							/* 4MHz feed into PLL */
	reg32_write(RCU_CFG0, val);
	while((reg32_read(RCU_CFG0) >> 2) & RCU_CFG0_SCS(0x2) != RCU_CFG0_SCS(0x2));

	//HXTAL external crystal enable
	val = reg32_read(RCU_CTL);
	val |= RCU_CTL_HXTALEN;
	reg32_write(RCU_CTL, val);
	while(reg32_read(RCU_CTL) & RCU_CTL_HXTALSTB != RCU_CTL_HXTALSTB);

	
}


