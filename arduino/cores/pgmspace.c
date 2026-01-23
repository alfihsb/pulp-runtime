/**
	* Copyright (C) 2026 Indonesia Chip Design Collaborative Center (ICDEC)
	*
	* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	* NONINFRINGEMENT.
	*/

/**
	* custom definition for pgm space function, these functions only be used
	* if standard POSIX.1-2001 or standard POSIX.1-2008 isn't used nor available
	*
	* these function are not implemented with optimization
	*/

#include <stddef.h>
#include <stdint.h>

#include <ctype.h> /* for tolower() */

#include "pgmspace.h"

/**
	* function renaming based on used standard
	*/

#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L))
	/**
		* standard POSIX.1-2008 is used, memccpy is provided by compiler,
		* then just declare header without actually using the function
		*/
	void *   pgmspace_memccpy(void * restrict dest, const void * restrict src,
						int c, size_t n);

/* defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L) */
#else /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L)) */
	/**
		* standard POSIX.1-2008 is NOT used,
		* rename pgmspace function to match the macro, and use our implementation
		*/
	#define  pgmspace_memccpy          memccpy_P

#endif /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L)) */



#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L))
	/**
		* standard POSIX.1-2008 is used, stpcpy is provided by compiler,
		* then just declare header without actually using the function
		*/
	char *   pgmspace_stpcpy(char * restrict dst, const char * restrict src);

/* defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L) */
#else /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L)) */
	/**
		* standard POSIX.1-2008 is NOT used,
		* rename pgmspace function to match the macro, and use our implementation
		*/
	#define  pgmspace_stpcpy           stpcpy_P

#endif /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L)) */



#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L))
	/**
		* standard POSIX.1-2001 is used, strcasecmp is provided by compiler,
		* then just declare header without actually using the function
		*/
	int      pgmspace_strcasecmp(const char *s1, const char *s2);

/* defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L) */
#else /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L)) */
	/**
		* standard POSIX.1-2001 is NOT used,
		* rename pgmspace function to match the macro, and use our implementation
		*/
	#define  pgmspace_strcasecmp       strcasecmp_P

#endif /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L)) */



#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L))
	/**
		* standard POSIX.1-2008 is used, strnlen is provided by compiler,
		* then just declare header without actually using the function
		*/
	size_t   pgmspace_strnlen(const char *s, size_t maxlen);

/* defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L) */
#else /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L)) */
	/**
		* standard POSIX.1-2008 is NOT used,
		* rename pgmspace function to match the macro, and use our implementation
		*/
	#define  pgmspace_strnlen          strnlen_P

#endif /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200809L)) */



#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L))
	/**
		* standard POSIX.1-2001 is used, strncasecmp is provided by compiler,
		* then just declare header without actually using the function
		*/
	int      pgmspace_strncasecmp(const char *s1, const char *s2, size_t n);

/* defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L) */
#else /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L)) */
	/**
		* standard POSIX.1-2001 is NOT used,
		* rename pgmspace function to match the macro, and use our implementation
		*/
	#define  pgmspace_strncasecmp      strncasecmp_P

#endif /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L)) */



#if (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L))
	/**
		* standard POSIX.1-2001 is used, strtok_r is provided by compiler,
		* then just declare header without actually using the function
		*/
	char *   pgmspace_strtok_r(char * restrict str, const char * restrict delim,
						char ** restrict saveptr);

/* defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L) */
#else /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L)) */
	/**
		* standard POSIX.1-2001 is NOT used,
		* rename pgmspace function to match the macro, and use our implementation
		*/
	#define  pgmspace_strtok_r         strtok_rP

#endif /* ! (defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE) >= 200112L)) */


/**
	* implementation
	*/

/**
	* this function will only be available if POSIX.1-2008 (or later) not used
	* this function will be renamed to memccpy_P in such case
	*/
void *  pgmspace_memccpy(void * restrict dest, const void * restrict src,
					int c, size_t n)
{
	/* 1. Cast pointers to uint8_t * for byte-by-byte access */
	int8_t       * restrict dst_int8_p   = dest;
	const int8_t * restrict src_int8_p   = src;

	/* 2. Convert the search character to unsigned char (as per standard) */
	int8_t                  search_byte  = (int8_t) c;

	/* iterator loop */
	size_t                  i;

	for (i = 0; i < n; i++)
	{
		/* 3. Copy the current byte from source to destination */
		dst_int8_p[i] = src_int8_p[i];

		/* 4. If the byte we just copied matches the target... */
		if (dst_int8_p[i] == search_byte)
		{
			/* ...return a pointer to the byte IMMEDIATELY AFTER the match */
			return (&(dst_int8_p[i + 1]));
		}
	}

	/* 5. If we reach 'n' bytes without finding 'c', return NULL */
	return NULL;
}


/**
	* this function will only be available if POSIX.1-2008 (or later) not used
	* this function will be renamed to stpcpyP in such case
	*/
char *  pgmspace_stpcpy(char * restrict dst, const char * restrict src)
{
	/* 1. Loop until we find the null terminator in the source */
	while (*src != '\0')
	{
		/* 2. Copy the character and move both pointers forward */
		*dst++ = *src++;
	}

	/* 3. The loop stops at '\0', so we must null-terminate the destination */
	*dst = '\0';

	/* 4. Return the pointer to the null terminator in the destination */
	return dst;
}


/**
	* this function will only be available if POSIX.1-2001 (or later) not used
	* this function will be renamed to strcasecmpP in such case
	*/
int     pgmspace_strcasecmp(const char *s1, const char *s2)
{
	int s1_int, s2_int;

	/* keep looping only if we not found terminating string */
	while (s1_int = *s1++, s2_int = *s2++, (s1_int != 0) && (s2_int != 0))
	{
		int compare_result;

		/* convert case to lowercase */
		s1_int = tolower(s1_int);
		s2_int = tolower(s2_int);

		/* compare character after converted to lowercase */
		compare_result = s1_int - s2_int;
		if (compare_result != 0)
		{
			return compare_result;
		}

		/**
			* if compare_result is 0, keep comparing until found '\0' or
			* found different character
			*/
	}

	/**
		* if we reach this, then we found terminating string
		* return difference
		*/
	return tolower(s1_int) - tolower(s2_int);
}


/**
	* this function will only be available if POSIX.1-2008 (or later) not used
	* this function will be renamed to strnlenP in such case
	*/
size_t  pgmspace_strnlen(const char *s, size_t maxlen)
{
	size_t len = 0;

	/**
		* We loop as long as two conditions are met:
		* 1. We haven't reached the maximum allowed length (maxlen)
		* 2. We haven't found the null terminator ('\0')
		*/
	while ((len < maxlen) && (s[len] != '\0'))
	{
		len++;
	}

	/* Return the count of characters found before the stop condition */
	return len;
}


/**
	* this function will only be available if POSIX.1-2001 (or later) not used
	* this function will be renamed to strncasecmpP in such case
	*/
int     pgmspace_strncasecmp(const char *s1, const char *s2, size_t n)
{
	int s1_int, s2_int;

	/**
		* standard dictate if n == 0, then return 0
		*/
	if (n <= 0)
	{
		return 0;
	}

	/**
		* keep looping only if we not found terminating string
		* and n is more than 1 (2 or more),
		* in case n is 0, just return difference of current character
		*/
	while (s1_int = *s1++, s2_int = *s2++,
		(n-- > 1) && (s1_int != 0) && (s2_int != 0))
	{
		int compare_result;

		/* convert case to lowercase */
		s1_int = tolower(s1_int);
		s2_int = tolower(s2_int);

		/* compare character after converted to lowercase */
		compare_result = s1_int - s2_int;
		if (compare_result != 0)
		{
			return compare_result;
		}

		/**
			* if compare_result is 0, keep comparing until found '\0' or
			* found different character of n is exhausted
			*/
	}

	/**
		* if we reach this, then we found terminating string
		* return difference
		*/
	return tolower(s1_int) - tolower(s2_int);
}


/**
	* this function will only be available if POSIX.1-2001 (or later) not used
	* this function will be renamed to strtok_rP in such case
	*/
char *  pgmspace_strtok_r(char * restrict str, const char * restrict delim,
					char ** restrict saveptr)
{
	char * restrict token_start;

	/**
		* 1. Initialization
		*    If @arg str is NULL, we are continuing a previous search.
		*    We resume from the address stored in (pointed by) @arg saveptr.
		*/
	if (str == NULL)
	{
		str = *saveptr;
	}

	/**
		* 2. Skip leading delimiters
		*    strspn (_P) returns the length of the initial segment consisting
		*    entirely of characters from @arg delim.
		*/
	str += strspn_P(str, delim);

	/* 3. Check if the string is exhausted */
	if (*str == '\0')
	{
		/* set saveptr to end of input string */
		*saveptr = str;

		return NULL; /* not found delimiter */
	}

	/* 4. Mark the beginning of the token */
	token_start = str;

	/**
		* 5. Find the end of the token
		*    strpbrk finds the first occurrence of any character
		*    from @arg delim.
		*/
	str = strpbrk_P(token_start, delim);

	/* check strpbrk_P result */
	if (str == NULL)
	{
		/* No more delimiters found.
		*  The token goes to the end of the string. */
		*saveptr = strchr_P(token_start, '\0');
	}
	else
	{
		/* We found a delimiter.
		*  Null-terminate the token and update saveptr for the next call. */
		*str = '\0';
		*saveptr = str + 1;
	}

	return token_start;
}
