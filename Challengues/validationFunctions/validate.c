#include "validate.h"
//defines
#define SUCCESS 1
#define FAILURE -1

void deleteNL(char s[]){
    unsigned short int i;
    for(i =0; s[i] != '\0'; i++){
        if(s[i] =='\n') s[i] = '\0';
    }
}

//VALIDATE BOOLEAN 0 y 1
int validateBoolean(char s[3]){
    deleteNL(s);
    if(s[0] == '1' && s[1] =='\0') return SUCCESS;
    else if(s[0] =='0' && s[1] =='\0') return SUCCESS;
    else return FAILURE;

}



//ENTEROS
int validateInt(char s[]){
    unsigned short int i, j;
    deleteNL(s);
    while(s[0] != '\0'){ //MIENTRAS NO SEA UN STRING VACIO
        if(s[0] =='-' && isdigit(s[1])){ //EVALUA LOS MENORES A 0
            if(s[1] == '0') return FAILURE;
            for(i =0, j=1; s[i] !='\0'; i++, j++){
                if(!isdigit(s[j]) && s[j] !='\0') return FAILURE;
                else if(isdigit(s[j]) && s[j] !='\0') continue;
                else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
            }
        }
        else{ //EVALUA LOS MAYORES E IGUALES A 0
            if(s[0] == '0' && s[1] == '\0') return SUCCESS;
            else if(s[0] =='0' && isdigit(s[1])) return FAILURE;
            for(i = 0, j=1; s[i] != '\0'; i++, j++){
                if(!isdigit(s[i]) || isalpha(s[i])) return FAILURE;
                else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
            }
        }     
    }
    return FAILURE;
}
int validateRangeInt(char s[], const int min, const int max){
    int n;
    if(validateInt(s) == SUCCESS){
        n = atoi(s);
        if(n >= min && n <= max) return SUCCESS;
        else return FAILURE;
    }
    else return FAILURE;
}

//DOUBLES

int validateDouble(char s[]){
    deleteNL(s); //BORRAR NEWLINE CHARACTER
    double n;
    short unsigned int i, j, k, m;
    while(s[0] != '\0'){ //MIENTRAS QUE EL STRING NO ESTE VACIO
    if(isdigit(s[0])){ // EVALUA CUANDO ES UN DIGITO
        if(s[0] =='0'){  //EVALUA CUANDO ES 0
            if(s[1] =='\0') return SUCCESS;
            else if(s[1] =='.'){ //EVALUA CUANDO ES 0 CON DECIMAL
            if(s[2] =='\0') return FAILURE;
                    for(i=2, j=3; s[i] !='\0'; j++, i++){
                        if(!isdigit(s[i])) return FAILURE;
                        else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
                    }
                
                }
            else return FAILURE;
        }
        else if(s[1] =='\0') return SUCCESS;
        else if(isdigit(s[1])){
            if(s[2] =='\0') return SUCCESS;
            for(i=2, j=3; s[i] !='\0';i++, j++){
                if(s[i] =='.'){
                    if(s[i+1] =='\0') return FAILURE;
                        for(k=j, m=j+1; s[k] !='\0'; m++, k++){
                            if(!isdigit(s[k])) return FAILURE;
                            else if(s[m] ='\0' && isdigit(s[k])) return SUCCESS;
                            else if(isdigit(s[k])) continue;
                        }
                }
                else if(!isdigit(s[i])) return FAILURE;
                else if(isdigit(s[i]) && s[j] =='\0') return SUCCESS;
            }
        }
        else if(s[1] =='.'){
             if(s[2] =='\0') return FAILURE;
             else if(isdigit(s[2])){
                        for(i=2, j=3; s[i] !='\0'; i++, j++){
                            if(!isdigit(s[i])) return FAILURE;
                            else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;   
                        }
             }
             else return FAILURE;
        } 
        else return FAILURE;
        
    }
    //EVALUA LA PARTE NEGATIVA 
    else if(s[0] =='-'){
        if(s[1] =='\0') return FAILURE;
        else if(s[1] == '0'){
            if(s[2] =='\0') return FAILURE;
            else if(s[2] =='.'){
            if(s[3] =='\0') return FAILURE;
                for(i=3, j=4; s[i] !='\0'; j++, i++){
                    if(!isdigit(s[i])) return FAILURE;
                    else if(isdigit(s[i])) continue;
                    else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
                }
            }
            else return FAILURE;
        }
        else if(isdigit(s[1])){
            for(i=1, j=2; s[i] !='\0';i++, j++){
                if(s[i] =='.'){
                    if(s[i+1] =='\0') return FAILURE;
                        for(k=j, m=j+1; s[k] !='\0'; m++, k++){
                        if(!isdigit(s[k])) return FAILURE;
                        else if(isdigit(s[k])) continue;
                        else if(s[m] ='\0' && isdigit(s[k])) return SUCCESS;
                        }
                }
                else if(!isdigit(s[i])) return FAILURE;
                else if(isdigit(s[i]) && s[j] =='\0') return SUCCESS;
            }
        }
        else return FAILURE;
    }
    else return FAILURE; 
}
return FAILURE;
} 


int validateRangeDouble(char s[], const double min, const double max){
    double n;
    if((validateDouble(s)) == SUCCESS){
        n = atof(s);
        if(n >= min && n<=max){
            return SUCCESS;
        }else return FAILURE;
    }
    else return FAILURE;
}

int validatePrintable(char s[]){
    unsigned short i;
    for(i =0; s[i] !='\0'; i++){
        if(isprint(s[i])) continue;
        else return FAILURE;
    }
    return SUCCESS;
}

int validateLetters(char s[]){
    unsigned short i;
    for(i =0; s[i] !='\0'; i++){
        if(isalpha(s[i])) continue;
        else return FAILURE;
    }
    return SUCCESS;
}

int validateLetter(char s[]){
    unsigned short i;
    for(i =0; s[i] !='\0'; i++){
        if(isalpha(s[i])) continue;
        else return FAILURE;
    }
    return SUCCESS;
}
int validateAllChar(char s[]){
    unsigned short i;
    for(i =0; s[i] !='\0'; i++){
        if(isalnum(s[i])) continue;
        else return FAILURE;
    }
    return SUCCESS;
}