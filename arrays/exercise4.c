#include <stdio.h>

int main(){
	int multiDimensionalArray[4][4] = {
			{1,1,1,1},
			{2,2,2,2},
			{3,3,3,3},
			{4,4,4,4}
	};



	for(int i= 0; i < 4; i++){
		printf("|");
		for(int j = 0; j<4; j++){
			printf("%d", multiDimensionalArray[i][j]);
		}
		printf("|");
		printf("\n");

	}
	return 0;
}
