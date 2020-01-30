#include <stdio.h>
#include "validate.h"


int main(){
    unsigned char s1[3], s2[50];
    int minRange = 0;
    int maxRange = 0;
    askAgain1:
    for(;;){

    printf("Ingresa un numero entre %d y %d\n", minRange, maxRange);
    fgets(s2, 50, stdin);
    if((validateDouble(s2)) == 1);
    else {
        /* system("clear"); */
        printf("Error\n");
        goto askAgain1;
    }
    
    /* system("clear"); */
    printf("Exito!\n");
    }
   


    return 0;
}

