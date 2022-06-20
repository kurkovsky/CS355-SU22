/*
A simple scaffolding to implement myfind (lab 8)
based on the long_ls example
*/

 #include <stdio.h>
 #include <dirent.h>
 #include <sys/stat.h>
 #include <string.h>


// this function is called for every encountered directory entry
void process_entry(char *dir_entry_name) {
    struct stat info;
    if(stat(dir_entry_name, &info)==-1)
        perror(dir_entry_name);
    else {
        if(S_ISDIR(info.st_mode)) {      // if this directory entry is a subdirectory
            printf("%s is a directory\n", dir_entry_name);
            // do_find(dir_entry_name);  // explore this subdirectory
        }
        if(1) { // use strstr() to check if the current directory entry's name matches the substring
            printf("Directory entry: %s\n", dir_entry_name);
        }
    }
}

// explore all entries of the given directory
void do_find(char *dir_name) {
    DIR *dir_ptr;               // pointer to a directory structure
    struct dirent *dirent_ptr;  // pointer to the current directory entry
    dir_ptr = opendir(dir_name);
    if(dir_ptr==0) {            // opendir could fail, possibly because
        perror(dir_name);       // the directory does not exist
    }
    else {                      // iterate over all directory entries
        while((dirent_ptr=readdir(dir_ptr)) != 0) {
            process_entry(dirent_ptr->d_name);
        }
        closedir(dir_ptr);
    }
}

int main() {
    do_find(".");                 // explore the contents of the current directory
    return 0;
}
