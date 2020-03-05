/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */


/*-----------------------------------------------------------
 * Implementation of functions defined in portable.h for the ARM7 port.
 *
 * Components that can be compiled to either ARM or THUMB mode are
 * contained in this file.  The ISR routines, which can only be compiled
 * to ARM mode are contained in portISR.c.
 *----------------------------------------------------------*/

/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "devRegs.h"
#include "timer.h"

/* Processor constants. */
//#include "AT91SAM7X256.h"

/* Constants required to setup the task context. */
#define portINITIAL_MSTATUS				( ( StackType_t ) ((0x1 << 3) | (0x1 << 7) | (0x3 << 11)) ) /* User mode, Interrupts enabled. */
#define portTHUMB_MODE_BIT				( ( StackType_t ) 0x20 )
#define portINSTRUCTION_SIZE			( ( StackType_t ) 4 )
#define portNO_CRITICAL_SECTION_NESTING	( ( StackType_t ) 0 )

/* Constants required to setup the tick ISR. */
#define portENABLE_TIMER			( ( uint8_t ) 0x01 )
#define portPRESCALE_VALUE			0x00
#define portINTERRUPT_ON_MATCH		( ( uint32_t ) 0x01 )
#define portRESET_COUNT_ON_MATCH	( ( uint32_t ) 0x02 )

/* Constants required to setup the PIT. */
#define portPIT_CLOCK_DIVISOR			( ( uint32_t ) 16 )
#define portPIT_COUNTER_VALUE			( ( ( configCPU_CLOCK_HZ / portPIT_CLOCK_DIVISOR ) / 1000UL ) * portTICK_PERIOD_MS )

#define portINT_LEVEL_SENSITIVE  0
#define portPIT_ENABLE      	( ( uint16_t ) 0x1 << 24 )
#define portPIT_INT_ENABLE     	( ( uint16_t ) 0x1 << 25 )
/*-----------------------------------------------------------*/

/* Setup the timer to generate the tick interrupts. */
static void prvSetupTimerInterrupt( void );

/* 
 * The scheduler can only be started from ARM mode, so 
 * vPortISRStartFirstSTask() is defined in portISR.c. 
 */
extern void vPortISRStartFirstTask( void );

/*-----------------------------------------------------------*/

/* 
 * Initialise the stack of a task to look exactly as if a call to 
 * portSAVE_CONTEXT had been called.
 *
 * See header file for description. 
 */
StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
{
StackType_t *pxOriginalTOS;

	pxOriginalTOS = pxTopOfStack;

	/* To ensure asserts in tasks.c don't fail, although in this case the assert
	is not really required. */
	pxTopOfStack--;

	/* Setup the initial stack of the task.  The stack is set exactly as 
	expected by the portRESTORE_CONTEXT() macro. */

	/* First on the stack is the return address - which in this case is the
	start of the task.  The offset is added to make the return address appear
	as it would within an IRQ ISR. */
	*pxTopOfStack = ( StackType_t ) pxCode;		/* Return Address */
	pxTopOfStack--;

	*pxTopOfStack = ( StackType_t ) 0x31313131;	/* x31 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x30303030; /* x30 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x29292929;	/* x29 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x28282828;	/* x28 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x27272727;	/* x27 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x26262626;	/* x26 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x25252525;	/* x25 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x24242424;	/* x24 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x23232323;	/* x23 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x22222222;	/* x22 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x21212121;	/* x21 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x20202020;	/* x20 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x19191919;	/* x19 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x18181818;	/* x18 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x17171717;	/* x17 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x16161616;	/* x16 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x15151515;	/* x15 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x14141414;	/* x14 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x13131313;	/* x13 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x12121212;	/* x12 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x11111111;	/* x11 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x10101010;	/* x10 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x09090909;	/* x9 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x08080808;	/* x8 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x07070707;	/* x7 */
	pxTopOfStack--;	
	*pxTopOfStack = ( StackType_t ) 0x06060606;	/* x6 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x05050505;	/* x5 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x04040404;	/* x4 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x03030303;	/* x3 */
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0x01010101;	/* x1 */
	pxTopOfStack--;

	/* When the task starts is will expect to find the function parameter in
	a2. */
	*pxTopOfStack = ( StackType_t ) pvParameters; /* a2 */
	pxTopOfStack--;

	/* The last thing onto the stack is the status register, which is set for
	system mode, with interrupts enabled. */
	*pxTopOfStack = ( StackType_t ) portINITIAL_MSTATUS;
	pxTopOfStack--;

	/* Some optimisation levels use the stack differently to others.  This 
	means the interrupt flags cannot always be stored on the stack and will
	instead be stored in a variable, which is then saved as part of the
	tasks context. */
	*pxTopOfStack = portNO_CRITICAL_SECTION_NESTING;

	return pxTopOfStack;
}
/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler( void )
{
	/* Start the timer that generates the tick ISR.  Interrupts are disabled
	here already. */
	prvSetupTimerInterrupt();

	/* Start the first task. */
	vPortISRStartFirstTask();	

	/* Should not get here! */
	return 0;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
	/* It is unlikely that the ARM port will require this function as there
	is nothing to return to.  */
}
/*-----------------------------------------------------------*/

/*
 * Setup the timer 0 to generate the tick interrupts at the required frequency.
 */
static void prvSetupTimerInterrupt( void )
{
	timer_config(TIMER1, 10);

#if 0
AT91PS_PITC pxPIT = AT91C_BASE_PITC;

	/* Setup the AIC for PIT interrupts.  The interrupt routine chosen depends
	on whether the preemptive or cooperative scheduler is being used. */
	#if configUSE_PREEMPTION == 0

		extern void ( vNonPreemptiveTick ) ( void );
		AT91F_AIC_ConfigureIt( AT91C_ID_SYS, AT91C_AIC_PRIOR_HIGHEST, portINT_LEVEL_SENSITIVE, ( void (*)(void) ) vNonPreemptiveTick );

	#else
		
		extern void ( vPreemptiveTick )( void );
		AT91F_AIC_ConfigureIt( AT91C_ID_SYS, AT91C_AIC_PRIOR_HIGHEST, portINT_LEVEL_SENSITIVE, ( void (*)(void) ) vPreemptiveTick );

	#endif

	/* Configure the PIT period. */
	pxPIT->PITC_PIMR = portPIT_ENABLE | portPIT_INT_ENABLE | portPIT_COUNTER_VALUE;

	/* Enable the interrupt.  Global interrupts are disables at this point so 
	this is safe. */
    AT91C_BASE_AIC->AIC_IECR = 0x1 << AT91C_ID_SYS;
#endif
}
/*-----------------------------------------------------------*/



