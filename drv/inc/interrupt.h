////////////////////////////////////////////////////////////
// this file is used for s3c2440 project
//	
// Auther: Wu Zhigang; wzgpeter@163.com
// Date: 2020-02-12
//
#ifndef INTERRUPT_H
#define INTERRUPT_H


#define	ECLIC_GROUP_LEVEL0_PRIO4	0
#define	ECLIC_GROUP_LEVEL1_PRIO3	1
#define	ECLIC_GROUP_LEVEL2_PRIO2	2
#define	ECLIC_GROUP_LEVEL3_PRIO1	3
#define	ECLIC_GROUP_LEVEL4_PRIO0	4


//eclic reg offset list
#define ECLIC_CFG_OFFSET			0x00U
#define ECLIC_INFO_OFFSET			0x04U
#define	ECLIC_MTH_OFFSET			0x0BU
#define ECLIC_INTIP_OFFSET			0x1000U
#define ECLIC_INTIE_OFFSET			0x1001U
#define ECLIC_INTATTR_OFFSET		0x1002U
#define ECLIC_INTCTL_OFFSET			0x1003U


#define ECLIC_INTCTLBITS			4
#define ECLIC_CFG_NLBITS_MASK		0x1EU
#define ECLIC_CFG_NLBITS_LSB		0x01U

#define ECLIC 						ECLIC_ADDR_BASE


//eclic register list
#define	ECLIC_CFG				REG8(ECLIC + ECLIC_CFG_OFFSET)
#define	ECLIC_INFO				REG32(ECLIC + ECLIC_INFO_OFFSET)
#define	ECLIC_MTH				REG8(ECLIC + ECLIC_MTH_OFFSET)
#define	ECLIC_INTIP(x)			REG8(ECLIC + ECLIC_INTIP_OFFSET + 4*x)
#define	ECLIC_INTIE(x)			REG8(ECLIC + ECLIC_INTIE_OFFSET + 4*x)
#define	ECLIC_INTCTL(x)			REG8(ECLIC + ECLIC_INTCTL_OFFSET + 4*x)


typedef enum IRQn
{

	CLIC_INT_RESERVED        	 = 0,    	/*!< RISC-V reserved		*/
	CLIC_INT_SFT         		 = 3,		/*!< Software interrupt		*/
	CLIC_INT_TMR         		 = 7,		/*!< CPU Timer interrupt	*/
	CLIC_INT_BWEI        		 = 17,		/*!< Bus Error interrupt	*/
	CLIC_INT_PMOVI       		 = 18,		/*!< Performance Monitor	*/

    /* interruput numbers */
    WWDGT_IRQn                   = 19,      /*!< window watchDog timer interrupt                          */
    LVD_IRQn                     = 20,      /*!< LVD through EXTI line detect interrupt                   */
    TAMPER_IRQn                  = 21,      /*!< tamper through EXTI line detect                          */
    RTC_IRQn                     = 22,      /*!< RTC alarm interrupt                                      */
    FMC_IRQn                     = 23,      /*!< FMC interrupt                                            */
    RCU_CTC_IRQn                 = 24,      /*!< RCU and CTC interrupt                                    */
    EXTI0_IRQn                   = 25,      /*!< EXTI line 0 interrupts                                   */
    EXTI1_IRQn                   = 26,      /*!< EXTI line 1 interrupts                                   */
    EXTI2_IRQn                   = 27,      /*!< EXTI line 2 interrupts                                   */
    EXTI3_IRQn                   = 28,      /*!< EXTI line 3 interrupts                                   */
    EXTI4_IRQn                   = 29,     	/*!< EXTI line 4 interrupts                                   */
    DMA0_Channel0_IRQn           = 30,     	/*!< DMA0 channel0 interrupt                                  */
    DMA0_Channel1_IRQn           = 31,     	/*!< DMA0 channel1 interrupt                                  */
    DMA0_Channel2_IRQn           = 32,     	/*!< DMA0 channel2 interrupt                                  */
    DMA0_Channel3_IRQn           = 33,     	/*!< DMA0 channel3 interrupt                                  */
    DMA0_Channel4_IRQn           = 34,     	/*!< DMA0 channel4 interrupt                                  */
    DMA0_Channel5_IRQn           = 35,     	/*!< DMA0 channel5 interrupt                                  */
    DMA0_Channel6_IRQn           = 36,     	/*!< DMA0 channel6 interrupt                                  */
    ADC0_1_IRQn                  = 37,     	/*!< ADC0 and ADC1 interrupt                                  */
    CAN0_TX_IRQn                 = 38,     	/*!< CAN0 TX interrupts                                       */
    CAN0_RX0_IRQn                = 39,     	/*!< CAN0 RX0 interrupts                                      */
    CAN0_RX1_IRQn                = 40,     	/*!< CAN0 RX1 interrupts                                      */
    CAN0_EWMC_IRQn               = 41,     	/*!< CAN0 EWMC interrupts                                     */
    EXTI5_9_IRQn                 = 42,     	/*!< EXTI[9:5] interrupts                                     */
    TIMER0_BRK_IRQn              = 43,     	/*!< TIMER0 break interrupts                                  */
    TIMER0_UP_IRQn               = 44,     	/*!< TIMER0 update interrupts                                 */
    TIMER0_TRG_CMT_IRQn          = 45,     	/*!< TIMER0 trigger and commutation interrupts                */
    TIMER0_Channel_IRQn          = 46,     	/*!< TIMER0 channel capture compare interrupts                */
    TIMER1_IRQn                  = 47,     	/*!< TIMER1 interrupt                                         */
    TIMER2_IRQn                  = 48,     	/*!< TIMER2 interrupt                                         */
    TIMER3_IRQn                  = 49,     	/*!< TIMER3 interrupts                                        */
    I2C0_EV_IRQn                 = 50,     	/*!< I2C0 event interrupt                                     */
    I2C0_ER_IRQn                 = 51,     	/*!< I2C0 error interrupt                                     */
    I2C1_EV_IRQn                 = 52,     	/*!< I2C1 event interrupt                                     */
    I2C1_ER_IRQn                 = 53,     	/*!< I2C1 error interrupt                                     */
    SPI0_IRQn                    = 54,     	/*!< SPI0 interrupt                                           */
    SPI1_IRQn                    = 55,     	/*!< SPI1 interrupt                                           */
    USART0_IRQn                  = 56,     	/*!< USART0 interrupt                                         */
    USART1_IRQn                  = 57,     	/*!< USART1 interrupt                                         */
    USART2_IRQn                  = 58,     	/*!< USART2 interrupt                                         */
    EXTI10_15_IRQn               = 59,     	/*!< EXTI[15:10] interrupts                                   */
    RTC_ALARM_IRQn               = 60,     	/*!< RTC alarm interrupt EXTI                                 */
    USBFS_WKUP_IRQn              = 61,     	/*!< USBFS wakeup interrupt                                   */

    EXMC_IRQn                    = 67,     	/*!< EXMC global interrupt                                    */

    TIMER4_IRQn                  = 69,     	/*!< TIMER4 global interrupt                                  */
    SPI2_IRQn                    = 70,     	/*!< SPI2 global interrupt                                    */
    UART3_IRQn                   = 71,     	/*!< UART3 global interrupt                                   */
    UART4_IRQn                   = 72,     	/*!< UART4 global interrupt                                   */
    TIMER5_IRQn                  = 73,     	/*!< TIMER5 global interrupt                                  */
    TIMER6_IRQn                  = 74,     	/*!< TIMER6 global interrupt                                  */
    DMA1_Channel0_IRQn           = 75,     	/*!< DMA1 channel0 global interrupt                           */
    DMA1_Channel1_IRQn           = 76,     	/*!< DMA1 channel1 global interrupt                           */
    DMA1_Channel2_IRQn           = 77,     	/*!< DMA1 channel2 global interrupt                           */
    DMA1_Channel3_IRQn           = 78,     	/*!< DMA1 channel3 global interrupt                           */
    DMA1_Channel4_IRQn           = 79,     	/*!< DMA1 channel3 global interrupt                           */

    CAN1_TX_IRQn                 = 82,     	/*!< CAN1 TX interrupt                                        */
    CAN1_RX0_IRQn                = 83,     	/*!< CAN1 RX0 interrupt                                       */
    CAN1_RX1_IRQn                = 84,     	/*!< CAN1 RX1 interrupt                                       */
    CAN1_EWMC_IRQn               = 85,     	/*!< CAN1 EWMC interrupt                                      */
    USBFS_IRQn                   = 86,     	/*!< USBFS global interrupt                                   */

	ECLIC_NUM_INTERRUPTS
} IRQn_Type;

#define		EXTI	EXTI_BASE

/* register definition */
#define		EXTI_INTEN		REG32(EXTI + 0x00U)
#define		EXTI_EVEN		REG32(EXTI + 0x04U)
#define		EXTI_RTEN		REG32(EXTI + 0x08U)
#define		EXTI_FTEN		REG32(EXTI + 0x0CU)
#define		EXTI_SWIEV		REG32(EXTI + 0x10U)
#define		EXTI_PD			REG32(EXTI + 0x14U)

extern void glob_intr_disable(void);
extern void glob_intr_enable(void);
extern void eclic_set_nlbits(uint8_t nlbits);
extern void eclic_irq_enable(uint32_t irqId, uint8_t level, uint8_t priority);
extern void eclic_init(uint32_t irqId);

#endif //INTERRUPT_H
