#include <stdio.h>
#define LENGHT 10
int main(){
	int grades[LENGHT], sum;
	float average;
	for(int i =1; i<= LENGHT; i++){
		printf("Enter the %d grade\n"
				"%d:", i, i);
		scanf("%d", &grades[i]);
		sum += grades[i];
	}
	average = (float)sum/LENGHT;
	printf("\nYour average is %.2f\n", average);
	return 0;
}
