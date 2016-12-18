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
volatile uint8_t  pinstatus;

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
		SysCtlDelay(112);
}

/**
 * This function is added in order to simulate arduino millis() function
 */
void __start_timer()
{

    // PIN
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
	GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);


	uint32_t g_ui32SysClock;

	#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
		defined(TARGET_IS_TM4C129_RA1) ||                                         \
		defined(TARGET_IS_TM4C129_RA2)
		g_ui32SysClock =	120000000;		// PLC = 120MHz
	#else
		g_ui32SysClock = SysCtlClockGet();		// PLC = 120MHz
	#endif

	// initialize timers
    // Enable the peripherals used by this example.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    // Enable processor interrupts.
    IntMasterEnable();
    // Configure the two 32-bit periodic timers.
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, g_ui32SysClock/1000); // 1ms clock!
    // Setup the interrupts for the timer timeouts.
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    // Enable the timers.
    TimerEnable(TIMER0_BASE, TIMER_A);

    // Initialize the counter.
    _millis = 0;

}

long __millis()
{
	return _millis;
}

//*****************************************************************************
//
// The interrupt handler for the first timer interrupt.
//
//*****************************************************************************
void
Timer0IntHandler(void)
{
	pinstatus ^= 1;
    // Clear the timer interrupt.
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, pinstatus * GPIO_PIN_0);

    _millis++;

}


