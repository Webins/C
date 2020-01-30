//pointer to const and void pointer

#include <stdio.h>
#include <stdarg.h>

int main(){
    int value = 999;
    const int * pvalue = &value;
    //*pvalue = 45; error
    printf("1. %d\n", *pvalue);
    value = 10;
    printf("2. %d\n", *pvalue);
    int otherValue = 100000;
    pvalue = &otherValue;
    printf("3. %d\n", *pvalue);
    //*pvalue = 10; error
    int number = 4;
    int *const pnumber = &number;
    printf("5. %d\n", *pnumber);
    number = 55;
    printf("6. %d\n", *pnumber);
   /*  pnumber = &value;  error*/
   int item = 5555;
   const int *const pitem = &item;
   printf("7. %d\n", *pitem);
   /* pitem = &pnumber;   error*/
    /* *pitem = 15;  error */
    item = 5;
    printf("8. %d\n", *pitem);
    void *ptr = NULL;
    ptr = &item;
    /*  printf("9. %d", *ptr);  Error*/ 
    printf("9. %d", *(int*)ptr);

    //
    int entero1 =0, entero2 =0;
    int * pointer1= NULL;
    pointer1 = &entero1;
    pointer1 = &entero2;
    *pointer1 = 15;
    printf("10. 1-%d |-| 2-%d", entero1, entero2);



    return 0;
}