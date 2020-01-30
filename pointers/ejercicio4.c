#include <stdio.h>
#include <string.h>

int main(){

    char string[] = "This is a string";
    char *p = string;

    /* for(int i =0; i < strlen(string); ++i){
        printf("String char [%d] with address(%p) is equal to : %c \n", i , p+i, *(p +i));
    }
 */
    long arr[] = {999, 1015, 2018, 11447, 29878,114171, 144441};
    long *p2 = arr;

    for(int i =0; i < sizeof(arr)/ sizeof(arr[0]); i++){
        printf("Arr[%d] with address %p is equal to = %ld \n", i, p2+i, *(p2+i));
    }

    printf("Long occupied %d Bytes\n", (int)sizeof(long));
    return 0;
}