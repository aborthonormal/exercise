/* 
roman_numeral_calc.h

Header file for the Roman numeral calculator library, libromancalc. 

*/

#ifndef ROMAN_NUMERAL_CALC_H
#define ROMAN_NUMERAL_CALC_H

/* Constants for minimum and maximum Roman numerals and decimal numbers.  The longest Roman numeral string is not the same as the largest valued Roman numeral string. */
#define MAX_LENGTH_ROMAN "MMMDCCCLXXXVIII"
#define MAX_VALUE_ROMAN "MMMCMXCIX"
#define MIN_VALUE_ROMAN "I"
#define MAX_DECIMAL 3999
#define MIN_DECIMAL 1

/* Convert decimal numbers (1-3999) to Roman numerals.  The function writes to a C string provided by the caller.  The array must be large enough to store the characters of the numerals and the null-terminating character.  A '0' value is returned if the conversion was successful.  A '1' value is returned if the conversion fails due to invalid input. */ 
int decimal_to_roman(const int decimal, char * numeral);


/* Convert Roman numerals to decimal numbers in the range 1-3999.  The function is passed a C string containing the Roman numerals to convert and a pointer to the integer variable that will receive the converted decimal value.  A '0' value is returned if the conversion was successful.  A '1' value is returned if the conversion fails due to invalid input. */
int roman_to_decimal(const char * numeral, int * decimal);

/* Add two Roman numerals.  The addition is performed by converting both Roman numeral operands to decimal, adding the decimal numbers, and then converting the result to Roman numerals.  The sum must be less than 3999 for the addition to succeed. A '0' value is returned if the addition succeeds.  A '1' value is returned if the addition fails, either due to a failed conversion or the sum is too large.  */
int roman_addition(const char * numeral_a, const char * numeral_b, char * numeral_sum);

#endif
