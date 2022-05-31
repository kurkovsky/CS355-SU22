#include <stdio.h>

// Atomic/primitive data types in C

int main() {
    int iNumber = 0;                // an integer
    unsigned uUnsigned = 100;       // an unsigned integer
    float fStuff = 10.1;            // a floating point number
    double dDoubleStuff = 10.111;   // a floating point number with double precision
    char cLetter='A';               // a character

    // Every character has a numeric (ASCII) code associated with it
    // C treats characters as integers
    printf("The value of cLetter is %d, which is '%c'\n", cLetter, cLetter);
	return 0;                   // indicates a successful completion of the program

}