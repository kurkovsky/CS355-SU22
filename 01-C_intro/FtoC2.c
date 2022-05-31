#include <stdio.h>

// This program converts temperature values from Fahrenheit to Celsius
// modified to accept user input using scanf()

int main() {
    float fCelsius, fFahrenheit;         // both temperature variables are declared as floating point numbers
    printf("Please enter temperature is Fahrenheit: ");
    scanf("%f", &fFahrenheit);
    fCelsius = (fFahrenheit - 32) / 9 * 5;      // the conversion formula is exactly the same, but the result will preserve the fractional values
    printf("%2.1fF is %2.1fC\n", fFahrenheit, fCelsius);
    return 0;                   // indicates a successful completion of the program

}