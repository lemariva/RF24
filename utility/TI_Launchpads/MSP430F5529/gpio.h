//
//
///**
// * @file gpio.h
// * Class declaration for SPI helper files
// */
//
// /**
// * Example of gpio.h class declaration for GPIO portability
// *
// * @defgroup Porting_GPIO Porting: GPIO
// *
// *
// * @{
// */
//
#ifndef _GPIO_H_
#define _GPIO_H_

#include <msp430.h>
#include <stdint.h>

/* Operational pins -- IRQ, CE, CSN (SPI chip-select)
 */
/* CSN SPI chip-select */
#define nrfCSNportout P2OUT
#define nrfCSNport 2
#define nrfCSNpin BIT2

/* CE Chip-Enable (used to put RF transceiver on-air for RX or TX) */
#define nrfCEportout P2OUT
#define nrfCEport 2
#define nrfCEpin BIT5


class GPIO {
public:
//		/* Constants */
	static const int DIRECTION_OUT = 1;
	static const int DIRECTION_IN = 0;

	static const int OUTPUT_HIGH = 1;
	static const int OUTPUT_LOW = 0;

	GPIO();
	/**
	 * Similar to Arduino pinMode(pin,mode);
	 * @param port
	 * @param DDR
	 */
	static void open(int port, int DDR);
	/**
	* Similar to Arduino digitalWrite(pin,state);
	* @param port
	* @param value
	*/
	static void write(int pin, int value);

	virtual ~GPIO();
};
//
#endif
///*@}*/
//
//
