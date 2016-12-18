/*
 * uart.h
 *
 *  Created on: 03.05.2014
 *      Author: MauroHernán
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"

#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#define SERIAL_UART6

//UART Interfaces

#if defined(SERIAL_UART7)

#define PERIPH_UART_GPIO	SYSCTL_PERIPH_GPION
#define PERIPH_UART			SYSCTL_PERIPH_UART7
#define UART_UNIT			UART7_BASE
#define	GPIO_UARTRX			GPIO_PC4_U7RX
#define GPIO_UARTTX			GPIO_PC5_U7TX

#define	PORT_UART 			GPIO_PORTP_BASE
#define UART_RXD_PIN   		GPIO_PIN_4			// PORT P 	Input
#define UART_TXD_PIN   		GPIO_PIN_5 			// PORT P	UART
#define UART_INT			INT_UART7

#elif defined(SERIAL_UART6)

#define PERIPH_UART_GPIO	SYSCTL_PERIPH_GPIOP
#define PERIPH_UART			SYSCTL_PERIPH_UART6
#define UART_UNIT			UART6_BASE
#define	GPIO_UARTRX			GPIO_PP0_U6RX
#define GPIO_UARTTX			GPIO_PP1_U6TX

#define	PORT_UART 			GPIO_PORTP_BASE
#define UART_RXD_PIN		GPIO_PIN_0			// PORT P 	Input	UART6
#define UART_TXD_PIN 		GPIO_PIN_1 			// PORT P	UART

#define UART_INT			INT_UART6

#endif


#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Initialize soft UART
 */
void uart_init(void);

/**
 * Set pointer for ISR to call when data was received.
 *
 * @param[in]	*isr_ptr	pointer to ISR
 */
void uart_set_rx_isr_ptr(void (*isr_ptr)(unsigned char c));

/**
 * Read one character from UART blocking.
 *
 * @return	character received
 */
unsigned char uart_getc();

/**
 * Write one chracter to the UART blocking.
 *
 * @param[in]	*c	the character to write
 */
void uart_putc(unsigned char c);

/**
 * Write string to the UART blocking.
 *
 * @param[in]	*str	the 0 terminated string to write
 */
void uart_puts(const char *str);

/**
 *
 * UART Interruption Handler
 *
 */
void UARTIntHandler(void);

#ifdef	__cplusplus
}
#endif

#endif /* UART_H_ */
