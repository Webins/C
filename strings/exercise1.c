#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void tokenFunction(void){
	char str[]= "hello how are you - my name is - jason"; // STRING
	const char s[]= "-"; //DELIMITER
	char *token;
	//GET THE FIRST TOKE
	token = strtok(str, s);
	//WALK TROUGHT OTHER TOKENS
	while(token != NULL){
		printf("%s\n", token);
		token = strtok(NULL, s); // PASAMOS NULL POR QUE NO QUEREMOS MIRAR DE NUEVO, SOLO QUEREMOS EL NUEVO TOKEN
	}
}
void lookForCertainWords(void){
	char buffer[100];
	size_t bufferSize = sizeof(buffer) / sizeof(char);
/*
 * To determine the number of elements in the array, we can divide the total size of the array by the
 * size of the array element.
 * */
	int nDigits=0, nPunct=0, nLetters=0;
	printf("\n\nPlease Enter a text lesser than 100 words: \n");
	scanf("%s", buffer);
		char strUpp[100];
	for(int i =0; i < bufferSize; i++){
		if(isdigit(buffer[i])) nDigits++;
		else if(ispunct(buffer[i])) nPunct++;
		else if(isalpha(buffer[i])) nLetters++;
		strUpp[i]= (toupper(buffer[i]));
	}
		printf("\nstring uppercase: %s", strUpp);
	printf("\nDigits %d, Letters %d, Punctuation %d", nDigits, nLetters, nPunct);
}

void stringToDouble(){
	double value = 0;
	char str[] = "2.5 3.5 4.5";
	char *pstr = str;
	char *check = NULL;

	value = strtod(str, &pstr);
	if(pstr == check) printf("No convertion\n");
	else printf(" %f ", value);
	pstr = check;


}
int main(){
//	char myString[] = " This is my string";
//	char temp[50] = "Ok,";
//	strncpy(temp /*dest*/, myString /*src*/, sizeof(temp) -1 /*Tamaño, -1 por el null char*/);
//	printf("%s\n", temp);
//	strncat(temp, myString, sizeof(temp) + sizeof(temp));
//	printf("%s\t", temp);
//	printf("\n%d", strcmp(myString, myString));
//	printf("\n\n");
	stringToDouble();
	return 0;
}
