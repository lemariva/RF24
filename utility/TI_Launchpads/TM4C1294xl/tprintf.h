#ifndef __TPRINTF_H
#define __TPRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include "uart.h"

#ifdef	__cplusplus
extern "C" {
#endif

void tprintf(char *format, ...);

#ifdef	__cplusplus
}
#endif

#endif

/* vim: set sw=4 et: */
