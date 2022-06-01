#include <stdio.h>

// For loops

int main() {
    int i;
    for(i=0; i<10; i++) {       // prints values from 0 to 9 on a single line
        printf("%d ", i);
    }
    printf("\n");

    // display a triangle composed of asterisks
    // the number of asterisks on the line corresponds to the line number
    int line, star;
    for(line=1; line<=10; line++) {         // iterate over every line
        printf("%2d ", line);
        for(star=1; star<=line; star++) {   // iterate over every asterisk on the current line
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
