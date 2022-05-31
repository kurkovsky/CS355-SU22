#include <stdio.h>

// Your second ever program in C

int main() {
    printf("Hello, world!\n");      // good old "Hello, world!"
    printf("This is ");             // What if we split the string into three lines
    printf("the most important ");  // using three different printf() calls?
    printf("class in CS\n");        // This still results in one line of output
                                    // because there's only one new line character ('\n')
    return 0;                       // indicates a successful completion of the program
}