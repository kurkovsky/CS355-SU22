#include <stdio.h>

// This program converts temperature values from Fahrenheit to Celsius

int main() {
    int iCelsius, iFahrenheit = 98;             // both temperature variables are declared as integers
    iCelsius = (iFahrenheit - 32) / 9 * 5;      // the result will always be an integer
    printf("%dF is %dC\n", iFahrenheit, iCelsius);

    float fCelsius, fFahrenheit = 98.6;         // both temperature variables are declared as floating point numbers
    fCelsius = (fFahrenheit - 32) / 9 * 5;      // the conversion formula is exactly the same, but the result will preserve the fractional values
    printf("%6.1fF is %2.1fC\n", fFahrenheit, fCelsius);
    return 0;                   // indicates a successful completion of the program    
}