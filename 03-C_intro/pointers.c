#include <stdio.h>

// introduction to pointers

int main() {
    int x = 5;      // just a regular integer
    int *p = 0;     // an integer pointer

    // print the value of x and p
    // this prints the actual address contained in p
    printf("x = %2d, p = %p\n", x, p);

    // this would result in a segmentation fault due
    // to an attempt to dereference a null pointer
    // printf("x = %2d, *p = %2d, p = %p\n", x, *p, p);


    p = &x;         // p now points to x
    printf("x = %2d, *p = %2d, p = %p\n", x, *p, p);

    x = 15;         // change the value of x
    printf("x = %2d, *p = %2d, p = %p\n", x, *p, p);

    *p = 17;        // change the value pointed to by p
    printf("x = %2d, *p = %2d, p = %p\n", x, *p, p);

    int y = 50;     // another regular integer
    printf("x = %2d, y = %2d, *p = %2d, p = %p\n", x, y, *p, p);

    p = &y;         // p now points to y
    printf("x = %2d, y = %2d, *p = %2d, p = %p\n", x, y, *p, p);
    
    return 0;
}
