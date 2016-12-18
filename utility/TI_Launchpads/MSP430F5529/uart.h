/*
 * uart.h
 *
 *  Created on: 03.05.2014
 *      Author: MauroHernán
 */

#ifndef UART_H_
#define UART_H_

#include <msp430f5529.h>

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


#ifdef	__cplusplus
}
#endif


#endif /* UART_H_ */
