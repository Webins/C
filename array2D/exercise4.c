/*Write a C program to perform Scalar matrix multiplication.*/
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COL 10


int main(){
    system("clear");
    int matrix1[ROWS][COL], multipliedMatrix[ROWS][COL];
    for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            matrix1[i][j] =i+1;
        }
    }

printf("PRIMERA MATRIZ:\n");
    for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            printf(" %d ", matrix1[i][j]);
        }
        printf("\n");
    }
printf("MULTIPLICACION POR UN ESCALAR I=5 DE LAS MATRICES:\n");
     for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            multipliedMatrix[i][j] = matrix1[i][j] * 5;
            printf(" %d ", multipliedMatrix[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}