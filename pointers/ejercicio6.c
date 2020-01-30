#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
int main(){

    char * str = NULL;
    /*Allocating*/
    str = (char *)calloc(10, sizeof(char));
    /*if(!str) check for null*/ 
    strcpy(str, "El primer string");
    printf("String = %s, Address = %p\n", str, str);
    /*Reallocating*/
    str = (char *) realloc(str, 25 * sizeof(char));
    /*if(!str) check for null*/ 
    strcat(str, " completado con realloc");
    printf("String = %s, Address = %p", str, str);

    free(str);


    return 0;
}