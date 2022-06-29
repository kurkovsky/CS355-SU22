// a demo of the curses library
// use the following command to compile:
// gcc -lncurses filename.c

#include <curses.h>
#include <stdio.h>
#include <unistd.h>     // for usleep()
#include <stdlib.h>     // for atoi()

int main(int ac, char *av[]) {
    int speed=1;            // speed of the animations
    if(ac==2)
        speed=atoi(av[1]);  // convert a char* to an int
    initscr();              // initialize the curses library
    printf("The screen is %d rows by %d columns", LINES, COLS);
    getchar();              // pause the program to wait for a keyboard input
    clear();                // clear the screen
    for(int i=0; i<LINES; i++) {
        move(i,i*3);                // move the cursor to a position on the diagonal
        addstr("Hello, world!");    // draw a string in the current position
        refresh();                  // update the screen
        usleep(1000000/speed);      // pause the process
        move(i,i*3);                // move back
        addstr("             ");    // erase the line
    }
    endwin();                // turn off curses
}
