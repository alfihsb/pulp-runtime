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
	* for variables of arduino
	* see https://docs.arduino.cc/language-reference/#variables
	*/

#ifndef __ARDUINO_CORES_CHARACTERS_H__
#define __ARDUINO_CORES_CHARACTERS_H__

#include <ctype.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
	* Analyze if a char is alpha (that is a letter).
	* Returns true if the input char contains a letter.
	*/
inline bool isAlpha(char thisChar)
{
	/**
		* if thisChar is NOT an alpha character, then isalpha will return 0
		* then if we compare the return value with fixed value 0,
		* we can only return false (because thisChar is not an alpha character)
		* if we compare it "not equal to" fixed value 0
		*/
	return (isalpha(thisChar) != 0);
}

/**
	* Analyze if a char is alphanumeric (that is a letter or a number).
	* Returns true if the input char contains either a number or a letter.
	*/
inline bool isAlphaNumeric(char thisChar)
{
	return (isalnum(thisChar) != 0);
}

/**
	* Analyze if a char is ASCII.
	* Returns true if the input char contains an ASCII character.
	*/
inline bool isAscii(char thisChar)
{
	/* we can only use isascii() in POSIX.1-2001 with XSI */
#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L) && \
	defined(_XOPEN_SOURCE))
	/* use XSI-compliant function */
	return (isascii(thisChar) != 0);
#else
	/* XSI standard is not available nor used */
	return ((((int) thisChar) >= 0) && (((int) thisChar) <= 127));
#endif
}

/**
	* Analyze if a char is a control character.
	* Returns true if the input char is a control character.
	*/
inline bool isControl(char thisChar)
{
	return (iscntrl(thisChar) != 0);
}

/**
	* Analyze if a char is a digit (that is a number).
	* Returns true if the input char is a number.
	*/
inline bool isDigit(char thisChar)
{
	return (isdigit(thisChar) != 0);
}

/**
	* Analyze if a char is printable with some content
	* (space is printable but has no content).
	* Returns true if the input char is printable.
	*/
inline bool isGraph(char thisChar)
{
	return (isgraph(thisChar) != 0);
}

/**
	* Analyze if a char is a hexadecimal digit (A-F, 0-9).
	* Returns true if the input char contains a hexadecimal digit.
	*/
inline bool isHexadecimalDigit(char thisChar)
{
	return (isxdigit(thisChar) != 0);
}

/**
	* Analyze if a char is lower case (that is a letter in lower case).
	* Returns true if the input char contains a letter in lower case.
	*/
inline bool isLowerCase(char thisChar)
{
	return (islower(thisChar) != 0);
}

/**
	* Analyze if a char is printable
	* (that is any character that produces an output, even a blank space).
	* Returns true if the input char is printable.
	*/
inline bool isPrintable(char thisChar)
{
	return (isprint(thisChar) != 0);
}

/**
	* Analyze if a char is punctuation (that is a comma,
	* a semicolon, an exclamation mark and so on).
	* Returns true if the input char is punctuation.
	*/
inline bool isPunct(char thisChar)
{
	return (ispunct(thisChar) != 0);
}

/**
	* Analyze if a char is a white-space character.
	* Returns true if the input char is a space,
	* form feed ('\f'), newline ('\n'), carriage return ('\r'),
	* horizontal tab ('\t'), or vertical tab ('\v').
	*/
inline bool isSpace(char thisChar)
{
	return (isspace(thisChar) != 0);
}

/**
	* Analyze if a char is upper case (that is, a letter in upper case).
	* Returns true if the input char is upper case.
	*/
inline bool isUpperCase(char thisChar)
{
	return (isupper(thisChar) != 0);
}

/**
	* Analyze if a char is a space character.
	* Returns true if the input char is a space or horizontal tab ('\t').
	*/
inline bool isWhitespace(char thisChar)
{
	return (isblank(thisChar) != 0);
}

#ifdef __cplusplus
}
#endif

#endif /* ! defined(__ARDUINO_CORES_CHARACTERS_H__) */
