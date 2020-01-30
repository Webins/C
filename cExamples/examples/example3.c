


void reverse(char[], int);


void reverse(char s[], int lenght){
    char str2[lenght];
        for(int j =0; s[j] != '\0'; j++){
            str2[j] = s[lenght-1];
            --lenght;
        }
    for(int i= 0; s[i] != '\0'; i++){
        s[i] = str2[i];
    }
}
