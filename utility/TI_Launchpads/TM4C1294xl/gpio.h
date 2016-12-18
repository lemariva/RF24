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

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"

#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"


/* Operational pins -- IRQ, CE, CSN (SPI chip-select)
 */
/* CSN SPI chip-select */
#define nrfCSNportout 	SYSCTL_PERIPH_GPIOM
#define nrfCSNport 	  	GPIO_PORTM_BASE
#define nrfCSNpin 		GPIO_PIN_4

/* CE Chip-Enable (used to put RF transceiver on-air for RX or TX) */
#define nrfCEportout 	SYSCTL_PERIPH_GPIOM
#define nrfCEport 	 	GPIO_PORTM_BASE
#define nrfCEpin 		GPIO_PIN_5


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
