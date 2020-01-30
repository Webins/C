#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#define MEMORY 256
int main(){
    int c, i=0;
    FILE *pfile = NULL;
    char * str = (char *)malloc(MEMORY);
    pfile = fopen("mytextFile2.txt", "r");
    if(!pfile) {
        printf("Couldn't open the file\n");
        exit(1);
    }

    while((c = fgetc(pfile)) != EOF){
        *(str+i) = toupper(c);
        i++;
    }
    fclose(pfile);
    pfile = NULL;

    pfile = fopen("mytextFile2.txt", "w");
    rename("mytextFile2.txt", "MYTEXTFILEUPP.TXT");
    fputs(str, pfile);
    remove("mytextFile2.txt");
    fclose(pfile);
    pfile = NULL;

    printf("The content in upper case : %s",str);
    return 0;
}