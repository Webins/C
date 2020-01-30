#include <stdio.h>
int main(){
	int resultEven=0,resultPrime=0, min=0, max=0;
	printf("Asigna un rango de numeros, ejemplo: [de 1 a 100]\n");
	printf("numero min:\n");
	scanf("%d", &min);
	printf("numero max:\n");
	scanf("%d", &max);
	int totalNumbers = max-min,  numbers[totalNumbers], primeNumbers[totalNumbers], evenNumbers[totalNumbers];
	int opt = min;
	//Asigno los numeros correspondientes al rango indicado
	for(int i=0; min<= totalNumbers;i++){
		numbers[i] = min;
		min++;
	}

	for(int i=0; opt<= totalNumbers; i++){
		int j = 0,k=0;
		if((numbers[i] % 2) != 0){
			primeNumbers[j] = numbers[i];
			printf("%d Primo \n", primeNumbers[j]);
			j++;
			resultPrime+= j;
		}else {
			evenNumbers[k] = numbers[i];
			printf("%d Entero \n", evenNumbers[k]);
			k++;
			resultEven+= k;
		}
		opt++;
}
		printf("En total son %d enteros, %d impares\n", resultEven, resultPrime);

	return 0;
}
