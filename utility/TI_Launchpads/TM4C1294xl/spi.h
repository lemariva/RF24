/*
 * Library for performing SPI I/O on a wide range of MSP430 chips.
 *
 * Copyright (c) 2013, Eric Brundick <spirilis@linux.com>

 * Permission to use, copy, modify, and/or distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright notice
 * and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT,
 * OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * 	MODIFIED by lemariva
	Copyright [2016] [Mauro Riva -lemariva@gmail.com- <http://lemariva.com>]

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#ifndef _SPI_H_
#define _SPI_H_

#include <stdint.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"

#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/ssi.h"



/* SPI port--
 * Select which USCI port we're using to connect to the rf24l001+
*/
#define SPI_DRIVER_SSI2


#if defined(SPI_DRIVER_SSI2)

#define SSIx_BASE			SSI2_BASE
#define PERIPH_SSI_GPIO		SYSCTL_PERIPH_GPIOD
#define PERIPH_SSI			SYSCTL_PERIPH_SSI2

#define SSI_MOSI_GPIO		GPIO_PD1_SSI2XDAT0
#define SSI_MISO_GPIO		GPIO_PD0_SSI2XDAT1
#define SSI_CLK_GPIO		GPIO_PD3_SSI2CLK

#define SSI_PORT_BASE		GPIO_PORTD_BASE
#define SSI_MOSI_PIN		GPIO_PIN_1
#define SSI_MISO_PIN		GPIO_PIN_0
#define SSI_CLK_PIN			GPIO_PIN_3

#elif defined(SPI_DRIVER_SSI3)

#define SSIx_BASE			SSI3_BASE
#define PERIPH_SSI_GPIO		SYSCTL_PERIPH_GPIOQ
#define PERIPH_SSI			SYSCTL_PERIPH_SSI3

#define SSI_MOSI_GPIO		GPIO_PQ2_SSI3XDAT0
#define SSI_MISO_GPIO		GPIO_PQ3_SSI3XDAT1
#define SSI_CLK_GPIO		GPIO_PQ0_SSI3CLK

#define SSI_PORT_BASE		GPIO_PORTQ_BASE
#define SSI_MOSI_PIN		GPIO_PIN_2
#define SSI_MISO_PIN		GPIO_PIN_3
#define SSI_CLK_PIN			GPIO_PIN_0

#endif



class SPI {
public:
	SPI();
	void begin();
	/**
	* Transfer a single byte
	* @param tx_ Byte to send
	* @return Data returned via spi
	*/
	uint8_t transfer(uint8_t tx_);

	uint16_t transfer16(uint16_t);  // SPI xfer 2 bytes
	uint16_t transfer9(uint16_t);   // SPI xfer 9 bits (courtesy for driving LCD screens)

	virtual ~SPI();
private:
	void init();
};

#endif
