////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2019-10-13
//
#ifndef TIMER_H
#define TIMER_H

extern uint8_t	irq_register(BaseType_t (*func)(void), uint8_t int_offset);
extern void do_irq(void);

#endif //TIMER_H
