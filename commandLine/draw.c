#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void pascalTriangle(int rows);
void printTree(void);
void printFrame(void);

int main(int argc, char ** argv){
	if(argc > 1 ){
        if(strcmp(argv[1], "-p") == 0 && argc > 2){
                for(int i =0 ; argv[2][i] !='\0'; i++){
                    if(!isdigit(argv[2][i])) {
                        printf("Enter a valid integer number for the rows\n");
                        return 1;
                    }
                }
                pascalTriangle(atoi(argv[2]));
        }
        else {
            printf("Enter a valid integer number for the rows\n");
            return 1;
            }
    }else{
        printf("Enter a option like \"-p\", \"-\" or \"-\"\n");
    }

return 0;
}


void pascalTriangle(int rows){
    int coef=1, space, i, j;
    for (i=0; i<rows; i++) {
        for (space=1; space <= rows-i; space++)
            printf("  ");
        for (j=0; j<=i; j++) {
            if (j==0 || i==0)
                coef = 1;
            else
                coef=coef*(i-j+1)/j;
            printf("%4d", coef);
        }
        printf("\n");
    }
}
