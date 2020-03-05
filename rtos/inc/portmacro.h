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

/*
	Changes from V3.2.3

	+ Modified portENTER_SWITCHING_ISR() to allow use with GCC V4.0.1.

	Changes from V3.2.4

	+ Removed the use of the %0 parameter within the assembler macros and
	  replaced them with hard coded registers.  This will ensure the
	  assembler does not select the link register as the temp register as
	  was occasionally happening previously.

	+ The assembler statements are now included in a single asm block rather
	  than each line having its own asm block.

	Changes from V4.5.0

	+ Removed the portENTER_SWITCHING_ISR() and portEXIT_SWITCHING_ISR() macros
	  and replaced them with portYIELD_FROM_ISR() macro.  Application code
	  should now make use of the portSAVE_CONTEXT() and portRESTORE_CONTEXT()
	  macros as per the V4.5.1 demo code.
*/

#ifndef PORTMACRO_H
#define PORTMACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR		char
#define portFLOAT		float
#define portDOUBLE		double
#define portLONG		long
#define portSHORT		short
#define portSTACK_TYPE	uint32_t
#define portBASE_TYPE	portLONG

typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;

#if( configUSE_16_BIT_TICKS == 1 )
	typedef uint16_t TickType_t;
	#define portMAX_DELAY ( TickType_t ) 0xffff
#else
	typedef uint32_t TickType_t;
	#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif
/*-----------------------------------------------------------*/

/* Architecture specifics. */
#define portSTACK_GROWTH			( -1 )
#define portTICK_PERIOD_MS			( ( TickType_t ) 1000 / configTICK_RATE_HZ )
#define portBYTE_ALIGNMENT			8
#define portNOP()					__asm volatile ( "NOP" )
/*-----------------------------------------------------------*/


/* Scheduler utilities. */

/*
 * portRESTORE_CONTEXT, portRESTORE_CONTEXT, portENTER_SWITCHING_ISR
 * and portEXIT_SWITCHING_ISR can only be called from ARM mode, but
 * are included here for efficiency.  An attempt to call one from
 * THUMB mode code will result in a compile time error.
 */
#define portRESTORE_CONTEXT()											\
{																		\
extern volatile void * volatile pxCurrentTCB;							\
extern volatile uint32_t ulCriticalNesting;								\
																		\
	/* Set the LR to the task stack. */									\
	asm volatile (														\
	/* x6 points to Task's Stack Top */									\
	"la			x5, pxCurrentTCB								\n\t"	\
	"lw			x5, (x5)										\n\t"	\
	"lw			x6, (x5)										\n\t"	\
																		\
	/* The critical nesting depth is the first item on the stack. */	\
	/* Load it into the ulCriticalNesting variable. */					\
	"la			x5, ulCriticalNesting							\n\t"	\
	"lw			x7, (x6)										\n\t"	\
	"sw			x7, (x5)										\n\t"	\
																		\
	/* Get the mstatus from the stack. */								\
	"lw			x7, 1*4(x6)										\n\t"	\
	"csrw		mstatus, x7										\n\t"	\
																		\
	/* Restore all registers from the task. */							\
	"lw			x31, 32*4(x6)									\n\t"	\
	"lw			x30, 31*4(x6)									\n\t"	\
	"lw			x29, 30*4(x6)									\n\t"	\
	"lw			x28, 29*4(x6)									\n\t"	\
	"lw			x27, 28*4(x6)									\n\t"	\
	"lw			x26, 27*4(x6)									\n\t"	\
	"lw			x25, 26*4(x6)									\n\t"	\
	"lw			x24, 25*4(x6)									\n\t"	\
	"lw			x23, 24*4(x6)									\n\t"	\
	"lw			x22, 23*4(x6)									\n\t"	\
	"lw			x21, 22*4(x6)									\n\t"	\
	"lw			x20, 21*4(x6)									\n\t"	\
	"lw			x19, 20*4(x6)									\n\t"	\
	"lw			x18, 19*4(x6)									\n\t"	\
	"lw			x17, 18*4(x6)									\n\t"	\
	"lw			x16, 17*4(x6)									\n\t"	\
	"lw			x15, 16*4(x6)									\n\t"	\
	"lw			x14, 15*4(x6)									\n\t"	\
	"lw			x13, 14*4(x6)									\n\t"	\
	"lw			x12, 13*4(x6)									\n\t"	\
	"lw			x11, 12*4(x6)									\n\t"	\
	"lw			x10, 11*4(x6)									\n\t"	\
	"lw			x9,  10*4(x6)									\n\t"	\
	"lw			x8,	  9*4(x6)									\n\t"	\
	"lw			x7,	  8*4(x6)									\n\t"	\
	"lw			x5,	  6*4(x6)									\n\t"	\
	"lw			x4,	  5*4(x6)									\n\t"	\
	"lw			x3,	  4*4(x6)									\n\t"	\
	"lw			x1,	  3*4(x6)									\n\t"	\
																		\
	/* get return address from stack */									\
	"lw			x2,	 33*4(x6)									\n\t"	\
	"csrw		mepc, x2										\n\t"	\
																		\
	/* put sp pointer into mscratch */									\
	"addi		x2, x6, 33*4									\n\t"	\
	"csrw		mscratch, x2									\n\t"	\
																		\
	"lw			x6, 7*4(x6)										\n\t"	\
																		\
	/* Return to Original Point */										\
	"mret														\n\t"	\
	);																	\
	( void ) ulCriticalNesting;											\
	( void ) pxCurrentTCB;												\
}
/*-----------------------------------------------------------*/

#define portSAVE_CONTEXT()												\
{																		\
extern volatile void * volatile pxCurrentTCB;							\
extern volatile uint32_t ulCriticalNesting;								\
																		\
	/* Push R0 as we are going to use the register. */					\
	asm volatile (														\
	/* Spare the space on stack */										\
	"addi		sp, sp, -33*4									\n\t"	\
																		\
	/* Save all registers into Stack */									\
	"sw			x31, 32*4(sp)									\n\t"	\
	"sw			x30, 31*4(sp)									\n\t"	\
	"sw			x29, 30*4(sp)									\n\t"	\
	"sw			x28, 29*4(sp)									\n\t"	\
	"sw			x27, 28*4(sp)									\n\t"	\
	"sw			x26, 27*4(sp)									\n\t"	\
	"sw			x25, 26*4(sp)									\n\t"	\
	"sw			x24, 25*4(sp)									\n\t"	\
	"sw			x23, 24*4(sp)									\n\t"	\
	"sw			x22, 23*4(sp)									\n\t"	\
	"sw			x21, 22*4(sp)									\n\t"	\
	"sw			x20, 21*4(sp)									\n\t"	\
	"sw			x19, 20*4(sp)									\n\t"	\
	"sw			x18, 19*4(sp)									\n\t"	\
	"sw			x17, 18*4(sp)									\n\t"	\
	"sw			x16, 17*4(sp)									\n\t"	\
	"sw			x15, 16*4(sp)									\n\t"	\
	"sw			x14, 15*4(sp)									\n\t"	\
	"sw			x13, 14*4(sp)									\n\t"	\
	"sw			x12, 13*4(sp)									\n\t"	\
	"sw			x11, 12*4(sp)									\n\t"	\
	"sw			x10, 11*4(sp)									\n\t"	\
	"sw			x9,  10*4(sp)									\n\t"	\
	"sw			x8,	  9*4(sp)									\n\t"	\
	"sw			x7,	  8*4(sp)									\n\t"	\
	"sw			x6,	  7*4(sp)									\n\t"	\
	"sw			x5,	  6*4(sp)									\n\t"	\
	"sw			x4,	  5*4(sp)									\n\t"	\
	"sw			x3,	  4*4(sp)									\n\t"	\
	"sw			x1,	  3*4(sp)									\n\t"	\
																		\
	/* Push return address into stack */								\
	"csrr		x5, mepc										\n\t"	\
	"addi		x5, x5, 4										\n\t"	\
	"sw			x5, 33*4(sp)									\n\t"	\
																		\
	/* Push parameter into stack */										\
	"sw			x0, 2*4(sp)										\n\t"	\
																		\
	/* Push mstatus into stack */										\
	"csrr		x5, mstatus										\n\t"	\
	"sw			x5, 1*4(sp)										\n\t"	\
																		\
	/* Push 'ulCriticalNesting' into Stack */							\
	"la			x5, ulCriticalNesting							\n\t"	\
	"lw			x5, (x5)										\n\t"	\
	"sw			x5, (sp)										\n\t"	\
																		\
	/* Store new top stack of task into 'pxCurrentTCB' */				\
	"la			x5, pxCurrentTCB								\n\t"	\
	"lw			x5, (x5)										\n\t"	\
	"sw			sp, (x5)										\n\t"	\
																		\
	);																	\
	( void ) ulCriticalNesting;											\
	( void ) pxCurrentTCB;												\
}

#define portYIELD_FROM_ISR()		vTaskSwitchContext()
#define portYIELD()					asm volatile ( "ecall" )
/*-----------------------------------------------------------*/


/* Critical section management. */

/*
 * The interrupt management utilities can only be called from ARM mode.  When
 * THUMB_INTERWORK is defined the utilities are defined as functions in
 * portISR.c to ensure a switch to ARM mode.  When THUMB_INTERWORK is not
 * defined then the utilities are defined as macros here - as per other ports.
 */

//#ifdef THUMB_INTERWORK

	//extern void vPortDisableInterruptsFromThumb( void ) __attribute__ ((naked));
	//extern void vPortEnableInterruptsFromThumb( void ) __attribute__ ((naked));

#define portDISABLE_INTERRUPTS()	//vPortDisableInterruptsFromThumb()
#define portENABLE_INTERRUPTS()		//vPortEnableInterruptsFromThumb()

//#else

	
#if 0
	#define portDISABLE_INTERRUPTS()											\
		__asm volatile (														\
			"STMDB	SP!, {R0}		\n\t"	/* Push R0.						*/	\
			"MRS	R0, CPSR		\n\t"	/* Get CPSR.					*/	\
			"ORR	R0, R0, #0xC0	\n\t"	/* Disable IRQ, FIQ.			*/	\
			"MSR	CPSR, R0		\n\t"	/* Write back modified value.	*/	\
			"LDMIA	SP!, {R0}			" )	/* Pop R0.						*/

	#define portENABLE_INTERRUPTS()												\
		__asm volatile (														\
			"STMDB	SP!, {R0}		\n\t"	/* Push R0.						*/	\
			"MRS	R0, CPSR		\n\t"	/* Get CPSR.					*/	\
			"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.				*/	\
			"MSR	CPSR, R0		\n\t"	/* Write back modified value.	*/	\
			"LDMIA	SP!, {R0}			" )	/* Pop R0.						*/
#endif

//#endif /* THUMB_INTERWORK */

extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );

#define portENTER_CRITICAL()		vPortEnterCritical();
#define portEXIT_CRITICAL()			vPortExitCritical();
/*-----------------------------------------------------------*/

/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */

