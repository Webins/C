#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void copy(char *, char *);

int main(){
    char str1[50] = "Este es un string criminal";
    char str2[50];
    copy(str1, str2);

    printf("String : \"%s\" with address %p" , str2, str2);


    return 0;
}

void copy(char * stringFrom, char * stringTo){
    while(*stringFrom) //El caracter nulo tambien se representa como 0 dentro del while
    *stringTo++ = *stringFrom++; 
    
    *stringTo ='\0';
}