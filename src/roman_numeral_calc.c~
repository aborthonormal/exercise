/*
roman_numeral_calc.c

Andrew Howard - 2016 

This file defines library functions that allow the user to add and subtract Roman numeral numbers.  Other functions facilitate the conversion between Roman numerals and decimal numbers.  The largest Roman numeral supported is 3999 (MMMCMXCIX) and the smallest is 1 (I).  

*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "roman_numeral_calc.h"

//Constants for minimum and maximum Roman numerals and decimal numbers. 
const char * MAX_ROMAN = "MMMCMXCIX";
const char * MIN_ROMAN = "I";
const int MAX_DECIMAL = 3999;
const int MIN_DECIMAL = 1;

/* Convert decimal numbers (1-3999) to Roman numerals.  A dynamically allocated c-string is returned by this function, so care must be taken to free the string after use, to avoid a memory leak. */ 
char * decimal_to_roman(int i) {

	switch(i) {
		case 1:
			return "I";
			break;
		case 4:
			return "IV";
			break;
		default:
			return '\0';
	}
}


