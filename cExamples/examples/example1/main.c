#include <stdio.h>
#include <string.h>	
#include <stdbool.h>
/*Squeeze borra cada caracter de el string numero 1 que coincida con cualquier caracter del string numero 2*/
	void squeeze(char s1[], char s2[]);	
/* Any regresa la primera posicion de el string numero 1 si se encuentra con cualquier caracter de la cadena s2 y regresa -1 si no hay coincidencias de s2 */
	char any(char s1[], char s2[]);
	int main(){
		char awnser;
		char firstString[] ="primero";
		char secondString[] ="segundo";
		squeeze(firstString, secondString);
		awnser = any(firstString, secondString);
		printf("%c\n", awnser);
		printf("\n");	
}

void squeeze(char s1[], char s2[]){
	
	char s3[strlen(s1)];
	strcpy(s3, s1);

	printf("String original: %s\n", s1);
	printf("String en el cual buscamos las coincidencias: %s\n", s2);
	for(int i =0; s2[i] != '\0'; i++){
				for(int j=0; s1[j] != '\0';j++){
					if(s1[j] == s2[i] ) s3[j] = '\00';				
				}				
	}
	/*Retornar s3 para no alterar s2 */
	printf("Resultado del string final: %s\n", s3);		
}

char any(char s1[], char s2[]){
	int cond =0;
	for(int i=0; s1[i] != '\0';i++){
		for(int j=0; s2[j] != '\0'; j++){
			if(s2[i] == s1[j]) return s1[0];
			continue;
		}
	}
	return -1;
	
	
}


