#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define CURRENT_MEMORY 16

struct item{
	char * itemName;
	int quantity;
	double price;
	double amount;
}origin;
	
typedef struct item item;
void readItem(item *);
void printItem(item *);

int main(){	
	item *item1 = &origin;
	readItem(item1);
	printItem(item1);
	free(item1 -> itemName);
}

void printItem(item * strc){
	printf("|Name:    %10s|\n", strc -> itemName);
	printf("|Quantity:%10d|\n", strc -> quantity);
	printf("|Price:   %10.2f|\n", strc -> price);
	printf("|Amount:  %10.2f|\n", strc -> amount);
}


void readItem(item * strc){
	int c, memory = CURRENT_MEMORY;
	short i =0;
	printf("Introduzca el nombre del producto\n");
	strc -> itemName = malloc(memory);
	if(strc -> itemName == NULL){
		printf("Couldn't allocate the memory\nPress a key to exit\n");
		getchar();
		exit(1);
	}
	while(((c=getchar()) !='\n') && (c !=EOF)){
		strc -> itemName[i] = c;
		if(i >= memory){
			strc -> itemName = malloc(CURRENT_MEMORY);
			memory += memory;
		}

		if(strc -> itemName == NULL){
			printf("Couldn't allocate more memory\nPress a key to exit\n");
			getchar();
			exit(1);
		}
		i++;
	}
	printf("Introduzca la cantidad del producto\n");
	scanf("%d", &strc -> quantity);
	printf("Introduzca el precio del producto\n");
	scanf("%lf", &strc -> price);
	strc -> amount = strc -> price * strc -> quantity;
}
