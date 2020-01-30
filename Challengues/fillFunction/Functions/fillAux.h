/*
 * fillAux.h
 *
 *  Created on: 8 nov. 2019
 *      Author: kleiv
 */



#ifndef FUNCTIONS_FILL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#ifndef WIDTH
#define WIDTH 50
#endif
#ifndef HEIGHT
#define HEIGHT 10
#endif

#ifndef SPACE
#define SPACE 32
#endif
#define FUNCTIONS_FILL_H_

#ifndef FREESPACES
#define FREESPACES (WIDTH-2)
#endif

#ifndef LENGHT
#define LENGHT (WIDTH* HEIGHT * 2)
#endif


 void fillFunc(char [], int);
 void frameFunc(char []);



#endif /* FUNCTIONS_FILL_H_ */
