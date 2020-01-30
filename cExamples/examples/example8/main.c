
#include <stdio.h>
#define ABS(number) ((number <0 ? -(number) : number))
/*Define a macro swap(t,x,y) that interchanges two arguments of type t.*/
#define swap(type,x,y){ type _z; \
_z = x;\
x = y;\
y = _z;}
//function-like
int main(){

    char x='a', y='b';
    printf("x= %c \t y= %c\n",x,y);
    swap(char,x,y);
    printf("character x swapped = %c\n",x);
    printf("%d\n", ABS(-2));
    return 0;
}