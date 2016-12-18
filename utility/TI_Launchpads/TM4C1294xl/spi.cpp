#include "spi.h"
//
volatile uint8_t rf_irq;
//
//
SPI::SPI()
{
}
SPI::~SPI()
{

}
void SPI::begin()
{
	// Enable GPIO port X for SPI
	SysCtlPeripheralEnable(PERIPH_SSI);
	SysCtlPeripheralEnable(PERIPH_SSI_GPIO);

	GPIOPinConfigure(SSI_CLK_GPIO); 	// SCLK
    GPIOPinConfigure(SSI_MOSI_GPIO);   	// MOSI
    GPIOPinConfigure(SSI_MISO_GPIO);   	// MISO

    GPIOPadConfigSet(SSI_PORT_BASE, SSI_MISO_PIN, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(SSI_PORT_BASE, SSI_MOSI_PIN | SSI_CLK_PIN, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD);

	// Configure the GPIO settings for the SSI pins.  This function also gives
	// control of these pins to the SSI hardware.  Consult the data sheet to
	// see which functions are allocated per pin.

    GPIOPinTypeSSI(SSI_PORT_BASE, SSI_MOSI_PIN | SSI_MISO_PIN | SSI_CLK_PIN);


	init();

}
void SPI::init()
{
	uint32_t g_ui32SysClock;

	#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
		defined(TARGET_IS_TM4C129_RA1) ||                                         \
		defined(TARGET_IS_TM4C129_RA2)
		g_ui32SysClock =	120000000;		// PLC = 120MHz

	#else
		g_ui32SysClock = SysCtlClockGet();		// PLC = 120MHz
	#endif

	//
	// Configure and enable the SSI port for SPI master mode.  Use SSIx,
	// system clock supply, idle clock level low and active low clock in
	// Freescale SPI mode, master mode, 1 MHz SSI frequency, and 8-bit data.
	// For SPI mode, you can set the polarity of the SSI clock when the SSI
	// unit is idle.  You can also configure what clock edge you want to
	// capture data on.  Please reference the datasheet for more information on
	// the different SPI modes.
	//
	SSIConfigSetExpClk(SSIx_BASE, g_ui32SysClock, SSI_FRF_MOTO_MODE_0,
					   SSI_MODE_MASTER, 1000000, 8);

	//
	// Enable the SSIx module.
	//
	SSIEnable(SSIx_BASE);
}
//
uint8_t SPI::transfer(uint8_t inb)
{
	uint32_t pui32DataRx;
	uint32_t psendDataTx = inb;

    SSIDataPut(SSIx_BASE, psendDataTx);
    SSIDataGet(SSIx_BASE, &pui32DataRx);
	//

	// Wait until SSI3 is done transferring all the data in the transmit FIFO.
	//
	while(SSIBusy(SSIx_BASE))
	{
	}

	return (uint8_t) pui32DataRx;
}

//uint16_t SPI::transfer16(uint16_t inw)
//{
//	uint16_t retw;
//	uint8_t *retw8 = (uint8_t *)&retw, *inw8 = (uint8_t *)&inw;
//
//	UCB0TXBUF = inw8[1];
//	while ( !(UCB0IFG & UCRXIFG) )
//		;
//	retw8[1] = UCB0RXBUF;
//	UCB0TXBUF = inw8[0];
//	while ( !(UCB0IFG & UCRXIFG) )
//		;
//	retw8[0] = UCB0RXBUF;
//	return retw;
//}
