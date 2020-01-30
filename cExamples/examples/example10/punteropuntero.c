#include <stdio.h>

int main(){
    int i;
    int *ptrToi;           /* Puntero a entero */
    int **ptrToPtrToi;     /* Puntero a puntero a entero */

    ptrToPtrToi = &ptrToi; /* Puntero contiene dirección de puntero */
    ptrToi = &i;           /* Puntero contiene dirección de entero */

    i = 10;                /* Asignación directa */
    *ptrToi = 20;          /* Asignación indirecta */
    **ptrToPtrToi = 30;    /* Asignación con doble indirección */  

    return 0;
}