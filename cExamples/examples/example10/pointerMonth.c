#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
 void deleteNL(char *);
int main(){
    unsigned short i=0, j=0;
    char decision[15];
    char *months[] = {
        "Mes invalido",
        "Enero", "Febrero", "Marzo","Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    printf("Introduzca un mes\n");
    fgets(decision, 15, stdin);
    deleteNL(decision);
    for(i=0; i <13; i++){
            if(strcmp(months[i], decision) ==0) printf("Mes :%d = Correcto\n", i);
            else printf("Mes :%d = Falso\n", i);
        }
return 0;
    }

    void deleteNL(char *s){
    unsigned short i;
    for(i =0; s[i] != '\0'; i++){
        if(s[i] =='\n') s[i] = '\0';
    }
}

