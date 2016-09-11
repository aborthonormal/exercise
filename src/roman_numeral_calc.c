/*
roman_numeral_calc.c

Andrew Howard - 2016 

This file defines library functions that allow the user to add and subtract Roman numeral numbers.  Other functions facilitate the conversion between Roman numerals and decimal numbers.  The largest Roman numeral supported is 3999 (MMMCMXCIX) and the smallest is 1 (I).  

*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

	/*
	switch(decimal) {
		case 1:
			strcpy(buffer,"I");
			break;
		case 4:
			strcpy(buffer,"IV");
			break;
	}
	*/

	//Temporary integer to store value of remaining decimal number 
	//as Roman numerals are added to the string.  
	int dtemp = decimal;

	//1000's place of decimal number
	if(dtemp >= 1000) {

		//Count the 1000's in the decimal number.  Rounds down. 
		int n = floor(((float)dtemp)/1000.0);

		//Add 1000's by appending "M" several times.  Maximum of 3. 
		for(int i=0; i<n; i++) {

			//Append "M" to end of numeral buffer string.
			strcat(buffer,"M");

			//Subtract 1000 from decimal value.  
			dtemp -= 1000;
		}
	}
	
	//Remainder of dtemp is between 900 and 999, so Roman 
	//numeral is "CM".
	if(dtemp >= 900) {

		//Append "CM" to end of numeral buffer string.
		strcat(buffer, "CM");

		//Subtract 900 from decimal value.  
		dtemp -= 900;
	}
	
	//Check if dtemp contains 500.   
	if(dtemp >= 500) {
	
		//Append "D" to end of numeral buffer string.
		strcat(buffer, "D");

		//Subtract 500 from dtemp.  
		dtemp -= 500;
	}
	
	//Check if dtemp is between 400 and 499.  
	if(dtemp >= 400) {
		
		//Roman numeral for 400 is "CD".  
		strcat(buffer,"CD");

		//Subract 400 from dtemp.
		dtemp -= 400;
	}
	
	//Check for 100's values between 100 and 399 in dtemp.  
	if(dtemp >= 100) {
	
		//Count the 100's in dtemp. Rounds down. 
		int n = floor(((float)dtemp)/100.0);

		//Add 100's by appending "C" several times.  Maximum of 3. 
		for(int i=0; i<n; i++) {

			//Append "C" to end of numeral buffer string.
			strcat(buffer,"C");

			//Subtract 100 from remaining decimal value.  
			dtemp -= 100;
		}
	}
	
	//Check if remaining value is between 90 and 99.
	if(dtemp >= 90) {
		
		//Roman numeral for 90 is "XC".  
		strcat(buffer,"XC");

		//Subract 90 from dtemp.
		dtemp -= 90;
	}
	
	//Check if dtemp contains 50.  
	if(dtemp >= 50) {
		
		//Roman numeral for 50 is "L".  
		strcat(buffer,"L");

		//Subract 50 from dtemp.
		dtemp -= 50;
	}
	
	//Check if dtemp is between 40 and 49.  
	if(dtemp >= 40) {
		
		//Roman numeral for 40 is "XL".  
		strcat(buffer,"XL");

		//Subract 40 from dtemp.
		dtemp -= 40;
	}
	
	//Check for 10's values between 10 and 39 in dtemp.  
	if(dtemp >= 10) {
	
		//Count the 10's in dtemp. Rounds down. 
		int n = floor(((float)dtemp)/10.0);

		//Add 10's by appending "X" several times.  Maximum of 3. 
		for(int i=0; i<n; i++) {

			//Append "X" to end of numeral buffer string.
			strcat(buffer,"X");

			//Subtract 10 from remaining decimal value.  
			dtemp -= 10;
		}
	}
	
	//Check if remaining value is between 1 and 9.
	if(dtemp >= 9) {
		
		//Roman numeral for 9 is "IX".  
		strcat(buffer,"IX");

		//Subract 90 from dtemp.
		dtemp -= 9;
	}
	
	//Check if dtemp contains 5.  
	if(dtemp >= 5) {
		
		//Roman numeral for 5 is "V".  
		strcat(buffer,"V");

		//Subract 50 from dtemp.
		dtemp -= 5;
	}
	
	//Check if dtemp is 4.  
	if(dtemp >= 4) {
		
		//Roman numeral for 4 is "IV".  
		strcat(buffer,"IV");

		//Subract 4 from dtemp.
		dtemp -= 4;
	}
	
	//Check for 1's values between 1 and 3 in dtemp.  
	if(dtemp >= 1) {
	
		//Count the 1's in dtemp. Rounds down. 
		int n = floor(((float)dtemp)/1.0);

		//Add 1's by appending "I" several times.  Maximum of 3. 
		for(int i=0; i<n; i++) {

			//Append "I" to end of numeral buffer string.
			strcat(buffer,"I");

			//Subtract 10 from remaining decimal value.  
			dtemp -= 1;
		}
	}

	//Copy contents of buffer to "numeral". 
	strncpy(numeral, buffer, strlen(buffer)+1);

	//dtemp should equal zero now, with all value extracted and 	
	//converted to Roman numerals.  If not, something went wrong.  
	if(dtemp != 0) {
		flag = 1;
		return flag;
	}

	//Free buffer memory
	free(buffer);

	return flag;
}


