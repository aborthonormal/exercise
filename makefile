# Makefile for testing program.  

all: libromancalc test_roman_calc

libromancalc:
	cd util; make

test_roman_calc: test_roman_calc.o
	gcc -o test_roman_calc test_roman_calc.o -Lutil -lromancalc -lcheck -lpthread -lm -lrt

test_roman_calc.o: test_roman_calc.c
	gcc -c test_roman_calc.c -Iinclude/

clean:
	cd util; make clean
	rm test_roman_calc.o test_roman_calc
