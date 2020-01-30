#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct filesCmpr{
    char *strcompared1;
    char *strcompared2;
    int nletters1;
    int nletters2;
}file1;

typedef struct filesCmpr filesCmpr;
filesCmpr *fileCompare(char *, char *);


int memory = 64, memory2 =64;
int main(){
    
    int c, d,  i=0, j=0;
    char *str1= (char *)malloc(memory), *str2 = (char *) malloc(memory);
    if(!str1 || !str2) {
        printf("Fallo al reservar la memoria\n");
        exit(EXIT_FAILURE);
    }
    FILE *pfile = NULL;
    FILE *pfile2 =NULL;

    pfile = fopen("/home/webins/Documentos/EducationExamples/cExamples/files/mytextFile.txt", "r");
    pfile2 = fopen("/home/webins/Documentos/EducationExamples/cExamples/files/mytextFile2.txt", "r");
    if(!pfile || !pfile2) {
        printf("Fallo al abrir el archivo de texto\n");
        exit(EXIT_FAILURE);
    } 

    while((c= fgetc(pfile)) !=EOF){
        if(i >= memory) {
            str1 = (char *)realloc(str1, memory);
            if(!str1){
                printf("Fallo al reservar la memoria\n");
                exit(EXIT_FAILURE);
            }
            memory += memory;
        }
        *(str1+i) = c;
        i++;
    }
    *(str1+i) = '\0';

    while((d=fgetc(pfile2)) !=EOF){
        if(j >= memory2) {
            str2 = (char *) realloc(str2, memory2);
            if(!str1){
                printf("Fallo al reservar la memoria\n");
                exit(EXIT_FAILURE);
            }
            memory2 += memory2;
        }
        *(str2+j) = d;
        j++;
    }
    *(str2+j) = '\0';

    
    filesCmpr *fileFinal = fileCompare(str1, str2);
    printf("The first file contains %d characters\n", fileFinal -> nletters1);
    printf("The second file contains %d characters\n\n", fileFinal -> nletters2);
    printf("The content of the first file: %s\nThe content of the second file: %s\n", str1, str2);
    printf("There is the missmatch: %s\n", fileFinal -> strcompared1);
    /* printf("%s\n", fileFinal -> strcompared2); */



    fclose(pfile);
    pfile= NULL;
    fclose(pfile2);
    pfile2 = NULL;

    return 0;
}

filesCmpr *fileCompare(char *str1, char *str2){
    filesCmpr *fileReturned = &file1;
    fileReturned ->strcompared1 = (char *) malloc(memory);
    fileReturned ->strcompared2 =(char *) malloc(memory);
    char *strcompared1 = (char *)malloc(memory), *strcompared2= (char*) malloc(memory);
    if(!strcompared1 || !strcompared2 || !(fileReturned ->strcompared1) || !(fileReturned ->strcompared2)){
        printf("Error, couldn't allocate the memory\n");
        exit(EXIT_FAILURE);
    }
    int i, counter1=0, counter2=0, j, k, m;
    bool cond = false;
    for(i =0; *(str1+i) !='\0';i++){
        counter1++;
    }
    for(i =0; *(str2+i) !='\0'; i++){
        counter2++;
    }
    if(counter1>= counter2){
        for(i=0; *(str1+i) !='\0' && cond != true; i++){
            if(*(str1+i) != *(str2+i)){
                j =i;
                for(j, k=0, m=0; *(str1+j) !='\0'; j++, k++, m++){
                    *(strcompared1+k) = *(str1+j);
                    if(*(str2+j) == '\0');
                    else *(strcompared2+m) = *(str2+j);
                }
                cond = true;
                *(strcompared2+k) = '\0';
                *(strcompared1+m) = '\0';
            }
        }
    }else{
        for(i=0; *(str2+i) !='\0' && cond != true; i++){
            if(*(str1+i) != *(str2+i)){
                j =i;
                for(j, k=0, m=0; *(str2+j) !='\0'; j++, k++, m++){
                    *(strcompared2+k) = *(str2+j);
                    if(*(str1+j) =='\0');
                    else *(strcompared1+m) = *(str1+j);
                }
                cond = true;
                *(strcompared2+k) = '\0';
                *(strcompared1+m) = '\0';
            }
        }
    }
fileReturned -> nletters1 = counter1;
fileReturned ->nletters2 = counter2;
fileReturned -> strcompared1 = strcompared1;
fileReturned -> strcompared2 = strcompared2;
return fileReturned;
}