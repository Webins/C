/*
Funciones para validar datos.
Estas funciones reciben un string como input, que sera leido por fgets y algunas reciben dos enteros que sera el rango de numero que pueden aceptar opcionalmente.
Todas estas funciones en caso de error regresan FAILURE(-1), en caso de exito SUCCESS(1)
*/
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>




// prototypes
extern void deleteNL(char[]);
//BOOLEAN
extern int validateBoolean(char[3]);
//Enteros
extern int validateInt(char[]);
extern int validateRangeInt(char[], const int, const int);
//Doubles
extern int validateDouble(char[]); 
extern int validateRangeDouble(char[], const double, const double);
//Strings 
extern int validatePrintable(char []);
extern int validateLetters(char []);
extern int validateAllChar(char[]);
