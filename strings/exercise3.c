#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <unistd.h>


void reverseString(char arr[100], int lenght);
void bubbleSortChar(char arr[100], int lenght);


void reverseString(char arr[100], int lenght){
	int j =0;
	char result[100];
	for(int i =0; i< lenght; i++){
		arr[i] = tolower(arr[i]);
	}
	for(int i =0; i<= lenght; i++){
		int otherLenght= lenght-j;
		result[i] = arr[otherLenght];
		j++;
		printf("%c", result[i]);
	}
}




void bubbleSortChar(char arr[100], int lenght){
	for(int i=0; i< lenght; i++){
		for(int j=0; j <lenght; j++){
			if(arr[i] < arr[j]) {
				char temp1 = arr[i], temp2=arr[j];
				arr[j] = temp1;
				arr[i] = temp2;
			}
		}
	}
	printf("%s", arr);
}

int main(){
	int n;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char stringToReverse[100], stringToOrganized[100];
	int decision;
	printf("Select 1 to reverse the content of a string\nSelect 2 to organize the chars of a string"
			" from least to greatest\nselect 3 to order a set of strings from least to greatest\n"
			"Select 0 to exit\n");
	scanf("%d", &decision);
	while(decision != 0){
		switch(decision){
			case 1: {
				printf("Enter the string :\n");
				scanf("%s", stringToReverse);
				int lenght = strlen(stringToReverse);
				printf("Transformed string:");
				reverseString(stringToReverse, lenght);
				sleep(5);
				break;
			}
			case 2:{
				printf("Enter the string to be organized: \n");
				scanf("%s", stringToOrganized);
				int lenght= strlen(stringToOrganized);
				bubbleSortChar(stringToOrganized, lenght);
				sleep(5);
				break;
			}
			case 3:{
				int i;
				printf("Enter the numbers of string to be organized : \n");
				scanf("%d", &n);
				char stringsToOrganized[n][100], temp[100];
				printf("Input string %d : ", n);
				for(i = 0; i < n; i++){
						printf("\n");
				        scanf("%s", stringsToOrganized[i]);
				        printf("\n /////// %s", stringsToOrganized[i]);
				    }
				for(i =1; i<= n; i++){
					 for(int j=0;j<=n-i;j++)
					 if(strcmp(stringsToOrganized[j],stringsToOrganized[j+1])>0)
					            {
					                strncpy(temp,stringsToOrganized[j], sizeof(temp) - 1);
					                strncpy(stringsToOrganized[j],stringsToOrganized[j+1], sizeof(stringsToOrganized[j]) - 1);
					                strncpy(stringsToOrganized[j+1],temp, sizeof(stringsToOrganized[j] + 1) - 1);
					            }
				}
				 printf("The strings appear after sorting :\n");

				    for (i = 0; i <= n; i++)
				        printf("%s\n", stringsToOrganized[i]);
			}
		}
		printf("\n want to do something else? \n");
		printf("Select 1 to reverse the content of a string\nSelect 2 to organize the chars of a string"
					" from least to greatest\nselect 3 to order a set of strings from least to greatest\n"
					"Select 0 to exit\n");
		scanf("%d", &decision);
	}
	printf("Good bye!");




	return 0;
}
