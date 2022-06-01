#include <stdio.h>

// how to work with user-defined functions
// also: pass by value, pass by reference

// function declarations
int product1(int, int);
int product2(int, int);
int product3(int, int*);

int main() {
    int a, b;
    printf("Please enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("You entered %d and %d\n", a, b);

    int tmp1 = product1(a, b);
    printf("Product1: %d * %d = %d\n", a, b, tmp1);

    int tmp2 = product2(a, b);
    printf("Product2: %d * %d = %d\n", a, b, tmp2);

    int tmp3 = product3(a, &b);
    printf("Product3: %d * %d = %d\n", a, b, tmp3);

    return 0;
}

// a straightforward implementation of a function that calculates the product of two integers
// both parameters are passed by value
int product1(int x, int y) {
    int result = x * y;
    return result;
}

// similar to above, but with possible side effects that do not work due to pass by value
int product2(int x, int y) {
    int result = x * y;
    x = 5;
    y = 10;
    return result;
}

// similar to above, but with one parameter passed by reference
// this implementationn DOES have side effects
int product3(int x, int *y) {
    int result = x * (*y);
    x = 5;
    *y = 10;
    return result;
}