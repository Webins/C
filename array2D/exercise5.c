/*Write a C program to multiply two matrices.*/
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COL 3


int main(){
    system("clear");
    int matrix1[ROWS][COL], matrix2[ROWS][COL], multipliedMatrix[ROWS][COL];
    for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            matrix1[i][j] =i+1;
            matrix2[i][j] =i+9;
        }
    }
printf("PRIMERA MATRIZ:\n");
    for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            printf(" %d ", matrix1[i][j]);
        }
        printf("\n");
    }


printf("SEGUNDA MATRIZ:\n");
    for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            printf(" %d ", matrix2[i][j]);
        }
        printf("\n");
    }


printf("MULTIPLICACION DE LA MATRIZ 1 POR LA MATRIZ 2:\n");
int m=0, k=0,result=0;
     for(int i =0, k; i< ROWS;i++,k++){
        for(int j=0; j< COL; j++){
            result += matrix1[i][j] * matrix1[j][i];
            if(j == COL-1){
            multipliedMatrix[i][j] = result;
            printf(" %d ", multipliedMatrix[i][j]);
            }
        }
            
        printf("\n");
    }
    

    return 0;
}