#include <stdio.h>

// Using conditions in C

int main(){
    int iAge=0;
    printf("How old are you? ");

    // Read a value from the terminal and verify that
    // it was interpreted correctly by scanf()
    int iReturnValue = scanf("%d", &iAge);
    if(iReturnValue!=1) {
        printf("scanf() could not interpret your input!\n");
        return 1;
    }
    //printf("You told me that you are %d years old.\n", iAge);

    if(iAge>=0 && iAge<=110) {
        if(iAge<21) {
            printf("You cannot legally enjoy alcoholic beverages.\n");
        }
        else {
            printf("Hello! Your age is %d\n", iAge);
        }
    }
    else
        printf("You entered an invalid age: %d\n", iAge);
    return 0;
}