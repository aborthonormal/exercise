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
#include <check.h>
#include "roman_numeral_calc.h"

//Test for the decimal to Roman numeral conversion function.  
START_TEST(convert_decimal_to_roman_test) {

	//Allocate the C string "numeral" to store the results of the 
	//conversion function.  
	char * numeral = (char*)malloc(sizeof(char) * (strlen(MAX_ROMAN)+1));
	memset(numeral, 0, strlen(MAX_ROMAN)+1);


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

	//4 -> IV
	decimal_to_roman(4, numeral);
	ck_assert_str_eq(numeral, "IV");

	//1000 -> M
	decimal_to_roman(1000, numeral);
	ck_assert_str_eq(numeral, "M");

	//3000 -> MMM
	decimal_to_roman(3000, numeral);
	ck_assert_str_eq(numeral, "MMM");


	//Free memory assigned to "numeral"
	free(numeral);
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
