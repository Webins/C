#include <stdio.h>

int main(){
char string[50];
printf("Enter input\n");
fgets(string, 50, stdin);
for(int i=0; string[i] !='\0';i++){
    string[i] = string[i] +3;
}

printf("cipher: %s\n", string);
for(int i=0; string[i] !='\0';i++){
    string[i] = string[i] -3;
}
printf("decipher: %s", string);
return 0;
}