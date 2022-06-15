/*
A simple implementation of ls with the long listing format (-l)
*/

 #include <stdio.h>
 #include <dirent.h>
 #include <sys/stat.h>
 #include <string.h>
 #include <time.h>

/* bitwise operators
a:    0001 1101
b:    0010 1011

a&b:  0000 1001
a|b:  0011 1111

permission bits in the file mode
read  0000 0100
write 0000 0010
exec  0000 0001

rwx   0000 0111

user rwx    0000 0001 1100 0000
group rwx   0000 0000 0011 1000
world rwx   0000 0000 0000 0111
*/

// convert file mode into a printable string
void mode_to_string(int mode, char str[]) {
    strcpy(str,"----------");
    if(S_ISDIR(mode)) str[0]='d'; // directory?
    if(S_ISCHR(mode)) str[0]='c'; // terminal?
    if(S_ISBLK(mode)) str[0]='b'; // disk?
    if(S_ISLNK(mode)) str[0]='l'; // link?

    if(mode & S_IRUSR) str[1]='r'; // bits for the user
    if(mode & S_IWUSR) str[2]='w';
    if(mode & S_IXUSR) str[3]='x';

    if(mode & S_IRGRP) str[4]='r'; // bits for the group
    if(mode & S_IWGRP) str[5]='w';
    if(mode & S_IXGRP) str[6]='x';

    if(mode & S_IROTH) str[7]='r'; // bits for the others
    if(mode & S_IWOTH) str[8]='w';
    if(mode & S_IXOTH) str[9]='x';
}

// display stat information for a single file
void show_dir_entry(char *dir_entry_name, struct stat *info) {
    char modestring[11];
    mode_to_string(info->st_mode, modestring);
    printf("%s ", modestring);
    printf("%4d ", (int)info->st_nlink);
    printf("%8d ", (int)info->st_size);
    printf("%.20s", ctime(&info->st_mtim.tv_sec));
    printf("%s\n", dir_entry_name); 
}

// a simple wrapper around stat() for error checking and printing file info
void do_stat(char *dir_entry_name) {
    struct stat info;
    if(stat(dir_entry_name, &info)==-1)
        perror(dir_entry_name);
    else {
        show_dir_entry(dir_entry_name, &info);
    }
}

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
            do_stat(dirent_ptr->d_name);
        }
        closedir(dir_ptr);
    }
}

int main() {
    do_ls(".");                 // list the contents of the current directory
    return 0;
}
