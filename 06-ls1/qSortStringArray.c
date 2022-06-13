#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// an example of using qsort with an array of strings
// also see https://man7.org/linux/man-pages/man3/qsort.3.html

// a comparison function that will be used by qsort()
int myStringCompare(const void *a, const void *b) {
    return strcmp((const char*)a, (const char*)b);
}

#define MaxWords 7
#define MaxWordLength 20
int main() {
    char words[MaxWords][MaxWordLength] = {"orange", "apple", "table", "chair", "cable", "TV", "1234"};
    
    qsort(words, MaxWords, MaxWordLength, myStringCompare);

    for(int i=0; i < MaxWords; i++)      // verify the correctness of sorting
        printf("%d: %s\n", i, words[i]);
}