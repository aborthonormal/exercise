/* 
test_roman_calc.c

Andrew Howard - 2016

Program used to test functions of the Roman numeral calculator library, libromancalc.  
This program uses the Check library, libcheck, to run a series of tests on the 
functions for conversion, addition, and subtraction.  

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <check.h>

#include "roman_numeral_calc.h"

//Test for the decimal to Roman numeral conversion function.  
START_TEST(convert_decimal_to_roman_test) {

	//Allocate the C string "numeral" to store the results of the 
	//conversion function.  
	char * numeral = (char*)malloc(sizeof(char) * (strlen(MAX_LENGTH_ROMAN)+1));
	memset(numeral, 0, strlen(MAX_LENGTH_ROMAN)+1);


	//Check that the conversion function returns the correct flag when proper and improper input is provided.  
	
	//correct input
	int flag = decimal_to_roman(1, numeral);
	ck_assert_int_eq(flag, 0);

	//incorrect inputs
	flag = decimal_to_roman(0, numeral);
	ck_assert_int_eq(flag, 1);

	flag = decimal_to_roman(4000, numeral);
	ck_assert_int_eq(flag, 1);

	flag = decimal_to_roman(1, NULL);
	ck_assert_int_eq(flag, 1);


	//Check if various conversions from decimal to Roman numerals work.

	//1 -> I
	decimal_to_roman(1, numeral);
	ck_assert_str_eq(numeral, "I");
	
	//3 -> III
	decimal_to_roman(3, numeral);
	ck_assert_str_eq(numeral, "III");

	//4 -> IV
	decimal_to_roman(4, numeral);
	ck_assert_str_eq(numeral, "IV");
	
	//5 -> V
	decimal_to_roman(5, numeral);
	ck_assert_str_eq(numeral, "V");
	
	//9 -> IX
	decimal_to_roman(9, numeral);
	ck_assert_str_eq(numeral, "IX");
	
	//10 -> X
	decimal_to_roman(10, numeral);
	ck_assert_str_eq(numeral, "X");
	
	//30 -> XXX
	decimal_to_roman(30, numeral);
	ck_assert_str_eq(numeral, "XXX");
	
	//40 -> XL
	decimal_to_roman(40, numeral);
	ck_assert_str_eq(numeral, "XL");
	
	//50 -> L
	decimal_to_roman(50, numeral);
	ck_assert_str_eq(numeral, "L");
	
	//80 -> LXXX
	decimal_to_roman(80, numeral);
	ck_assert_str_eq(numeral, "LXXX");
	
	//100 -> C
	decimal_to_roman(100, numeral);
	ck_assert_str_eq(numeral, "C");
	
	//287 -> CCLXXXVII
	decimal_to_roman(287, numeral);
	ck_assert_str_eq(numeral, "CCLXXXVII");
	
	//288 -> CCLXXXVIII
	decimal_to_roman(288, numeral);
	ck_assert_str_eq(numeral, "CCLXXXVIII");
	
	//300 -> CCC
	decimal_to_roman(300, numeral);
	ck_assert_str_eq(numeral, "CCC");
	
	//400 -> CD
	decimal_to_roman(400, numeral);
	ck_assert_str_eq(numeral, "CD");
	
	//500 -> D
	decimal_to_roman(500, numeral);
	ck_assert_str_eq(numeral, "D");
	
	//800 -> DCCC
	decimal_to_roman(800, numeral);
	ck_assert_str_eq(numeral, "DCCC");

	//1000 -> M
	decimal_to_roman(1000, numeral);
	ck_assert_str_eq(numeral, "M");

	//3000 -> MMM
	decimal_to_roman(3000, numeral);
	ck_assert_str_eq(numeral, "MMM");

	//900 -> CM
	decimal_to_roman(900, numeral);
	ck_assert_str_eq(numeral, "CM");

	//2900 -> MMCM
	decimal_to_roman(2900, numeral);
	ck_assert_str_eq(numeral, "MMCM");


	//Free memory assigned to "numeral"
	free(numeral);
}
END_TEST

//Test for the Roman numeral to decimal conversion function.  
START_TEST(convert_roman_to_decimal_test) {

	//integer to store the returned converted number
	int decimal = 0;
	
	//Check if various conversions from Roman numerals to decimal 
	//numbers work.
	
	//I -> 1
	roman_to_decimal("I", &decimal);
	ck_assert_int_eq(decimal, 1);
	
	//III -> 3
	roman_to_decimal("III", &decimal);
	ck_assert_int_eq(decimal, 3);
	
	//IV -> 4
	roman_to_decimal("IV", &decimal);
	ck_assert_int_eq(decimal, 4);
	
	//V -> 5
	roman_to_decimal("V", &decimal);
	ck_assert_int_eq(decimal, 5);
	
	//VIII -> 8
	roman_to_decimal("VIII", &decimal);
	ck_assert_int_eq(decimal, 8);
	
	//IX -> 9
	roman_to_decimal("IX", &decimal);
	ck_assert_int_eq(decimal, 9);
	
	//X -> 10
	roman_to_decimal("X", &decimal);
	ck_assert_int_eq(decimal, 10);
	
	//XXX -> 30
	roman_to_decimal("XXX", &decimal);
	ck_assert_int_eq(decimal, 30);
	
	//XL -> 40
	roman_to_decimal("XL", &decimal);
	ck_assert_int_eq(decimal, 40);
	
	//L -> 50
	roman_to_decimal("L", &decimal);
	ck_assert_int_eq(decimal, 50);
	
	//LXXX -> 80
	roman_to_decimal("LXXX", &decimal);
	ck_assert_int_eq(decimal, 80);
	
	//XC -> 90
	roman_to_decimal("XC", &decimal);
	ck_assert_int_eq(decimal, 90);
	
	//C -> 100
	roman_to_decimal("C", &decimal);
	ck_assert_int_eq(decimal, 100);
	
	//CCC -> 300
	roman_to_decimal("CCC", &decimal);
	ck_assert_int_eq(decimal, 300);
	
	//CCLXXXVII -> 287
	roman_to_decimal("CCLXXXVII", &decimal);
	ck_assert_int_eq(decimal, 287);
	
	//CCLXXXVIII -> 288
	roman_to_decimal("CCLXXXVIII", &decimal);
	ck_assert_int_eq(decimal, 288);
	
	//CD -> 400
	roman_to_decimal("CD", &decimal);
	ck_assert_int_eq(decimal, 400);
	
	//D -> 500
	roman_to_decimal("D", &decimal);
	ck_assert_int_eq(decimal, 500);
	
	//DCCC -> 800
	roman_to_decimal("DCCC", &decimal);
	ck_assert_int_eq(decimal, 800);
	
	//CM -> 900
	roman_to_decimal("CM", &decimal);
	ck_assert_int_eq(decimal, 900);
	
	//M -> 1000
	roman_to_decimal("M", &decimal);
	ck_assert_int_eq(decimal, 1000);
	
	//MCM -> 1900
	roman_to_decimal("MCM", &decimal);
	ck_assert_int_eq(decimal, 1900);
	
	//MMCM -> 2900
	roman_to_decimal("MMCM", &decimal);
	ck_assert_int_eq(decimal, 2900);
	
	//MMM -> 3000
	roman_to_decimal("MMM", &decimal);
	ck_assert_int_eq(decimal, 3000);
	
	//MMMCM -> 3900
	roman_to_decimal("MMMCM", &decimal);
	ck_assert_int_eq(decimal, 3900);
	
	//Test if input Roman numeral string is valid.  
	int flag = 0;
	
	//Correct input
	flag = roman_to_decimal("MMMCM", &decimal);
	ck_assert_int_eq(flag, 0);
	
	//Incorrect input
	flag = roman_to_decimal("MMMIICM", &decimal);
	ck_assert_int_eq(flag, 1);
	
	//Incorrect input
	flag = roman_to_decimal("IIII", &decimal);
	ck_assert_int_eq(flag, 1);
	
	//Incorrect input
	flag = roman_to_decimal("absC", &decimal);
	ck_assert_int_eq(flag, 1);

	//Incorrect input
	flag = roman_to_decimal(NULL, &decimal);
	ck_assert_int_eq(flag, 1);
	
	//Incorrect input
	flag = roman_to_decimal("IV", NULL);
	ck_assert_int_eq(flag, 1);	
}
END_TEST

/* Test both the decimal_to_roman() and roman_to_decimal() functions by converting all integers 1-3999 to Roman numerals, then back to decimal, and then comparing the results to the inputs. */
START_TEST(double_conversion_test) {

	//String used for Roman numeral.  
	char * numeral = (char*)malloc(sizeof(char) * (strlen(MAX_LENGTH_ROMAN)+1));
	memset(numeral, 0, strlen(MAX_LENGTH_ROMAN)+1);

	//Integer used for result of roman_to_decimal() conversion.  
	int decimal;

	//Check every integer from 1-3999.
	for(int i=0; i <= MAX_DECIMAL; i++) {
	
		//Convert from decimal to Roman numeral and then back again. 
		decimal_to_roman(i, numeral);		
		roman_to_decimal(numeral, &decimal);
		
		//Two numbers should be equal.  
		ck_assert_int_eq(decimal, i);
	}
	
	//Free memory of string.  
	free(numeral);
}
END_TEST

/* Test the roman_addition() function.  Whole numbers that sum up to anywhere within 2-3999 are converted to Roman numerals, those are passed to the addition function, the resulting roman numeral is converted back to decimal, and the result is compared.  Thorough testing of the conversion functions allows us to conduct this test with confidence.  */
START_TEST(roman_addition_test) {

	//Strings used for additions
	//First Roman numeral
	char * numeral_a = (char*)malloc(sizeof(char) * (strlen(MAX_LENGTH_ROMAN)+1));
	memset(numeral_a, 0, strlen(MAX_LENGTH_ROMAN)+1);
	
	//Second Roman numeral
	char * numeral_b = (char*)malloc(sizeof(char) * (strlen(MAX_LENGTH_ROMAN)+1));
	memset(numeral_b, 0, strlen(MAX_LENGTH_ROMAN)+1);
	
	//Roman numeral sum
	char * numeral_sum = (char*)malloc(sizeof(char) * (strlen(MAX_LENGTH_ROMAN)+1));
	memset(numeral_sum, 0, strlen(MAX_LENGTH_ROMAN)+1);

	//Integers for addition operands.  
	int a, b;

	//Integer used to store decimal conversion of sum.  
	int decimal;
	
	//Flag to check for failure condition from roman_addition()
	int flag = 0;
	
	//Set seed for random number generator.  
	srand(time(NULL));
	
	//Try many random values for a and b that sum up to less than 
	//3999. Initial idea to test all whole numbers that sum to 3999 
	//resulted in a timeout error with the libcheck function.  
	for(int i=0; i<10000; i++) {

		//Sum a+b is between 1-3999
		a = (rand() % (MAX_DECIMAL-1)) + 1;
		b = (rand() % (MAX_DECIMAL-a)) + 1;

		//Convert operands to Roman numerals.  
		decimal_to_roman(a, numeral_a);
		decimal_to_roman(b, numeral_b);
	
		//Add Roman numerals, check flag for failure.  
		flag = roman_addition(numeral_a, numeral_b, numeral_sum);
		ck_assert_int_eq(flag, 0);
	
		//Convert Roman numeral sum to decimal.  
		roman_to_decimal(numeral_sum, &decimal);

		//Compare the result to the inputs.  
		ck_assert_int_eq(decimal, (a+b));
	}
}
END_TEST

/* This function creates the test Suite structure, with the test cases added to it.  
The test suite is then run within the main function.  */
static Suite *create_test_suite(void) {

	//Suite struct
	Suite *s;

	//test case struct
	TCase *tc_core;

	//Initialize the test suite. 
	s = suite_create("Roman Calc Test Suite");

	//Create a single test case that consits of several tests of the 
	//Roman numeral calculator's functions.  
	tc_core = tcase_create("Core");

	//Add the test for decimal to Roman conversion to the test case.  
	tcase_add_test(tc_core, convert_decimal_to_roman_test);
	
	//Add the test for Roman to decimal conversion to the test case.  
	tcase_add_test(tc_core, convert_roman_to_decimal_test);

	//Add the test for double conversion, an broad test of both conversion functions.  
	tcase_add_test(tc_core, double_conversion_test);
	
	//Add the test for the addition function.  
	tcase_add_test(tc_core, roman_addition_test);

	//Add the test case to the tese suite.  
	suite_add_tcase(s, tc_core);

	//Return the finished test suite.  
	return s;
}

/* As a test program, the main function will simply run the test suite, which consists of a main test case and the small tests for the calculator's functions.  */
int main(void) {

	//Count the number of tests failed.  
	int number_failed;

	//Structs for test suite and suite runner
	Suite *s;
	SRunner *sr;

	//Create the test suite.  
	s = create_test_suite();

	//Create the runner for the test suite. 
	sr = srunner_create(s);

	//Run all tests of the test suite.  
	srunner_run_all(sr, CK_NORMAL);

	//Count the number of tests that failed.  
	number_failed = srunner_ntests_failed(sr);

	//Delete the suite runner.  
	srunner_free(sr);

	//The program will exit with a failure if a test fails.  
	return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
