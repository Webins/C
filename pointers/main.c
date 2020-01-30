#include <stdio.h>
#include <stddef.h>

int main(){
//	int number=10, * pnumber=NULL;
//
//	printf("number value : %d\n", number);
//	printf("number address : %p\n", &number);
//	printf("number size %ld\n", sizeof(number));
//
//	printf("///////////////////////////////////////\n");
//	printf("pnumber address : %p\n", (void*)&pnumber);
//	printf("///////////////////////////////////////\n");
//
//	pnumber = &number;
//
//	printf("pnumber address : %p\n", (void*)&pnumber);
//	printf("pnumber value pointed to : %d\n", *pnumber);
//	printf("pnumber size : %d\n", (int)sizeof(pnumber));
//	printf("pnumber value : %p\n", pnumber);
//	*pnumber +=25;
//	printf("%d\n", number);
	long num1 =0l, num2= 0l;
	long * pnum = NULL;
	printf("initial values num1: %ld  num2: %ld, pnum: %ld", num1, num2, pnum);

	pnum = &num1;
	printf("\npnum:%ld", *pnum);
	*pnum = 2l;
	printf("\npnum:%ld", *pnum);
	num2++;
	printf("\npnum:%ld", *pnum);
	printf("\nnum2:%ld", num2);
	num2+= *pnum;
	printf("\npnum:%ld", *pnum);
	printf("\nnum2:%ld", num2);

	pnum = &num2;
	++*pnum;
	printf("\npnum:%ld", *pnum);
	printf("\nnum1:%ld", num1);
	printf("\nnum2:%ld", num2);
	return 0;
}
