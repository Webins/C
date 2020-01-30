#include <stdio.h>
#define MONTHS 12
int main(){
	int days[MONTHS] = {30,28,31,30,31,30,31,31,30,31,30,31};
	for(int i = 0; i< MONTHS; i++){
		printf("The %d month has: %d days\n", i +1, days[i]);
	}
return 0;
}
