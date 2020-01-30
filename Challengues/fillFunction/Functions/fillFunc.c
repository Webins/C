#include "fillAux.h"
#include"coreFunction.h"
#include "colors.h"

void fillFunc(char s[], int lenght){
	   int i=0 ,m =0, k=0;
	   int start = (WIDTH+1) * (HEIGHT/2) +1, end = start +FREESPACES;
	   char subStrings[HEIGHT+1][FREESPACES+1], sFrame[(LENGHT)];
	   unsigned const int lenghtPlus = lenght +FREESPACES;


	   //init substrings with null character
	    for(i =0; i< HEIGHT+1; i++){
	            subStrings[i][0] = '\0';

	    }

	    //fill line per line
	   for(i =FREESPACES; i<lenghtPlus; i+= FREESPACES){
	        int j;
	        for(j = 0; j<= FREESPACES+1; j++){
	            if(j == FREESPACES || s[m] == '\0') {
	                subStrings[k][j] = '\0';
	            }
	            else{
	            subStrings[k][j] = s[m];
	            m++;
	            }
	        }

	        k++;
	   }
	    //frame
	    frameFunc(sFrame);


	    int count =0, j;
	    int start2=(WIDTH+2), end2 = start2+FREESPACES;
	    for(j=0; j < HEIGHT; j++){
	       k =0;
	       if((subStrings[j][0]!= '\0')){
	           //if there is no more spaces below, go to the top
	             if(count >= FREESPACES*((HEIGHT/2)+1)){
	                for(; end2 >= start2 && subStrings[j][k] != '\0'; k++){
	                sFrame[start2] = subStrings[j][k];
	                ++start2;
	                }
	            start2+= 3;
	            end2 = start2+FREESPACES;
	            }
	            //write in the free spaces
	            else{
	            for(; end >= start && subStrings[j][k] != '\0'; k++){
	            sFrame[start] = subStrings[j][k];
	            ++start;
	            }
	            }
	            count += k;
	        }
	        start+= 3;
	        end = start+FREESPACES;

	    }
#ifdef __unix__
	    printf("%s\n", GREEN);
#endif
	    printf("%s\n", sFrame);
#ifdef __unix__
	    printf("%s\n", DEFAULT);
#endif
	}
