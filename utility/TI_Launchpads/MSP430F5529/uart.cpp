/*
 * uart.c
 *
 *  Created on: 03.05.2014
 *      Author: riva
 */


#include <msp430f5529.h>
#include "uart.h"

/**
 * Receive Data (RXD) at P3.4
 */
#define RXD		BIT4

/**
 * Transmit Data (TXD) at P3.3
 */
#define TXD		BIT3

/**
 * Callback handler for receive
 */
void (*uart_rx_isr_ptr)(unsigned char c);

void uart_init(void)
{
	uart_set_rx_isr_ptr(0L);

	P3SEL  = RXD + TXD;
  	UCA0CTL1 |= UCSSEL_2;                     // SMCLK

  	UCA0BR0 = 70;                             // 16MHz 115200		(UCA0BR1*256) + UCA0BR0 = SMCLK / Baudios
  	UCA0BR1 = 0;                              // 16MHz 115200

  	UCA0MCTL = UCBRS0;                        // Modulation UCARSx = 1
  	UCA0CTL1 &= ~UCSWRST;                     // Initialize USCI state machine

  	//IE2 |= UCA0RXIE;                        // Enable USCI_A0 RX interrupt
}

void uart_set_rx_isr_ptr(void (*isr_ptr)(unsigned char c))
{
	uart_rx_isr_ptr = isr_ptr;
}

unsigned char uart_getc()
{
    //while (!(IFG2&UCA0RXIFG));                // USCI_A0 RX buffer ready?
	return UCA0RXBUF;

}

void uart_putc(unsigned char c)
{
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
    UCA0TXBUF = c;                    		// TX
}

void uart_puts(const char *str)
{
     while(*str) uart_putc(*str++);
}


#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	if(uart_rx_isr_ptr != 0L) {
		(uart_rx_isr_ptr)(UCA0RXBUF);
	}
}


