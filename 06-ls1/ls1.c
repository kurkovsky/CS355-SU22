/*
A very basic implementation of ls:
list the names of all directory entries

Pseudocode:
    open directory
    while not end of directory
        read directory entry
        display entry info
    close directory
 */

 #include <stdio.h>
 #include <dirent.h>


// lists all entries of the given directory
void do_ls(char *dir_name) {
    DIR *dir_ptr;               // pointer to a directory structure
    struct dirent *dirent_ptr;  // pointer to the current directory entry
    dir_ptr = opendir(dir_name);
    // The line below if equivalent to this:
    // if(!dir_ptr) {
    if(dir_ptr==0) {            // opendir could fail, possibly because
        perror(dir_name);       // the directory does not exist
    }
    else {                      // iterate over all directory entries
        while((dirent_ptr=readdir(dir_ptr)) != 0) {
            printf("Directrory entry: %s\n", dirent_ptr->d_name);
        }
        closedir(dir_ptr);
    }
}

int main() {
    do_ls(".");                 // list the contents of the current directory
    return 0;
}
