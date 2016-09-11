/* 
roman_numeral_calc.h

Header file for the Roman numeral calculator library, libromancalc. 

*/

#ifndef ROMAN_NUMERAL_CALC_H
#define ROMAN_NUMERAL_CALC_H

//Constants for minimum and maximum Roman numerals and decimal numbers. 
#define MAX_ROMAN "MMMCMXCIX"
#define MIN_ROMAN "I"
#define MAX_DECIMAL 3999
#define MIN_DECIMAL 1

/* Convert decimal numbers (1-3999) to Roman numerals.  The function writes to a C string character array provided by the caller.  The array must be large enough to store the characters of the numerals and the null-terminating character.  A '0' value is returned if the conversion was successful.  A '1' value is returned if the conversion fails for any reason. */ 
int decimal_to_roman(const int decimal, char * numeral);

#endif
