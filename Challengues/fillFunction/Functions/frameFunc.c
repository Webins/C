#include "fillAux.h"
#include "coreFunction.h"

void frameFunc(char frame[]){
	    int pos =0, j=0;
	    for(; pos < WIDTH; pos++){
	        frame[pos] = '*';
	    }
	    frame[pos] = '\n';
	    for((pos = pos+1); j< (HEIGHT *2); j+=2){
	        int k=0;
	        frame[pos] = '*';
	            for(; k < WIDTH -2; pos++){
	                frame[pos+1] = SPACE;
	                k++;
	            }
	        frame[pos+1] ='*';
	        frame[pos+2] ='\n';
	        pos+=3;
	    }
	    j=0;
	     for(; j< WIDTH; j++){
	        frame[pos] = '*';
	        pos++;
	    }
	    frame [pos] ='\0';

	}
