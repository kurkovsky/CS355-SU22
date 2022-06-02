#include <stdio.h>

// how to work with command line parameters

int main(int argc, char *argv[]) {      // argc: argument count
    for(int i=0; i<argc; i++) {         // argv: argument values
        printf("Parameter %d: %s\n", i, argv[i]);
    }
}
