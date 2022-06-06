// how to read from the UTMP structure

#include <utmp.h>
#include <unistd.h>   // aka UNIX Standard; POSIX (Portable OS Interface) API incl read/write
#include <fcntl.h>    // aka File Control; POSIX API for open/close
#include <stdio.h>

/*
pseudocode to implement our very basic version of the built-in who command
    open utmp
    repeat
        read utmp record
        display utmp record
    close utmp
*/

int main() {
    struct utmp currentRecord;              // a single UTMP record will be stored here
    int intUTMPfile;                        // a file descriptor to work with the UTMP file
    int intUTMPlength=sizeof(currentRecord);// how many bytes are there in a UTMP record
    // UTMP_FILE is a #define that contains the current path of the UTMP file
    printf("UTMP file is %s\n", UTMP_FILE);
    intUTMPfile=open(UTMP_FILE, O_RDONLY);  // open the UTMP file
    if(intUTMPfile==-1) {                   // check if it was open successfully
        perror(UTMP_FILE);                  // any error message will be determined by the value
        return 1;                           // of variable errno (per POSIX standards)
    }
    // read and print all UTMP records, one at a time
    while(read(intUTMPfile, &currentRecord, intUTMPlength)==intUTMPlength) {
        printf("%s %s\n", currentRecord.ut_user, currentRecord.ut_host);
    }
    close(intUTMPfile);
    return 0;
}