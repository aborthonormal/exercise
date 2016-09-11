# Library Makefile - Generate the static library for the Roman numeral 
# calculator functions.  
# ------------------------

all: libromancalc

libromancalc: roman_numeral_calc.o
	ar -cvq libromancalc.a roman_numeral_calc.o

roman_numeral_calc.o: 
	gcc -Wall -c -std=c99 -fPIC ../src/roman_numeral_calc.c -I../include/ -I../src/

clean:
	rm roman_numeral_calc.o libromancalc.a
