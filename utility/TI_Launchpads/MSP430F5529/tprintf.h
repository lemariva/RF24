#ifndef __TPRINTF_H
#define __TPRINTF_H

#include <msp430.h>
#include <stdarg.h>

#include "uart.h"
#include "tprintf.h"

#ifdef	__cplusplus
extern "C" {
#endif

void tprintf(char *format, ...);


#ifdef	__cplusplus
}
#endif

#endif

/* vim: set sw=4 et: */
