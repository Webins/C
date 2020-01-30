#include <stdio.h>
double averageTemp(double * arr){
	int i;
	double avg = 0.0;
	for(i=0; arr[i] != '\0'; i++) avg+= *(arr+i);
	return (avg /(double)i);
}

void printAverageTemp(double * arr){
	printf("The average temperature is : %lf\n", averageTemp(arr));
}
