#include <stdio.h>
#include <stdlib.h>
unsigned long long fibonacci(int);

int main(){
    int n;
    printf("Which fibbonaci number would you like : ");
    scanf("%d", &n);
    if(n <=0){
        printf("Enter a positive number\n");
        exit(EXIT_FAILURE);
    }else printf("The fibonnaci number is : %llu", fibonacci(n));

    return 0;
}

unsigned long long fibonacci(int n){
    unsigned long long result;
    if(n == 1 || n == 2) result = 1;
    else result = fibonacci(n-1) + fibonacci(n-2);
    return result;
}