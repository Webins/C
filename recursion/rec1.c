#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>

int factorial(int);

#define CURRENT_MEMORY 128
int main(){
    int n, i=0, c;
    char *str = (char *) malloc(sizeof(char) *CURRENT_MEMORY);
    if(!str) {
        fprintf(stderr, "Couldn't allocate memory\nExiting...\n");
        exit(EXIT_FAILURE);
    }
    askFactorial:
    printf("Ingrese solo numeros positivos para calcular el factorial\n");
    while((c=getchar()) != '\n' && c != EOF){
        if((c < '0' || c >'9')){
            fprintf(stderr, "Introduzca solo numeros\n");
            goto askFactorial;
        }else{
        *(str + i) = c;
        }
    }
    n = atoi(str);
    if(n == 0) {
        printf("The factorial number of %d is 1\n", n);
        exit(EXIT_SUCCESS);
    }
    printf("The factorial number of %d is : %d", n, factorial(n));
    free(str);
    str = NULL;
}

int factorial(int n){
    int result;
    if(n == 1) result =1;
    else n * factorial(n-1);
    return result;
}
