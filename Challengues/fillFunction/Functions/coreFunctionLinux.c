#include "colors.h"
#include "fillAux.h"
#include "coreFunction.h"

unsigned int lenght;
void coreFunctionLinux(void){
	    char s[LENGHT];
	    char dec[3];
	    bool cond = false, run = true;

	    system("clear");
	    printf("%s", GREEN);
	    printf("\t\t\t\t\t\t\t*************************\n");
	    printf("\t\t\t\t\t\t\t*         HOLA          *\n");
	    printf("\t\t\t\t\t\t\t*      BIENVENIDO       *\n");
	    printf("\t\t\t\t\t\t\t*************************\n\n");
	    printf("%sEste programa recibe un texto, y lo introduce dentro de un cuadro de asteriscos que empezara desde el medio de dicho cuadro.\n"
	    "Si el texto es muy amplio, entonces seguira el recorrido a la parte de arriba.\n\n", GREEN);
	    askRun:
	    printf("Ingresa 1 para arrancar el programa\n0 Para salir\n");
	    fgets(dec, 3, stdin);
	    for(int i =0; dec[i] != '\0'; i++){
	            if(dec[i] == '\n') dec[i] = '\0';
	    }
	    system("clear");
	    if(dec[0] == '1' && dec[1] =='\0'){
	        run = true;
	    }else if(dec[0] == '0' && dec[1] == '\0'){
	        run = false;
	    }else{
	        printf("%sIngresa un numero entre 0 y 1\n%s", BOLDRED, GREEN);
	        fflush(stdin);
	        goto askRun;
	    }
	    if(run){
	        system("clear");
	        goAgain:
	        ask:
	        ask2:
	        printf("%s", GREEN);
	        printf("Introduzca el texto\n");
	        printf(":");
	        fgets(s, (LENGHT), stdin);
	        lenght = strlen(s);
	        // check if is there an overflow
	        if(lenght > (FREESPACES*HEIGHT)){
	            system("clear");
	            printf("%sError, Introduciste mas caracteres de lo soportado %s\n", BOLDRED, DEFAULT);
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
	            printf("%sError, No introduzca un string vacio%s\n", BOLDRED,DEFAULT);
	            fflush(stdin);
	            goto ask;
	            }
	        }
			cond = false;


	    printf("%s\n", DEFAULT);
	    system("clear");
	    fillFunc(s, lenght);
	    askRun2:
	    printf("%sPresione 1 para introducir otro texto\nPara salir presione 0%s\n", GREEN, DEFAULT);
	   	fgets(dec, 3, stdin);
	    for(int i =0; dec[i] != '\0'; i++){
	            if(dec[i] == '\n') dec[i] = '\0';
	    }
	    system("clear");
	    if(dec[0] == '1' && dec[1] =='\0'){
	        run = true;
	        goto goAgain;
	    }else if(dec[0] == '0' && dec[1] == '\0'){
	        run = false;
	    }else{
	        printf("%sIngresa un numero entre 0 y 1\n%s", BOLDRED, GREEN);
	        fflush(stdin);
	        goto askRun2;
	    }

	    }
	}







