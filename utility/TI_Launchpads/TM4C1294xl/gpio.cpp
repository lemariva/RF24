/*
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


#include "gpio.h"

void GPIO::open(int pin, int DDR)
{
	if(pin == nrfCSNpin)
	{
		// GPIO port x needs to be enabled so these pins can be used.
		#if (nrfCEportout != nrfCSNportout)
			SysCtlPeripheralEnable(nrfCEportout);
		#endif

	    GPIOPinTypeGPIOOutput(nrfCSNport, nrfCSNpin); 	 // ~CS - configure it as GPIO output
	    GPIOPinWrite(nrfCSNport, nrfCSNpin, nrfCSNpin);  // ~CS - set it to logic HIGH

	}else
	{
		// GPIO port x needs to be enabled so these pins can be used.
		SysCtlPeripheralEnable(nrfCSNportout);

	    GPIOPinTypeGPIOOutput(nrfCEport, nrfCEpin); 	 // ~CE - configure it as GPIO output
	    GPIOPinWrite(nrfCEport, nrfCEpin, nrfCEpin); 	 // ~CE - set it to logic HIGH
	}

}
void GPIO::write(int pin, int value)
{
	if(pin == nrfCEpin)
	{
		if (value==OUTPUT_LOW)
			GPIOPinWrite(nrfCEport, nrfCEpin, 0);
		else
			GPIOPinWrite(nrfCEport, nrfCEpin, nrfCEpin);
	}

	if(pin == nrfCSNpin)
	{
		if (value==OUTPUT_LOW)
			GPIOPinWrite(nrfCSNport, nrfCSNpin, 0);
		else
			GPIOPinWrite(nrfCSNport, nrfCSNpin, nrfCSNpin);
	}
}
