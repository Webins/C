#include <stdio.h>
#include <string.h>
void reverse(char[], int);

int main(){
    char str1[] ="jejeje";
    reverse(str1, strlen(str1));
    return 0;

}


void reverse(char s[], int lenght){
    char str2[lenght];
        for(int j =0; s[j] != '\0'; j++){
            str2[j] = s[lenght-1];
            --lenght;
        }
    
    printf("%s", str2);
}