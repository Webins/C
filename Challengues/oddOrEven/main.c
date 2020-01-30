#include <stdio.h>

int main(int argcs, char *argv[]){
	int number, run;
	printf("To run the program type 1:");
	scanf("%d", &run);
	while(run ==1){
	printf("Enter the number to be evaluated: \n");
	scanf("%d", &number);
	int remainder = number %2;

	remainder==0 ? printf("%d is odd\n", number) : printf("%d is even\n", number);

	//El ternary operator es equivalente a hacer esto de abajo.
//	if(remainder == 0){
//		printf("%d is odd\n", number);
//	}
//	else{
//		printf("%d is even\n", number);
//	}


	printf("Keeping evaluating number(1) or exit with (0) \n");
	scanf("%d", &run);
	}

	return 0;
}
