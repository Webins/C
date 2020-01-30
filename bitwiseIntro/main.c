#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned int a = 60; // 0011 1100;
	unsigned int b = 13; // 0000 1101;
	int result = 0;      //-----------
	result = a & b; //      0000 1100;               if a is equal to 1 and b is equal to 1 that bit is going to be turn on.
	printf("%d\n", result);//------------        the decimal equivalent
	result = a | b; //      0011 1101
	printf("%d\n", result);//------------
	result = a ^ b;		 // 0011 0001;
	printf("%d\n", result);//------------
	result = a << 2;	//  1111 0000;
	printf("%d\n", result);//------------
	result = a >> 2;	//  0000 1111;
	printf("%d\n", result);//------------
	result = -a;	//      ;
	printf("%d\n", result);//------------
	return 0;
}
