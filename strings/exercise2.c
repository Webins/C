#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lenght(const char arr[100]);
void concat(const char arr_1[100], const char arr_2[100], int lenght1, int lenght2);
_Bool compare(const char arr_1[100], const char arr_2[100], int lenght1, int lenght2);

int lenght(const char arr[100]){
	int count;
	while(arr[count] != '\0') count++;
	return count;
}
void concat(const char arr_1[100], const char arr_2[100],int lenght1, int lenght2){
	char result[200];
	char space = ' ';
	int i;
	for(i=0; i<= lenght1; i++){
		result[i] = arr_1[i];
		if(i == lenght1) result[i] = space;
	}
	for(int j=0; j < lenght2; j++){
		result[j+i] = arr_2[j];
	}
	printf("%s\n", result);
}

_Bool compare(const char arr_1[100], const char arr_2[100],int lenght1, int lenght2){
	const int equal =1;
	const int notEqual= 0;
	if(lenght1 == lenght2){
		for(int i=0; i< lenght1; i++){
			if(arr_1[i] == arr_2[i] && arr_1[i]!= '\0'){
				continue;
			}
			else {
				printf("Not equal\n");
				return notEqual;
				 }
		}
	}
	if(lenght1 > lenght2 || lenght1 < lenght2 ) return notEqual;
else{
	return equal;
	printf("Equal\n");
}
}


int main(){
	char myName[] = "Kleiver";
	char myNameAgain[] = "Kleiver";
	char myLastName[] = "Marcano";
	printf("%d\n", lenght(myLastName));
	concat(myName, myLastName,lenght(myName), lenght(myLastName));
	compare(myName, myLastName, lenght(myName), lenght(myLastName));
	return 0;
}
