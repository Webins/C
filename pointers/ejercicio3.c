// pointer arithmetic

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int arraySum(int *, int);

int main(){
/* int values[100] = {0,1,2,3,4,5};
    int * valuesptr1 = &values[1];
    int * valuesptr2 = values+1;
    printf("%d - %d \n", *valuesptr1, *valuesptr2); */
    int array[8] = {0,1,2,3,4,5,6,7};
    int *ptr = array;
    for(int i = 0; i < 8; i++){
        *(ptr+i) = rand() %100;
    }

    printf("Sumatoria de array : %d \n",arraySum(array, 8));
   
    return 0;
}

int arraySum(int * array, int lenght){
    int * const arrayEnd = array +lenght;
    int sum=0;

    for(; array < arrayEnd; ++array){
        sum += *array;
    }

    return sum;
}  
/*  int arraySum(int * array, int lenght){
    int * const arrayEnd = array +lenght;
    int sum=0, *ptr1,;
    for(ptr1 = array; ptr1 < arrayEnd; ptr1++, ptr2++){
        sum += *ptr1;
    }

    return sum;
}  */