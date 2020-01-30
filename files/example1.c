#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int main(){
    FILE *pfile;
    int c;
    char str[60], str2[10], str3[10], str4[10];
    int integer;
    pfile = fopen("mytextFile.txt", "r");
    if(!pfile) {
        printf("Error opening the file\n");
        exit(1);
    }

    fscanf(pfile, "%s %s %s %d", str2, str3, str4 ,&integer);
    printf("str2 :%s\nstr3: %s\nstr4:%s\ninteger : %d\n", str2, str3, str4,integer);

    if(fgets(str, 59, pfile) != NULL){
    printf("str : %s \n", str);
    }else exit(1);




int i =0;
while(i < 2){
    while((c=fgetc(pfile)) != EOF){
        putchar(c);
    }
        rewind(pfile);
        i++;
}


    fclose(pfile);
    pfile = NULL;


    return 0;
}