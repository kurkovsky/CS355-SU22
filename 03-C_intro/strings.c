#include <stdio.h>
#include <string.h> // standard C string library

// how to work with strings in C

int main() {
    char *string1 = "Hello, world!";    // a pointer to a string constant

    // This will result in a segmentation fault because we cannot
    // modify a string constant
    // string1[5] = 'X';

    printf("string1: %s\n", string1);

    char string2[25] = "Hello, world!"; // a character array
    printf("string2: %s\n", string2);

    // print all characters in string2 including the terminating 0
    for(int i=0; i<=strlen(string2); i++)
        printf("string2[%d] = %c (%d)\n", i, string2[i], string2[i]);

    // another way to iterate over every character in a string
    // until we encounter the terminating zero
    for(int i=0; string2[i]!=0; i++)
        printf("string2[%d] = %c (%d)\n", i, string2[i], string2[i]);

    // this will not work because the string constant is too long for the array
    //char string3[5] = "This is a long string";

    // this will not work because string2 is an array and
    // cannot be changed using the assignment operator
    // instead, strcpy should be used here
    //string2 = "This is another string";

    // but this works because string1 is a pointer
    string1 = "This is another string";

    // this will cause a segmentation fault because the source string is longer than
    // the number of characters that string2 can hold
    //strcpy(string2, "This is yet another string, but it is really long");

    printf("str1: %s\n", string1);
    printf("str2: %s\n", string2);

    return 0;
}