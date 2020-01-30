/*
Write a C program to read and print elements of array. - using recursion.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COL 10
void printMatrix(int[][COL], int, int);


int main(){
    int matrix1[ROWS][COL], matrix2[ROWS][COL];
    int i, j;
    srand(time(0));
    for(i =0; i<ROWS; i++){
        printf("| ");
        for(j=0; j<COL; j++){
            matrix1[i][j] = rand() %100;
            printf("%d ", matrix1[i][j]);
        }
        printf(" |\n");
    }
    printf("\n\n\nRECURSION\n");
    printMatrix(matrix1, ROWS, COL);
    return 0;
}


void printMatrix(int matrix[][COL], int i, int j){
    static int index1=0, index2 =0, counter=0;
    if(counter == ROWS) return;
    if(index2 % 10 == 0) {
        printf("|");
        index2=0;
        ++counter; 
    }
        while(index2+1 <j){
            printf(" %d", matrix[index1][index2]);
            if((index2 % j) == ROWS-1) printf(" |\n");
            index2++;
            printMatrix(matrix, i, j);
        }
    
        ++index1; 
        printMatrix(matrix, i, j);
    
    
}
        
    

        
