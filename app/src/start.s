####################################################################
# This file is based on GD32VF103 platform.
#
# Changed Data: 2020-02-09
#
####################################################################

	.section .init
	
    .weak  eclic_sft_handler
    .weak  eclic_tmr_handler
    .weak  eclic_bwei_handler
    .weak  eclic_pmovi_handler
    .weak  WWDGT_IRQHandler
    .weak  LVD_IRQHandler
    .weak  TAMPER_IRQHandler
    .weak  RTC_IRQHandler
    .weak  FMC_IRQHandler
    .weak  RCU_IRQHandler
    .weak  EXTI0_IRQHandler
    .weak  EXTI1_IRQHandler
    .weak  EXTI2_IRQHandler
    .weak  EXTI3_IRQHandler
    .weak  EXTI4_IRQHandler
    .weak  DMA0_Channel0_IRQHandler
    .weak  DMA0_Channel1_IRQHandler
    .weak  DMA0_Channel2_IRQHandler
    .weak  DMA0_Channel3_IRQHandler
    .weak  DMA0_Channel4_IRQHandler
    .weak  DMA0_Channel5_IRQHandler
    .weak  DMA0_Channel6_IRQHandler
    .weak  ADC0_1_IRQHandler
    .weak  CAN0_TX_IRQHandler
    .weak  CAN0_RX0_IRQHandler
    .weak  CAN0_RX1_IRQHandler
    .weak  CAN0_EWMC_IRQHandler
    .weak  EXTI5_9_IRQHandler
    .weak  TIMER0_BRK_IRQHandler
    .weak  TIMER0_UP_IRQHandler
    .weak  TIMER0_TRG_CMT_IRQHandler
    .weak  TIMER0_Channel_IRQHandler
    .weak  TIMER1_IRQHandler
    .weak  TIMER2_IRQHandler
    .weak  TIMER3_IRQHandler
    .weak  I2C0_EV_IRQHandler
    .weak  I2C0_ER_IRQHandler
    .weak  I2C1_EV_IRQHandler
    .weak  I2C1_ER_IRQHandler
    .weak  SPI0_IRQHandler
    .weak  SPI1_IRQHandler
    .weak  USART0_IRQHandler
    .weak  USART1_IRQHandler
    .weak  USART2_IRQHandler
    .weak  EXTI10_15_IRQHandler
    .weak  RTC_Alarm_IRQHandler
    .weak  USBFS_WKUP_IRQHandler
    .weak  EXMC_IRQHandler
    .weak  TIMER4_IRQHandler
    .weak  SPI2_IRQHandler
    .weak  UART3_IRQHandler
    .weak  UART4_IRQHandler
    .weak  TIMER5_IRQHandler
    .weak  TIMER6_IRQHandler
    .weak  DMA1_Channel0_IRQHandler
    .weak  DMA1_Channel1_IRQHandler
    .weak  DMA1_Channel2_IRQHandler
    .weak  DMA1_Channel3_IRQHandler
    .weak  DMA1_Channel4_IRQHandler
    .weak  CAN1_TX_IRQHandler
    .weak  CAN1_RX0_IRQHandler
    .weak  CAN1_RX1_IRQHandler
    .weak  CAN1_EWMC_IRQHandler
    .weak  USBFS_IRQHandler


#######################################################
## Interrupt Vector Table
##
vector_base:
    j _start
    .align    2
    .word     0
    .word     0
    .word     eclic_sft_handler
    .word     0
    .word     0
    .word  	  0
    .word  	  eclic_tmr_handler
    .word  	  0
    .word  	  0
    .word  	  0
    .word  	  0
    .word  	  0
    .word  	  0
    .word  	  0
    .word 	  0
    .word  	  0
    .word  	  eclic_bwei_handler
    .word  	  eclic_pmovi_handler
    .word  	  WWDGT_IRQHandler
	.word     LVD_IRQHandler
	.word     TAMPER_IRQHandler
	.word     RTC_IRQHandler
	.word     FMC_IRQHandler
	.word     RCU_IRQHandler
	.word     EXTI0_IRQHandler
	.word     EXTI1_IRQHandler
	.word     EXTI2_IRQHandler
	.word     EXTI3_IRQHandler
	.word     EXTI4_IRQHandler
	.word     DMA0_Channel0_IRQHandler
	.word     DMA0_Channel1_IRQHandler
	.word     DMA0_Channel2_IRQHandler
	.word     DMA0_Channel3_IRQHandler
	.word     DMA0_Channel4_IRQHandler
	.word     DMA0_Channel5_IRQHandler
	.word     DMA0_Channel6_IRQHandler
	.word     ADC0_1_IRQHandler
	.word     CAN0_TX_IRQHandler
	.word     CAN0_RX0_IRQHandler
	.word     CAN0_RX1_IRQHandler
	.word     CAN0_EWMC_IRQHandler
	.word     EXTI5_9_IRQHandler
	.word     TIMER0_BRK_IRQHandler
	.word     TIMER0_UP_IRQHandler
	.word     TIMER0_TRG_CMT_IRQHandler
	.word     TIMER0_Channel_IRQHandler
	.word     TIMER1_IRQHandler
	.word     TIMER2_IRQHandler
	.word     TIMER3_IRQHandler
	.word     I2C0_EV_IRQHandler
	.word     I2C0_ER_IRQHandler
	.word     I2C1_EV_IRQHandler
	.word     I2C1_ER_IRQHandler
	.word     SPI0_IRQHandler
	.word     SPI1_IRQHandler
	.word     USART0_IRQHandler
	.word     USART1_IRQHandler
	.word     USART2_IRQHandler
	.word     EXTI10_15_IRQHandler
	.word     RTC_Alarm_IRQHandler
	.word     USBFS_WKUP_IRQHandler
    .word     0
    .word     0
    .word     0
    .word     0
	.word     0
	.word     EXMC_IRQHandler
	.word     0
	.word     TIMER4_IRQHandler
	.word     SPI2_IRQHandler
	.word     UART3_IRQHandler
	.word     UART4_IRQHandler
	.word     TIMER5_IRQHandler
	.word     TIMER6_IRQHandler
	.word     DMA1_Channel0_IRQHandler
	.word     DMA1_Channel1_IRQHandler
	.word     DMA1_Channel2_IRQHandler
	.word     DMA1_Channel3_IRQHandler
	.word     DMA1_Channel4_IRQHandler
    .word     0
    .word     0
	.word     CAN1_TX_IRQHandler
	.word     CAN1_RX0_IRQHandler
	.word     CAN1_RX1_IRQHandler
	.word     CAN1_EWMC_IRQHandler
	.word     USBFS_IRQHandler


##############################################################
## define the csr registers
##############################################################

#	.equ	mtvec,			0x305
	.equ	mtvt,			0x307
	.equ	mcountinhibit,	0x320
	.equ	mmisc_ctl,		0x7d0
	.equ	msubm,			0x7c4
	.equ	mtvt2,			0x7ec
	.equ	jalmnxti,		0x7ed



##################################################
## Bit for MSTATUS register

	.equ	MSTATUS_UIE,    0x00000001
	.equ	MSTATUS_SIE,    0x00000002
	.equ	MSTATUS_HIE,    0x00000004
	.equ	MSTATUS_MIE,    0x00000008
	.equ	MSTATUS_UPIE,   0x00000010
	.equ	MSTATUS_SPIE,   0x00000020
	.equ	MSTATUS_HPIE,   0x00000040
	.equ	MSTATUS_MPIE,   0x00000080
	.equ	MSTATUS_SPP,    0x00000100
	.equ	MSTATUS_MPP,    0x00001800
	.equ	MSTATUS_FS,     0x00006000
	.equ	MSTATUS_XS,     0x00018000
	.equ	MSTATUS_MPRV,   0x00020000
	.equ	MSTATUS_PUM,    0x00040000
	.equ	MSTATUS_MXR,    0x00080000
	.equ	MSTATUS_VM,     0x1F000000
	.equ	MSTATUS32_SD,   0x80000000



	.globl	_start
	.type	_start, @function

_start:

	li		t0, 0x00000008		# MSTATUS_MIE
	csrc 	mstatus, t0

	## Jump to logical address first to ensure correct operation of RAM region
    la		a0,	_start
    li		a1,	1
	slli	a1,	a1, 29
    bleu	a1, a0, _start0800
    srli	a1,	a1, 2
    bleu	a1, a0, _start0800
    la		a0,	_start0800
    add		a0, a0, a1
	jr      a0

_start0800:

    ## Set the the NMI base to share with mtvec by setting CSR_MMISC_CTL
    li 		t0, 0x200
    csrs 	mmisc_ctl, t0

	## Intial the mtvt
    la 		t0, vector_base
    csrw 	mtvt, t0

	## Intial the mtvt2 and enable it
    la 		t0, irq_entry
    csrw 	mtvt2, t0
    csrs 	mtvt2, 0x1

    ## Intial the CSR MTVEC for the Trap ane NMI base addr
    la 		t0, trap_entry
    csrw 	mtvec, t0

.ifdef __riscv_flen
	## Enable FPU
	li 		t0, MSTATUS_FS
	csrs 	mstatus, t0
	csrw 	fcsr, x0
.endif

.option push
.option norelax
	la 		gp, __global_pointer$
.option pop
	la 		sp, _sp

	## Load data section
	la 		a0, _data_lma
	la 		a1, _data
	la 		a2, _edata
	bgeu 	a1, a2, 2f
1:
	lw 		t0, (a0)
	sw 		t0, (a1)
	addi 	a0, a0, 4
	addi 	a1, a1, 4
	bltu 	a1, a2, 1b
2:

	## Clear bss section
	la 		a0, __bss_start
	la 		a1, _end
	bgeu 	a0, a1, 2f
1:
	sw 		zero, (a0)
	addi 	a0, a0, 4
	bltu 	a0, a1, 1b
2:
	## enable mcycle_minstret
    csrci 	mcountinhibit, 0x5

	call	_system_init

	## eclic interrupt mode enable
	csrs	mtvec, 0x00000003	## Use the ECLIC interrupt mode

	## argc = argv = 0
	li 		a0, 0
	li 		a1, 0
	call 	main
	tail 	exit

1:
	j 		1b

exit:
	j		1b


	.global disable_mcycle_minstret
disable_mcycle_minstret:
    csrsi 	mcountinhibit, 0x5
	ret

	.global enable_mcycle_minstret
enable_mcycle_minstret:
    csrci 	mcountinhibit, 0x5
	ret



	.equ	REGBYTES, 4

#############################################
## macro for save context
.macro	SAVE_CONTEXT
	addi	sp,  sp, -20*REGBYTES	#spare 20-registers space in stack
	sw		x1,  0*REGBYTES(sp)
	sw		x4,  1*REGBYTES(sp)
	sw		x5,  2*REGBYTES(sp)
	sw		x6,  3*REGBYTES(sp)
	sw		x7,  4*REGBYTES(sp)
	sw		x10, 5*REGBYTES(sp)
	sw		x11, 6*REGBYTES(sp)
	sw		x12, 7*REGBYTES(sp)
	sw		x13, 8*REGBYTES(sp)
	sw		x14, 9*REGBYTES(sp)
	sw		x15, 10*REGBYTES(sp)
#ifndef __riscv_32e
	sw		x16, 11*REGBYTES(sp)
	sw		x17, 12*REGBYTES(sp)
	sw		x28, 13*REGBYTES(sp)
	sw		x29, 14*REGBYTES(sp)
	sw		x30, 15*REGBYTES(sp)
	sw		x31, 16*REGBYTES(sp)
#endif
.endm


#############################################
## macro for restore context
.macro	RESTORE_CONTEXT
	lw		x1,  0*REGBYTES(sp)
	lw		x4,  1*REGBYTES(sp)
	lw		x5,  2*REGBYTES(sp)
	lw		x6,  3*REGBYTES(sp)
	lw		x7,  4*REGBYTES(sp)
	lw		x10, 5*REGBYTES(sp)
	lw		x11, 6*REGBYTES(sp)
	lw		x12, 7*REGBYTES(sp)
	lw		x13, 8*REGBYTES(sp)
	lw		x14, 9*REGBYTES(sp)
	lw		x15, 10*REGBYTES(sp)
#ifndef __riscv_32e
	lw		x16, 11*REGBYTES(sp)
	lw		x17, 12*REGBYTES(sp)
	lw		x28, 13*REGBYTES(sp)
	lw		x29, 14*REGBYTES(sp)
	lw		x30, 15*REGBYTES(sp)
	lw		x31, 16*REGBYTES(sp)
#endif
	addi	sp,  sp, 20*REGBYTES	#remove spared 20-registers space in stack
.endm


##################################################
## macro for save mepc, mstatus, msubm registers
.macro	SAVE_EPC_STATUS
	csrr	x5, mepc
	sw		x5, 17*REGBYTES(sp)		# store mepc into stack 
	csrr	x5, mstatus
	sw		x5, 18*REGBYTES(sp)		# store mstatus into stack
	csrr	x5, msubm
	sw		x5, 19*REGBYTES(sp)		# store msubm into stack
.endm


##################################################
## macro for restore mepc, mstatus, msubm registers
.macro	RESTORE_EPC_STATUS
	lw		x5, 17*REGBYTES(sp)
	csrw	mepc, x5
	lw		x5, 18*REGBYTES(sp)
	csrw	mstatus, x5
	lw		x5, 19*REGBYTES(sp)
	csrw	msubm, x5
.endm


##############################################################
## IRQ entry point

	.section	.text.irq
	.align	2
	.global	irq_entry

irq_entry:	## mtvt2 register will hold this label
	SAVE_CONTEXT
	SAVE_EPC_STATUS

	## Jump to vec table entry
	## interrupt global enable
	## store interrupt return address
	csrrw	ra, jalmnxti, ra			# jump to ISR, indicated by mtvt2

	csrc	mstatus, MSTATUS_MIE
	RESTORE_EPC_STATUS
	RESTORE_CONTEXT
	mret	# return to regular code


##################################################
## macro for save all registers
.macro portSAVE_CONTEXT_asm

	/* Spare the space on stack */
	addi		sp, sp, -33*4

	/* Save all registers into Stack */
	sw			x31, 32*4(sp)
	sw			x30, 31*4(sp)
	sw			x29, 30*4(sp)
	sw			x28, 29*4(sp)
	sw			x27, 28*4(sp)
	sw			x26, 27*4(sp)
	sw			x25, 26*4(sp)
	sw			x24, 25*4(sp)
	sw			x23, 24*4(sp)
	sw			x22, 23*4(sp)
	sw			x21, 22*4(sp)
	sw			x20, 21*4(sp)
	sw			x19, 20*4(sp)
	sw			x18, 19*4(sp)
	sw			x17, 18*4(sp)
	sw			x16, 17*4(sp)
	sw			x15, 16*4(sp)
	sw			x14, 15*4(sp)
	sw			x13, 14*4(sp)
	sw			x12, 13*4(sp)
	sw			x11, 12*4(sp)
	sw			x10, 11*4(sp)
	sw			x9,  10*4(sp)
	sw			x8,	  9*4(sp)
	sw			x7,	  8*4(sp)
	sw			x6,	  7*4(sp)
	sw			x5,	  6*4(sp)
	sw			x4,	  5*4(sp)
	sw			x3,	  4*4(sp)
	sw			x1,	  3*4(sp)

	/* Push return address into stack */
	csrr		x5, mepc
	addi		x5, x5, 4
	sw			x5, 33*4(sp)

	/* Push parameter into stack */
	sw			x0, 2*4(sp)

	/* Push mstatus into stack */
	csrr		x5, mstatus
	sw			x5, 1*4(sp)

	/* Push 'ulCriticalNesting' into Stack */
	la			x5, ulCriticalNesting
	lw			x5, (x5)
	sw			x5, (sp)

	/* Store new top stack of task into 'pxCurrentTCB' */
	la			x5, pxCurrentTCB
	lw			x5, (x5)
	sw			sp, (x5)
.endm 	#end of this macro



##############################################################################
## macro for restore all registers

.macro	portRESTORE_CONTEXT_asm
	/* x6 points to Task's Stack Top */
	la			x5, pxCurrentTCB
	lw			x5, (x5)
	lw			x6, (x5)

	/* The critical nesting depth is the first item on the stack. */
	/* Load it into the ulCriticalNesting variable. */
	la			x5, ulCriticalNesting
	lw			x7, (x6)
	sw			x7, (x5)

	/* Get the mstatus from the stack. */
	lw			x7, 1*4(x6)
	csrw		mstatus, x7

	/* Restore all registers from the task. */
	lw			x31, 32*4(x6)
	lw			x30, 31*4(x6)
	lw			x29, 30*4(x6)
	lw			x28, 29*4(x6)
	lw			x27, 28*4(x6)
	lw			x26, 27*4(x6)
	lw			x25, 26*4(x6)
	lw			x24, 25*4(x6)
	lw			x23, 24*4(x6)
	lw			x22, 23*4(x6)
	lw			x21, 22*4(x6)
	lw			x20, 21*4(x6)
	lw			x19, 20*4(x6)
	lw			x18, 19*4(x6)
	lw			x17, 18*4(x6)
	lw			x16, 17*4(x6)
	lw			x15, 16*4(x6)
	lw			x14, 15*4(x6)
	lw			x13, 14*4(x6)
	lw			x12, 13*4(x6)
	lw			x11, 12*4(x6)
	lw			x10, 11*4(x6)
	lw			x9,  10*4(x6)
	lw			x8,	  9*4(x6)
	lw			x7,	  8*4(x6)
	lw			x5,	  6*4(x6)
	lw			x4,	  5*4(x6)
	lw			x3,	  4*4(x6)
	lw			x1,	  3*4(x6)

	/* get return address from stack */
	lw			x2,	 33*4(x6)
	csrw		mepc, x2

	/* put sp pointer into mscratch */
	addi		x2, x6, 33*4
	csrw		mscratch, x2
	lw			x6, 7*4(x6)

	/* Return to Original Point */
	mret
.endm	#end of this macro


##############################################################
## task switching
	.section	.text.trap
	.align		6
	.global		vPortYieldProcessor

vPortYieldProcessor:
	portSAVE_CONTEXT_asm

	/* Find the highest priority task that is ready to run. */
	jal		vTaskSwitchContext

	portRESTORE_CONTEXT_asm
Loop2:
	j		Loop2



##############################################################
## TRAP entry point

	.section	.text.trap
	.align	6		# in CLIC mode, the trap must be 64bytes aligned
	.global	trap_entry

trap_entry:  ## mtvec register wil hold this lable
	j		vPortYieldProcessor

Loop1:
	j	Loop1
	## Never touch here!

