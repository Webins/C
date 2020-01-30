#include <stdio.h>

int main(int argc, char * argv[]){
    printf("%s", argv[1]);
    return 0;
}

/*
DECLARACIONES COMPLICADAS
char **argv = argv: apuntador a un apuntador a char

int (*daytab)[13] = daytab: apuntador a un arreglo[13] de int

int *daytab[13] = daytab: arreglo[13] de apuntadores a int

void *comp( ) =comp: función que regresa apuntador a void

void (*comp) ( ) =comp: apuntador a una función que regresa void

char (*(*x( ))[ ])( ) =x: función que regresa un apuntador a un arreglo [ ] de apuntadores a una función que regresa char

char (*(*x[3]) ( ))[5] = x: arreglo[3] de apuntadores a una función que regresa un apuntador a un arreglo [5] de char

*/