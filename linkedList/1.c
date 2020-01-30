#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct digs{
    int num;
    struct digs* next;
}digit;

digit *createDigit(int );

int main(){

    digit * numberptr;
    int digitToStore= 6;
    numberptr = createDigit(digitToStore);
    printf("We are storing the digit %d and the pointer %p at memory location %p.\n", numberptr->num, numberptr->next, numberptr);
    free(numberptr);
    numberptr = NULL;
}

digit * createDigit(int dig){
    digit * ptr = NULL;
    ptr = (digit *)malloc(sizeof(digit));
    if(!ptr) {
        exit(EXIT_FAILURE);
        printf("Couldn't allocate memory\n");
    }
    ptr->num = dig;
    ptr->next =NULL;
    return ptr;
}

