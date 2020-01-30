#include <stdio.h>

/*
Ejercicio 4-1. Escriba la función strIndex(s,t), que regresa la posición de la ocu­
rrencia de más a la derecha de t en s, ó -1 si no hay alguna.
 */

int strIndex(char s[], char t[]);

int main(){
    char s1[50], s2[50];
    printf("Primer string:\n");
    fgets(s1, 50, stdin);
    printf("Segundo string:\n");
    fgets(s2, 50, stdin);
    int result;
    result = strIndex(s1, s2);
    result == -1? printf("%d", result): printf("%c", result);
    return 0;
}
int strIndex(char s[], char t[]){
    int k;
    k=0;
        for(int i=0; s[i] != '\0'; i++){
            k=i;
        }
        for(int i=k; i!=0; i--){
            for(int j=0; t[j] !='\0'; j++){ 
            if(s[i] == t[j] && s[i] != 32 && s[i] !='\n') return t[j];
            }
        }

    return -1;
}


