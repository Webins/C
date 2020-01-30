#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


int main(){
    int c, linesCounter, charCounter;
    FILE *pfile = NULL;
    pfile = fopen("mytextFile.txt", "r");
    if(!pfile) {
        printf("Couldn't open the file\n");
        exit(1);
    }

    while((c = fgetc(pfile)) != EOF){
        charCounter++;
        if(c == '\n') linesCounter++;
    }

    printf("The number of characters in the file is : %d \n", charCounter);
    printf("The number of lines of the file is : %d \n", linesCounter);

    fclose(pfile);
    pfile = NULL;
    return 0;
}