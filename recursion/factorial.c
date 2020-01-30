#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long long factorial(int);
void handler(void);
#define CURRENT_MEMORY 64
int main(){
    int n, i=0, c;
    char *str = (char *) malloc(sizeof(char) *CURRENT_MEMORY);
    if(!str) {
        fprintf(stderr, "Couldn't allocate memory\nExiting...\n");
        exit(EXIT_FAILURE);
    }
    askFactorial:
    printf("Ingrese solo numeros positivos para calcular el factorial\n");
    while((c=getchar()) != EOF && c != '\n'){
        if((c < '0' || c >'9')){
            fprintf(stderr, "Error no introdujo un numero positivo\n");
            handler();
            goto askFactorial;
        }else *(str + i) = c;
        i++;
    }
    n = atoi(str);
    if(n > 9) printf("The factorial number of %d is : %llu", n, factorial(n));
    else printf("The factorial number of %d is : %d", n, factorial(n));
    free(str);
    str = NULL;
}

unsigned long long factorial(int n){
    unsigned long long  result;
    if(n == 0) result =1;
    else result = n * factorial(n-1);
    return result;
}

void handler(void){
   int c;
   while((c = getchar()) !=EOF && c != '\n');
   return;
}