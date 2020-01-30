#include <stdio.h>
size_t countChar(const char *);

int main(){
    char str[] = "Este es mi string";
    printf("%d", countChar(str));
    return 0;
}

size_t countChar(const char * str){
    unsigned short i =0;
    while(*(str+i)) i++;
    return *str+i - *str;
}