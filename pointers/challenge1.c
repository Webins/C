#include <stdio.h>
#include <stdarg.h>

int main(){
    int value =10;
    int * pvalue = &value;

    printf("Value address: %p\n", &value);
    printf("Pvalue address: %p\n",pvalue);

    printf("value is equal to %d\n", value);
    printf("pvalue is equal to %d", *pvalue);


    return 0;
}