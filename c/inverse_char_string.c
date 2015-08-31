#include <stdio.h>

void inverse(char* str) {
    int size = 0;
    int i;
    char tmp;

    while(str[size] != '\0') {
        size++;
    }

    for(i=0; i<size/2; i++) {
        tmp = *(str + i);
        *(str + i) = *(str + size - 1 - i);
        *(str + size - 1 - i) = tmp;
    }
}

int main(int argc, char* argv[]) {
    //char* s = "Hello world";
    //puts the string literal "Hello world" in read-only memory and creates a pointer s to that, 
    //making any writing operation on s illegal (e.g., s[0] = 'A'), 
    //while char s[] = "Hello world";
    //puts the string literal "Hello world" in read-only parts of memory, 
    //creates an array s by allocating memory on the stack and copies the string literal to the newly allocated memory, 
    //making any writing operation on s legal.
    
    //Example:                       Allocation Type:     Read/Write:    Storage Location:   Memory Used (Bytes):
    //===========================================================================================================
    //const char* str = "Stack";     Static               Read-only      Code segment        6 (5 chars plus '\0')
    //char* str = "Stack";           Static               Read-only      Code segment        6 (5 chars plus '\0')
    //char* str = malloc(...);       Dynamic              Read-write     Heap                Amount passed to malloc
    //char str[] = "Stack";          Static               Read-write     Stack               6 (5 chars plus '\0')
    //char strGlobal[10] = "Global"; Static               Read-write     Data Segment (R/W)  10

    char str1[] = "Hello World";
    char str2[] = "HelloWorld";
    char str3[] = "";
    char str4[] = "H";
    char str5[] = "He";

    inverse(str1);
    printf("%s\n", str1);

    inverse(str2);
    printf("%s\n", str2);

    inverse(str3);
    printf("%s\n", str3);

    inverse(str4);
    printf("%s\n", str4);

    inverse(str5);
    printf("%s\n", str5);

    return 0;
}

