#pragma once
// Standard Headers

// Disable tgmath.h C99 conformance warning.
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H

#include <assert.h>				// C   - Contains the assert macro, used to assist with detecting logical errorsand other types of bugs in debugging versions of a program.
#include <complex.h>			// C99 - A set of functions for manipulating complex numbers.
#include <ctype.h>				// C   - Defines set of functions used to classify characters by their types or to convert between upper and lower case in a way that is independent of the used character set(typically ASCII or one of its extensions, although implementations utilizing EBCDIC are also known).
#include <errno.h>				// C   - For testing error codes reported by library functions.
#include <fenv.h>				// C99 - Defines a set of functions for controlling floating - point environment.
#include <float.h>				// C   - Defines macro constants specifying the implementation - specific properties of the floating - point library.
#include <inttypes.h>			// C99 - Defines exact - width integer types.
#include <iso646.h>				// NA1 - Defines several macros that implement alternative ways to express several standard tokens.For programming in ISO 646 variant character sets.
#include <limits.h>				// C   - Defines macro constants specifying the implementation - specific properties of the integer types.
#include <locale.h>				// C   - Defines localization functions.
#include <math.h>				// C   - Defines common mathematical functions.
#include <setjmp.h>				// C   - Declares the macros setjmp and longjmp, which are used for non - local exits.
#include <signal.h>				// C   - Defines signal - handling functions.
//#include <stdalign.h>			// C11 - For querying and specifying the alignment of objects.
#include <stdarg.h>				// C   - For accessing a varying number of arguments passed to functions.
//#include <stdatomic.h>		// C11 - For atomic operations on data shared between threads.
#include <stdbool.h>			// C99 - Defines a boolean data type.
#include <stddef.h>				// C   - Defines several useful types and macros.
#include <stdint.h>				// C99 - Defines exact - width integer types.
#include <stdio.h>				// C   - Defines core input and output functions
#include <stdlib.h>				// C   - Defines numeric conversion functions, pseudo - random numbers generation functions, memory allocation, process control functions
//#include <stdnoreturn.h>		// C11 - For specifying non - returning functions
#include <string.h>				// C   - Defines string - handling functions
#include <tgmath.h>				// C99 - Defines type - generic mathematical functions.
//#include <threads.h>			// C11 - Defines functions for managing multiple threads, mutexesand condition variables
#include <time.h>				// C   - Defines date - and time - handling functions
#include <uchar.h>				// C11 - Types and functions for manipulating Unicode characters
#include <wchar.h>				// NA1 - Defines wide - string - handling functions
#include <wctype.h>				// NA1 - Defines set of functions used to classify wide characters by their types or to convert between upper and lower case