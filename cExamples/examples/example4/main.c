#include <stdio.h> 
#include <string.h>
void scape(char s[], char t[]);
int main(){
    char arr[50];
    char arr2[50];
    fgets(arr, 50, stdin);
    scape(arr,arr2);
    return 0;
}
void scape(char s[], char t[]){
    strcpy(t, s);
        for(int i =0; s[i] != '\0'; i++){
            switch(s[i]){
                case '\t' : {
                s[i] = '\\'; 
                s[i+1] ='t';
                for(int j =i+2; t[j] != '\0'; j++){
                    s[j] = t[j-1];
                }
                }
                break; 
                case 32 :{
                s[i] = '\\'; 
                s[i+1] ='s';
                for(int j =i+2; t[j] != '\0'; j++){
                    s[j] = t[j-1];
                }
                }
            }
        }
    
       printf("S %s\n", s);
       printf("T %s\n", t);
}