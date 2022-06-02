#include <stdio.h>

// how to declare and iterate over arrays

int main() {
    int intArray[100];      // an array of 100 integers

    for(int i=0; i<100; i++) {      // iterate over every array element, initialize, and print the value
        intArray[i] = i * 2;
        printf("intArray[%d] = %d\n", i, intArray[i]);
    }
    
    return 0;
}
