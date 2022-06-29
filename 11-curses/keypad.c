// how to capture keyboard input using curses

#include <curses.h>

int main(int ac, char *av[]) {
    initscr();              // initialize the curses library
    clear();                // clear the screen
    curs_set(0);            // hide the cursor
    noecho();               // do not echo the user input to the screen
    keypad(stdscr,TRUE);    // enables working with the arrow keys
    move(0,0);
    addstr("Press any key...");
    while(1){
        int ch=getch();
        move(0,0);

        switch(ch) {
            case KEY_UP:
                addstr("You pressed the UP arrow                         ");
                break;
            case KEY_DOWN:
                addstr("You pressed the DOWN arrow                         ");
                break;
            case KEY_LEFT:
                addstr("You pressed the LEFT arrow                         ");
                break;
            case KEY_RIGHT:
                addstr("You pressed the RIGHT arrow                         ");
                break;
            case 10:
            case KEY_ENTER:
                addstr("You pressed the ENTER key                         ");
                break;
            case 'x':       // pressing 'x' or 'X' will exit the program
            case 'X':
                endwin();   // close curses
                return 0;
            default:
                printw("You pressed a \"%c\" key, ASCII code %d...", (char)ch, ch);
                break;
        }
        refresh();
    }
}