#include <stdio.h>

/* 
set bit regresa x con los n bits que principian en la posicion p iguales a los n bits mas a la derecha de y, dejando a los otros bits sin cambios
numero de bits es cuantos bits vamos a cambiar de la variable y a x eje: cambiar 3 bits de 42 a 51 y a partir de la posicion 1
51 en binario : 1 1 0 1 1
*/

unsigned setBit(int firstBits, int position, int numberOfBits, int secondBits);

int main(){
    int result;
    result = setBit(51, 1, 3, 42);
    printf("%d", result);
    return 0;
}

unsigned setBit(int x, int p, int n, int y){

    return x >> (p+n) | (y);

}