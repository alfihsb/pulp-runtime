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
	* for structure of arduino
	* see https://docs.arduino.cc/language-reference/#structure
	*/

#ifndef __ARDUINO_CORES_STRUCTURE_H__
#define __ARDUINO_CORES_STRUCTURE_H__

/**
	* define loop and setup here,
	* both loop and setup are c-like function
	*/
#ifdef __cplusplus
extern "C"
{
#endif

/* setup function for user sketch */
extern void setup(void);

/* loop function for user sketch */
extern void loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ! defined(__ARDUINO_CORES_STRUCTURE_H__) */
