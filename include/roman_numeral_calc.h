/* 
roman_numeral_calc.h

Header file for the Roman numeral calculator library, libromancalc. 

*/

#ifndef ROMAN_NUMERAL_CALC_H
#define ROMAN_NUMERAL_CALC_H

/* Convert decimal numbers (1-3999) to Roman numerals.  A dynamically allocated c-string is returned by this function, so care must be taken to free the string after use, to avoid a memory leak. */ 
char * decimal_to_roman(int i);

#endif
