#include <stdio.h>
#include <string.h>

// several versions of implementing strcpy

// array subscript version with explicit copy
void strcpy1(char *dest, const char *src){
    int i=0;
    while(src[i]!=0) {
        dest[i] = src[i];
        i++;
    }
    dest[i]=0;
}

// array subscript version
void strcpy2(char *dest, const char *src){
    int i=0;
    while((dest[i] = src[i])!=0)
        i++;
}

// pointer version
void strcpy3(char *dest, const char *src){
    while((*dest = *src)!=0) {
        dest++;
        src++;
    }
}

// pointer version with inline increment
void strcpy4(char *dest, const char *src){
    while((*dest++ = *src++)!=0) ;
}

// pointer viersion with inline increment and simplified condition
void strcpy5(char *dest, const char *src){
    while((*dest++ = *src++)) ;
}


int main(){
    char str1[100] = "Hello, world!";
    char str2[100];

    strcpy(str2,str1);
    printf("str2 = %s\n", str2);

    strcpy1(str2,str1);
    printf("str2 = %s\n", str2);

    strcpy2(str2,str1);
    printf("str2 = %s\n", str2);

    strcpy3(str2,str1);
    printf("str2 = %s\n", str2);

    strcpy4(str2,str1);
    printf("str2 = %s\n", str2);

    strcpy5(str2,str1);
    printf("str2 = %s\n", str2);
    
    return 0;
}
