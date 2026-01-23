/**
	* Copyright (C) 2026 Indonesia Chip Design Collaborative Center (ICDEC)
	*
	* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	* NONINFRINGEMENT.
	*/

/**
	* this file can be included in both C and C++ code
	*
	* this file implement language reference requirement
	* for functions: interrupts of arduino
	* see https://docs.arduino.cc/language-reference/#structure
	*/

#ifndef __ARDUINO_CORES_ARDUINO_INTERRUPTS_H__
#define __ARDUINO_CORES_ARDUINO_INTERRUPTS_H__

#include <pulp.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
	* interrupts and noInterrupts is global interrupt control
	* and cannot be nested
	*/

/* enable interrupt */
static inline void interrupts(void)
{
	hal_irq_enable();
}

/* disable interrupt */
static inline void noInterrupts(void)
{
	hal_irq_disable();
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ! defined(__ARDUINO_CORES_ARDUINO_INTERRUPTS_H__) */
