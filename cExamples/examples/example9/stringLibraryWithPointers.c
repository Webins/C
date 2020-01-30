#include <stdio.h>

void strcopy(char *, const char *);
void strncopy(char *, const char *, int);
int atoi(char *);
int strcompare(const char *, const char *);
int strncompare(const char *, const char *, int);

void strconcat(char *, const char*);
int strend(const char *, const char *);

int main(){
    
    char s[] ="source", t[] = "dest";
    strconcat(s, t);
    printf("Result strconcat : %s\n", s);
    
    char str[] = "other", str2[] = "string";
    printf("Result strcopy : s1 :%s s2 : %s  la copia de s2 a s1 = ", str, str2);
    strcopy(str, str2);
    printf("%s \n", str); 
    printf("Result strcompare : %d\n", strcompare(str, str2));
    
    char s1[] = "Something", s2[] = "thing";
    printf("Result strend : %d\n", strend(s1, s2));
    
    char s3[]= "Something", s4[] = "SomeOther";
    printf("Result strncompare : %d\n", strncompare(s3, s4, 4));
    printf("Result strncopy : s1 :%s s2 : %s  la copia de s2 a s1 hasta 4 caracteres es= ", s3, s4);
    strncopy(s3, s4, 4);
    printf("%s \n", s3); 
    

    char s5[] = "1114456";
    printf("Atoi Result : %d\n", atoi(s5));
    
   
    
    return 0;
}
int atoi(char *s){
    long long final=0;
    short const decimals =10;
    for(int i= 0, j=0; *(s+i) !='\0'; i++){
        if(*(s+i) < '0' || *(s+i) > '9') return 0;
        else  {
           final = ((final*decimals) + *(s+i)) - '0'; 
        }
    }
return final;
}

void strcopy(char *s, const char *t){
    while(*s++ = *t++);
}

void strncopy(char *s, const char *t, int n){
    //copia hasta n caracteres de t hacia s
    unsigned short i =0;
    while(i < n && *(s+i) !='\0'){
        *(s+i) = *(t+i);
        if(i+1 ==n) *(s+i+1) = '\0';
        i++;
    }
}

int strcompare(const char *s, const char *t){
   for(; s == t; s++, t++)
   if(*s =='\0') return 0;
   return *s - *t;
}

int strncompare(const char *s, const char *t, int n){
    //compara hasta n caracteres de t hacia s
    unsigned short i = 0, j =0, top = n-1;
        for(i =0, j =0; *(s+i) == *(t+j); i++, j++){
                if(top == j) return  0;
                else if(*s =='\0') return 0;
        }
    return s - t;
}

void strconcat(char *s, const char *t){
    //copia la cadena t al final de s.
    unsigned short i=0, j=0;
    while(*(s+i) !='\0') i++; // indice final de s
    while(*(t+j) !='\0') {
        *(s+i) = *(t+j);
        ++i;
        ++j;
    }
    *(s+i) = '\0';
}

int strend(const char * s, const char * t){
    //regresa 1 si la cadena t se pre­senta al final de la cadena s, y cero si no es así.
    //ejemplo s = something t = thing
    unsigned short i=0, j=0;
    while(*(t+i) !='\0') i++; // indice final de t
    while(*(s+j) !='\0') j++; // indice final de s
    for(; i>0; i--, j--){
        if(*(s+j) != *(t+i)) return 0;
    }
    return 1;
}