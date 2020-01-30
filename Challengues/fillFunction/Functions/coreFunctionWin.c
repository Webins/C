#include "fillAux.h"
#include "coreFunction.h"



void coreFunctionWin(void){
	    char s[LENGHT];
	    char dec[3];
	    bool cond = false, run = true;

	    system("cls");
	    printf("\t\t\t\t\t\t\t*************************\n");
	    printf("\t\t\t\t\t\t\t*         HOLA          *\n");
	    printf("\t\t\t\t\t\t\t*      BIENVENIDO       *\n");
	    printf("\t\t\t\t\t\t\t*************************\n\n");
	    printf("Este programa recibe un texto, y lo introduce dentro de un cuadro de asteriscos que empezara desde el medio de dicho cuadro.\n"
	    "Si el texto es muy amplio, entonces seguira el recorrido a la parte de arriba.\n\n");
	    askRun:
	    printf("Ingresa 1 para arrancar el programa\n0 Para salir\n");
	    fgets(dec, 3, stdin);
	    for(int i =0; dec[i] != '\0'; i++){
	            if(dec[i] == '\n') dec[i] = '\0';
	    }
	    system("cls");
	    if(dec[0] == '1' && dec[1] =='\0'){
	        run = true;
	    }else if(dec[0] == '0' && dec[1] == '\0'){
	        run = false;
	    }else{
	        printf("Ingresa un numero entre 0 y 1\n");
	        fflush(stdin);
	        goto askRun;
	    }
	    if(run){
	        static unsigned int lenght;
	        system("cls");
	        goAgain:
	        ask:
	        ask2:
	        printf("Introduzca el texto\n");
	        printf(":");
	        fgets(s, (LENGHT), stdin);
	        lenght = strlen(s);
	        // check if is there an overflow
	        if(lenght > (FREESPACES*HEIGHT)){
	            system("cls");
	            printf("Error, Introduciste mas caracteres de lo soportado\n");
	            fflush(stdin);
	            goto ask2;
	        }
	        for(int i =0; s[i] != '\0'; i++){
	            if(s[i] == '\n') s[i] = '\0';
	        }
	        for(int i=0; cond == false ; i++){
	            if(isspace(s[i])) continue;
	            else if(isalnum(s[i])) cond = true;
	            else if(s[i] == '\0') {
	            system("clear");
	            printf("Error, No introduzca un string vacio\n");
	            fflush(stdin);
	            goto ask;
	            }
	        }


	    system("cls");
	    fillFunc(s, lenght);
	    askRun2:
	    printf("Presione 1 para introducir otro texto\nPara salir presione 0\n");
	    fgets(dec, 3, stdin);
	    for(int i =0; dec[i] != '\0'; i++){
	            if(dec[i] == '\n') dec[i] = '\0';
	    }
	    system("cls");
	    if(dec[0] == '1' && dec[1] =='\0'){
	        run = true;
	        goto goAgain;
	    }else if(dec[0] == '0' && dec[1] == '\0'){
	        run = false;
	    }else{
	        printf("Ingresa un numero entre 0 y 1\n");
	        fflush(stdin);
	        goto askRun2;
	    }

	    }

	}





