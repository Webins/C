#include <stdio.h>

int main(int argc, char *argv[]){
int entero;
size_t output = sizeof(entero);
printf("%zd BYTES INT\n", output);

short int shortEntero;
size_t output2 = sizeof(shortEntero);
printf("%zd BYTES SHORT INT\n", output2);

long int longEntero;
size_t output3 = sizeof(longEntero);
printf("%zd BYTES LONG INT\n", output3);

int arregloEntero[] = {entero, shortEntero, longEntero};
size_t output4 = sizeof(arregloEntero);
printf("%zd BYTES ARRAY\n", output4);

long long int longLongEntero;
size_t output5 = sizeof(longLongEntero);
printf("%zd BYTES LONG LONG INT\n", output5);

float flotante;
size_t output6 = sizeof(flotante);
printf("%zd BYTES FLOAT \n", output6);

double doble;
size_t output7 = sizeof(doble);
printf("%zd BYTES DOUBLE \n", output7);

long double longDouble;
size_t output8 = sizeof(longDouble);
printf("%zd BYTES LONG DOUBLE\n", output8);

_Bool booleano;
size_t output9 = sizeof(booleano);
printf("%zd BYTES BOOLEAN\n", output9);

char caracter;
size_t output10 = sizeof(caracter);
printf("%zd BYTES CHAR\n", output10);





}

