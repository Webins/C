#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv){
    if(argc > 2){
        for(int i=0; argv[1][i] != '\0'; i++){
            if(!isdigit(argv[1][i])) {
                printf("Invalid input.\n");
                return 1;
            }
            if(isdigit(argv[2][0])){
                for(int i=1; argv[2][i] !='\0'; i++){
                    if(isdigit(argv[2][i])) continue;
                    else if(isdigit(argv[2][i]) =='.'){
                        for(int j =i; argv[2][j] !='\0';j++){
                            if(isdigit(argv[2][i])) continue;
                        }
                       printf("%d plants for %.2lf dollars each cost %.2lf dollars\n", atoi(argv[1]), atof(argv[2]), ((atoi(argv[1])) * (atof(argv[2]) ))); 
                    }
                }
                printf("%d plants for %.2lf dollars each cost %.2lf dollars\n", atoi(argv[1]), atof(argv[2]), ((atoi(argv[1])) * (atof(argv[2]) )));
            }else{
                printf("Invalid input.\n");
                return 1;
            }
        }
    }else{
        printf("Invalid input.\n");
    }
    
    
    return 0;
}
