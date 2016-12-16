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

/* 
 * File:   compatiblity.h
 * Author: lemariva
 *
*/

 /**
 * @file compatibility.h
 */

 /**
 * class declaration for timing functions
 *
 * @defgroup Porting_Timing Porting: Timing
 * 
 * @{
 */
 

#ifndef COMPATIBLITY_H
#define	COMPATIBLITY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <msp430.h>
#include <stdint.h>


void __msleep(int milisec);
void __usleep(int milisec);
void __start_timer();
long __millis();

#ifdef	__cplusplus
}
#endif

#endif	/* COMPATIBLITY_H */

/*@}*/	
