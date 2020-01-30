/*
 *Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
every n columns. Should n be a variable or a symbolic parameter?
 *  Created on: 11 oct. 2019
 *      Author: kleiv
 */

#ifndef EXAMPLES_DETAB_H_
#define EXAMPLES_DETAB_H_


void detab(void);
const int TABING = 8;
void detab(){
	int c, numBlanks= 0;
	while((c= getchar())!= EOF){

		if(c == '\t') {
		numBlanks = TABING;
			while(numBlanks > 0){
				putchar(' ');
				numBlanks --;
			}
		}
		else if(c == '\n'){
			putchar(c);
		}
		else {
		putchar(c);
		}
	}
}

