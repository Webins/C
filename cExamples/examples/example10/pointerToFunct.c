int f()
 {
//......
return 0;
}

int main(){
  int (*p)();
  int i;

    p = f; /* parasitaje: p apunta hacia f */
   /*  p = f(); /* INVALIDO */ */
    i = p(); /* aplicando operador llamada() a p */
    i = f(); /* aplicando opreador llamada() a f */
    i = (*p)(); /* equivalente a i=f() */

return 0;
}



/* Programa de arreglo de funciones, que puede reemplazar  una estructura switch */
/* 
#include <math.h>

int main(){
static double (*action[3])(double) = ffabs, sqrt, expg;
int i;
double x,y;
x=1.0;
printf(''De un numero (0-2): '');
scanf(''%d'',&i);
y = (*action[i])(x);
printf(''nn encontramos: %lf nn'',y);
return 0;
} */