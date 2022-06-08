/*
An implementation of a very basic verison of cp:
copy a source file into a destination file

Pseudocode:
    open sourcefile for reading
    open destinationfile for writing
    while not EOF
        read from sourcefile into buffer
        write from buffer into destinationfile
    close sourcefile
    close destinationfile
 */

 #include <stdio.h>
 #include <unistd.h>
 #include <fcntl.h>

 #define COPYMODE 0644      // corresponds to -rw-r--r-- file permissions
 #define BUFFERSIZE 1024

 int main(int ac, char *av[]) {
    int src, dst;  // source and destination files
    char buffer[BUFFERSIZE];
    int numBytes;

    if(ac!=3) {    // this program must be used with exactly two parameters
        printf("Usage: %s source destination\n", av[0]);
        return 1;
    }

    src=open(av[1], O_RDONLY); // attempt to open the source file
    if(src<0) {
        perror(av[1]);
        return 1;
    }

    dst=creat(av[2], COPYMODE); // attempt to open the destination file
    if(dst<0) {
        perror(av[2]);
        return 1;
    }

  /*
    What happens when read() is called several times: at the last iteration,
    read() will not be able to read the entire buffer worth of data
    Source file content: [-----   -----   -----   -----   ---]
    Buffer content:      [=====] [=====] [=====] [=====] [===]
    Iterations:             1       2       3       4      5
    */

    int iteration = 1; // we may use this to trace the number of
                       // iterations used by this program depending
                       // on the buffer size in order to discuss the
                       // effects of user/supervisor mode switching

    // attempt read the entire buffer[] worth of data in a loop,
    // as long as there is data to be read from the file,
    // i.e. until we reach the end of file
    while((numBytes=read(src,buffer,BUFFERSIZE))>0) {
        // if the number of bytes obtained by read() is not the same
        // as the number of bytes written by write()
        if(write(dst,buffer,numBytes)!=numBytes) {
            perror("Write error");
            return 1;
        }
        printf("Iteration %d, bytes read %d\n", iteration, numBytes);
        iteration++;
    }

    // what if, although the source file was succesfully open,
    // it was not possible to read from it
    if(numBytes<0) {
        perror("Read error");
        return 1;
    }

	// attempt to close both files
    if(close(src)<0 || close(dst)<0) {
        perror("Error closing files");
        return 1;
    }
    return 0;
 }
