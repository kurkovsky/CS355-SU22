// using structures in C

#include <stdio.h>
#include <string.h>

struct dataRecord {     // a simple structure to represent a person
    int intID;
    int intAge;
    float fSalary;
    char strName[100];
};

// print the values of a structure
void printDataRecord(const struct dataRecord * p) {
    printf("%s is %d years of age, their salary is %f.\n", 
    	p->strName, p->intAge, p->fSalary);
}

int main() {
    struct dataRecord John;     // declare an instance of a structure
    John.intID=12345;
    John.intAge=25;
    John.fSalary=100.05;
    strcpy(John.strName,"John");
    printDataRecord(&John);

    John.intAge=26;             // change one field within a structure

    struct dataRecord *alias=0;
    alias=&John;                // create a pointer to a structure

    alias->fSalary=110;         // access a field within a structure via a pointer
    printDataRecord(&John);
    (*alias).fSalary=115;
    printDataRecord(alias);
    
    return 0;
}
