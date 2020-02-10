////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-09
//
#ifndef REGS_OP_H
#define REGS_OP_H

static inline uint32_t reg32_read(uint32_t reg)
{
	return *((volatile uint32_t *)reg);
}

static inline void reg32_write(uint32_t reg, uint32_t val)
{
	*((volatile uint32_t *)reg) = val;
}

static inline void reg32_update_bits(uint32_t reg, uint32_t mask, uint32_t val)
{
	reg32_write(reg, reg32_read(reg) & (~mask) | (val & mask));
}

static inline uint16_t reg16_read(uint32_t reg)
{
	return *((volatile uint16_t *)reg);
}

static inline void reg16_write(uint32_t reg, uint16_t val)
{
	*((volatile uint16_t *)reg) = val;
}

#endif //REGS_OP_H