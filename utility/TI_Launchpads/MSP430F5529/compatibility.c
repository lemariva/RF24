/*
 	Copyright [2016] [Mauro Riva -lemariva@gmail.com- (http://lemariva.com)]

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

#include "compatibility.h"

volatile uint32_t _millis;

/**********************************************************************/
/**
 * This function is added in order to simulate arduino delay() function
 * @param milisec
 */
void __msleep(int milisec)
{
	int useconds = milisec * 1000;
	__usleep(useconds);
}

void __usleep(int usec)
{
	int i;
	for (i=usec; i>0; i--)
		__delay_cycles(16);
}

/**
 * This function is added in order to simulate arduino millis() function
 */
void __start_timer()
{
	// Timer Specifications
	TB0CCTL0 = CCIE; // CCR0 interrupt enabled
	TB0CCR0 = 8000;  // Make is 1000 Hz
	TB0CTL = TBSSEL_2 + MC_1 + TBCLR;

	_millis = 0;
}

long __millis()
{
	return _millis;
}


// Timer0_B0 interrupt service routine
#pragma vector=TIMER0_B0_VECTOR
__interrupt void Timer0_B0 (void)
{
	_millis++;
	TB0CCTL0 &= ~CCIFG;
}
