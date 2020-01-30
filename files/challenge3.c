#include <stdio.h> 
#include <stdlib.h>
#include <stddef.h>

int main(){
    int pos, c, i=0;
    FILE *pfile = NULL;
    pfile = fopen("textFileInReverseOrder.txt", "r");
    if(!pfile){
        fprintf(stderr, "Couldn't open the file\nExiting...\n");
        exit(1);
    }
    fseek(pfile, 0, SEEK_END);
    pos = ftell(pfile);
    while(i < pos){
        i++;
        fseek(pfile, -i, SEEK_END);
        printf("%c", fgetc(pfile));
    }

    fclose(pfile);
    pfile = NULL;
    return 0;
}