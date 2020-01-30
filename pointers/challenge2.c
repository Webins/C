#include <stdio.h>

void exp(int *, int);
int main(){
    int base = 5, pow = 2;
    printf("base value %d\n", base);
    exp(&base, pow);
    printf("base ^ %d is : %d", pow, base);
    return 0;
}

void exp(int *base, int pow){
    if(pow==1 && *base != 0) *base =1;
    while(pow!=1){
        *base *= *base;
        --pow;
    }
}

