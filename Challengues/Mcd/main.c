#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#define SUCCESS 1
#define FAILURE -1

/*Disenar un programa en lenguaje c que halle el maximo comun divisor de dos numeros naturales mayores que 0.
  Utilizando punteros y los siguientes mecanismos:
  1. Version iterativa y recursiva del algoritmo de euclide (resto)/(modulo)
  2. Algoritmo de euclide binario
  Por ultimo hallar el minimo comun multiplo de esos numeros utilizando el conocimiento del Maximo comun divisor
*/


int validateInt(char[]);
int validatePositiveInt(char s[]);
void deleteNL(char s[]);
int validateBoolean(char s[3]);


void mcd_recursive(int * first, int * second, int * result);
void mcd_iterative(int * first, int * second, int * result);
void mcd_binary(int * first, int *second, int * result);
void mcm(int * first, int * second, int * result);
int input(int * store, size_t max_size, const short flag);
int main(){
    int run = 1, keep = 1, mcm_input=1;
    int persistent_first, persistent_second;
    int first, second, desition, result = 0, once=1, mcm_result=0;
    printf("CALCULO DEL MAXIMO COMUN DIVISOR\n\n");
    ask_run:
    printf("Quiere iniciar el programa? \n");
    printf("introduzca 1 para iniciar/0 para salir: ");
    if((input(&run, 2, 3)) == FAILURE){
        goto ask_run;
    }
    while(run){
        system("cls");
        if(once == 1){
            printf("\nDescripcion:\nEl maximo comun divisor es el mayor numero entero que divide a dos numeros sin dejar residuo alguno\n");
            printf("Necesita introducir dos numeros naturales que sean mayores a 0 para calcular el maximo comun divisor\n");
        once++;
            printf("Presione una tecla si entendio: ");
            getchar();
            fflush(stdin);
        }
        system("cls");
        /*Entrada primer numero*/
        ask_first:
        printf("Introduzca el primer numero para el calculo del MCD: ");
        if ((input(&first, 11, 1)) == FAILURE)
            goto ask_first;
         persistent_first = first;
        /*Entrada segundo numero*/
        system("cls");
        ask_second:
        printf("Introduzca el segundo numero para el calculo del MCD: ");
        if ((input(&second, 11, 1)) == FAILURE)
            goto ask_second;
        persistent_second = second;

        /*Entrada de la seleccion*/
        system("cls");
        ask_desition:
        printf("\nSeleccione que version del mcd quiere utilizar\n");
        printf("1. Mcd recursivo\n");
        printf("2. Mcd Iterativo\n");
        printf("3. Mcd Binario\n: ");
        if ((input(&desition, 2, 2)) == FAILURE)
            goto ask_desition;

        switch(desition){
            case 1: {
                    clock_t begin = clock();
            /* here, do your time-consuming job */
            mcd_recursive(&first, &second, &result);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("TIME SPENT: %lf", time_spent);
            };break;
            case 2:{
                clock_t begin = clock();
                /* here, do your time-consuming job */
                mcd_iterative(&first, &second, &result);
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("TIME SPENT: %lf", time_spent);
            };break;
            case 3:{
                clock_t begin = clock();
                /* here, do your time-consuming job */
                mcd_binary(&first, &second, &result);
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("TIME SPENT: %lf", time_spent);
            };
            break;
            }

        printf("\nResultado: Maximo comun divisor(%d, %d) = %d\n",persistent_first, persistent_second, result);
        printf("Presione una tecla para continuar: ");
        getchar();
        fflush(stdin);
        system("cls");
        ask_mcm:
        printf("Desea calcular el minimo comun multiplo(MCM) con el resultado del maximo comun divisor(MCD)?\n");
        printf("Presione 1 para aceptar/0 para salir: ");
            if((input(&mcm_input, 2, 3 )) == FAILURE){
                goto ask_mcm;
            }
            if(mcm_input == 1){
                int fr = persistent_first, sr = persistent_second;
                 clock_t begin = clock();
                /* here, do your time-consuming job */
                mcm(&fr, &sr, &mcm_result);
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("TIME SPENT: %lf", time_spent);
                printf("\nResultado Minimo comun multiplo(%d, %d) = %d\n", persistent_first, persistent_second, mcm_result);
                 printf("Presione una tecla para continuar: ");
                getchar();
                fflush(stdin);
                system("cls");
            }

         ask_exit:
            printf("Quiere ejecutar el programa de nuevo?\nPresione 1 para aceptar/0 para salir: ");
            if((input(&keep, 2, 3 )) == FAILURE){
                goto ask_exit;
            }
            if(keep == 0)
                run = false;
    }
    return 0;
}


void mcd_recursive(int * first, int * second, int * result){



    int resto = *first % *second;
    if(resto == 0){
        *result = *second;
        return;
    }
    *first = *second;
    *second = resto;

    mcd_recursive(first, second, result);
}
void mcd_iterative(int * first, int * second, int * result){
    unsigned short int i =0;
    int resto = *first % *second;
    while(resto!= 0){
        *first = *second;
        *second = resto;
        resto = *first % *second;
        i++;
    }
    if(resto == 0){
        *result = *second;
    }
}
void mcd_binary(int * first, int * second, int * result){
    int input_a, input_b;
    int a = *first % 2, b = *second % 2, binary_result =0;
    if(*first == *second){
        *result = *first;
    }
    else if(a == 0 && b == 0){
        input_a = (*first)/2;
        input_b = (*second)/2;
        mcd_iterative(&input_a, &input_b, &binary_result);
        *result = binary_result * 2;
    }
    else if(a == 0 && b != 0){
        input_a = (*first)/2;
        input_b = *second;
        mcd_iterative(&input_a, &input_b, &binary_result);
        *result = binary_result;
    }
    else if(a !=0 && b == 0){
        input_a = *first;
        input_b = (*second/2);
        mcd_iterative(&input_a, &input_b, &binary_result);
         *result = binary_result;
    }
    else if(a !=0 && b != 0){
        if(*first > * second){
            input_a = ((*first-*second)/2);
            input_b = *second;
            mcd_iterative(&input_a, &input_b, &binary_result);
        }else{
            input_a = *first;
            input_b = ((*second-*first)/2);
            mcd_iterative(&input_a, &input_b, &binary_result);
        }
        *result = binary_result;
    }

}
void mcm(int * first, int * second, int * result){
    int a;
    int b;
    if(*first > *second){
        a = *first;
        b = *second;
    }
    else {
        b = *first;
        a = *second;
    }
    int mcd_a = a;
    int mcd_b = b;
    int mcd_result = 0;
    mcd_iterative(&mcd_a, &mcd_b, &mcd_result);
    *result = (a / mcd_result) *b;
}
int input(int * store,  size_t max_size, const short flag){
    const size_t range_off = max_size+2;
    char input[range_off];
        fgets(input, range_off, stdin);
        if(strlen(input) > max_size){
            system("cls");
            if(max_size-1 == 1)  printf("Error, el valor introducido sobrepaso el maximo aceptado(%llu caracter)\n", (max_size-1));
            else printf("Error, el valor introducido sobrepaso el maximo aceptado(%llu caracteres)\n", (max_size-1));
            printf("Intenta con otro valor valido\n");
            fflush(stdin);
            return FAILURE;
        }
        if(flag == 1 && validateRangeInt(input, 1, INT_MAX) == FAILURE){
            system("cls");
            printf("Error numero invalido\n");
            return FAILURE;
        }
        else if(flag ==2 && validateRangeInt(input, 1 , 3) == FAILURE){
            system("cls");
            printf("Error numero invalido\n");
            return FAILURE;
        }
        else if(flag ==3 && validateBoolean(input) == FAILURE){
            system("cls");
            printf("Error numero invalido\n");
            return FAILURE;
        }
    *store = atoi(input);
    return SUCCESS;
}


//VALIDATION
int validateRangeInt(char s[], const int min, const int max){
    int n;
    if(validateInt(s) == SUCCESS){
        n = atoi(s);
        if(n >= min && n <= max) return SUCCESS;
        else return FAILURE;
    }
    else return FAILURE;
}


int validateInt(char s[]){
    unsigned short int i, j;
    deleteNL(s);
    while(s[0] != '\0'){ //MIENTRAS NO SEA UN STRING VACIO
        if(s[0] =='-' && isdigit(s[1])){ //EVALUA LOS MENORES A 0
            if(s[1] == '0') return FAILURE;
            for(i =0, j=1; s[i] !='\0'; i++, j++){
                if(!isdigit(s[j]) && s[j] !='\0') return FAILURE;
                else if(isdigit(s[j]) && s[j] !='\0') continue;
                else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
            }
        }
        else{ //EVALUA LOS MAYORES E IGUALES A 0
            if(s[0] == '0' && s[1] == '\0') return SUCCESS;
            else if(s[0] =='0' && isdigit(s[1])) return FAILURE;
            for(i = 0, j=1; s[i] != '\0'; i++, j++){
                if(!isdigit(s[i]) || isalpha(s[i])) return FAILURE;
                else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
            }
        }
    }
    return FAILURE;
}

void deleteNL(char s[]){
    unsigned short int i;
    for(i =0; s[i] != '\0'; i++){
        if(s[i] =='\n') s[i] = '\0';
    }
}

int validateBoolean(char s[3]){
    deleteNL(s);
    if(s[0] == '1' && s[1] =='\0') return SUCCESS;
    else if(s[0] =='0' && s[1] =='\0') return SUCCESS;
    else return FAILURE;

}
