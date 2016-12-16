/*
 * uart.h
 *
 *  Created on: 03.05.2014
 *      Author: riva
 */

#ifndef UART_H_
#define UART_H_

#define 	UART_RX_SIZE 	3

#define 	UART_DRIVER_USCI_A 			// only USCI_A0 support UART

volatile unsigned int tx_flag;			//Mailbox Flag for the tx_char.
volatile unsigned char tx_char;			//This char is the most current char to go into the UART

volatile unsigned int rx_flag;			//Mailbox Flag for the rx_char.
volatile unsigned char rx_char;			//This char is the most current char to come out of the UART

// UART
bool isReceiving;		// Status for when the device is receiving
bool hasReceived;		// Lets the program know when a byte is received

char RXBuff[UART_RX_SIZE];

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

void Receive();


#endif /* UART_H_ */
