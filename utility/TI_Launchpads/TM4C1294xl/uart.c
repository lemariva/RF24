/*
 * uart.c
 *
 *  Created on: 03.05.2014
 *      Author: riva
 */

#include "uart.h"

void uart_init(void)
{
	uint32_t g_ui32SysClock;

	#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
		defined(TARGET_IS_TM4C129_RA1) ||                                         \
		defined(TARGET_IS_TM4C129_RA2)
		g_ui32SysClock =	120000000;		// PLC = 120MHz
	#else
		g_ui32SysClock = SysCtlClockGet();		// PLC = 120MHz
	#endif

	// Enable GPIO
	SysCtlPeripheralPowerOn(PERIPH_UART_GPIO);

	SysCtlPeripheralReset(PERIPH_UART_GPIO);
	SysCtlPeripheralEnable(PERIPH_UART_GPIO);
    // Enable UART
	SysCtlPeripheralEnable(PERIPH_UART);
    // Configure GPIO Pins for UART mode.
	GPIOPinConfigure(GPIO_UARTRX);
	GPIOPinConfigure(GPIO_UARTTX);
	GPIOPinTypeUART(PORT_UART,  UART_RXD_PIN | UART_TXD_PIN);

    // Use oscillator as the UART clock source.
    UARTConfigSetExpClk	(UART_UNIT, g_ui32SysClock, 115200,	//115200 internal 16mHz oscilator -> UART_CLOCK_PIOSC (UARTClockSourceSet(UART_UNIT, UART_CLOCK_PIOSC))
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));
    //
    // Initialize the UART interruption
    //
    // Set both the TX and RX trigger thresholds to 4.  This will be used by
	// the uDMA controller to signal when more data should be transferred.  The
	// uDMA TX and RX channels will be configured so that it can transfer 2
	// bytes in a burst when the UART is ready to transfer more data.
	//
    UARTFIFOLevelSet(UART_UNIT, UART_FIFO_TX1_8, UART_FIFO_RX1_8);

    UARTIntRegister(UART_UNIT, UARTIntHandler);

//    IntEnable(UART_INT);
//
//    UARTIntEnable(UART_UNIT, UART_INT_RX | UART_INT_RT);

}

void uart_set_rx_isr_ptr(void (*isr_ptr)(unsigned char c))
{
	//uart_rx_isr_ptr = isr_ptr;
}

unsigned char uart_getc()
{
	return ROM_UARTCharGetNonBlocking(UART_INT);

}

void uart_putc(unsigned char c)
{
	ROM_UARTCharPut(UART_UNIT, c);                    		// TX
}

void uart_puts(const char *str)
{
	int ui32Count = 16;
    // Loop while there are more characters to send.
    while(ui32Count--)
    {
        // Write the next character to the UART.
        UARTCharPutNonBlocking(UART_UNIT, *str++);
    }
}


//*****************************************************************************
//
// The UART interrupt handler.
//
//*****************************************************************************
void
UARTIntHandler(void)
{
    uint32_t ui32Status;

    // Get the interrrupt status.
    ui32Status = UARTIntStatus(UART_UNIT, true);

    // Clear the asserted interrupts.
    UARTIntClear(UART_UNIT, ui32Status);

    //
    // Loop while there are characters in the receive FIFO.
    //
    while(UARTCharsAvail(UART_UNIT))
    {
        //
        // Read the next character from the UART and write it back to the UART.
        //
        UARTCharPutNonBlocking(UART_UNIT,
                                   ROM_UARTCharGetNonBlocking(UART_UNIT));

    }
}

