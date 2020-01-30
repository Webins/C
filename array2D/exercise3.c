/*Write a C program to subtract two matrices.*/
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COL 10

int main(){
    system("clear");
    int matrix1[ROWS][COL], matrix2[ROWS][COL], substractedMatrix[ROWS][COL];
    for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            matrix1[i][j] =i+1;
            matrix2[i][j] =i%8 *j*5;
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
printf("RESTA DE LAS MATRICES:\n");
     for(int i =0; i< ROWS;i++){
        for(int j=0; j< COL; j++){
            substractedMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            printf(" %d ", substractedMatrix[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}