// a demo of using getopt() to parse input flags

#include <stdio.h>
#include <unistd.h>

// these flags match the four options used in cat lab
int flagB=0, flagE=0, flagN=0, flagS=0;

int main(int ac, char *av[]) {
    char option;
    while((option = getopt(ac, av, "bens")) != -1) {
        switch(option) {
            case 'b':
                flagB = 1;
                printf("flag B enabled\n");
                break;
            case 'e':
                flagE = 1;
                printf("flag E enabled\n");
                break;
            case 'n':
                flagN = 1;
                printf("flag N enabled\n");
                break;
            case 's':
                flagS = 1;
                printf("flag S enabled\n");
                break;  
        }
    }
    return 0;
}