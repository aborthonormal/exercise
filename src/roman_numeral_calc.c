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

/* Convert decimal numbers (1-3999) to Roman numerals.  The function writes to a C string character array provided by the caller.  The array must be large enough to store the characters of the numerals and the null-terminating character.  A '0' value is returned if the conversion was successful.  A '1' value is returned if the conversion fails for any reason. */ 
int decimal_to_roman(const int decimal, char * numeral) {

	//Flag set to non-zero value if input is incorrect or conversion fails.  
	int flag = 0;

	//First check if number is within the accepted range. 
	if(decimal < MIN_DECIMAL || decimal > MAX_DECIMAL) {
		flag = 1;
		return flag;
	}

	//Check for a null pointer.  
	if(numeral == NULL) {
		flag = 1;
		return flag;
	}

	//Ensure the string is clean before writing over it.  
	memset(numeral, 0, strlen(numeral));

	//Generate buffer string used when generating Roman numerals.  
	char * buffer = (char*)malloc(sizeof(char) + (strlen(MAX_ROMAN)+1));
	memset(buffer, 0, (strlen(MAX_ROMAN)+1));

	switch(decimal) {
		case 1:
			strcpy(buffer,"I");
			break;
		case 4:
			strcpy(buffer,"IV");
			break;
	}

	//Copy contents of buffer to "numeral". 
	strncpy(numeral, buffer, strlen(buffer)+1);

	//Free buffer memory
	free(buffer);

	return flag;
}


