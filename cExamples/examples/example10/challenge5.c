#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int main(){
    size_t current_size = 5 * sizeof(char), lenght = current_size;
    char *str =  malloc(current_size);
    int c, i=0;
    if(!str) {
        printf("Couldn't allocate the memory\nEnter a key to exit\n");
        getchar();
        exit(0);
    }
    while((c = getc(stdin)) !='\n' && c != EOF){
        *(str+i) = c;
        if(i == lenght){
            lenght += current_size;
            str= realloc(str, lenght);
            if(!str){
                printf("Couldn't reallocate the memory\nEnter a key to exit\n");
                getchar();
                exit(0);
            }
            
        }
        i++;
    }

    printf("%s\n", str);

    free(str);
    str = NULL;
}