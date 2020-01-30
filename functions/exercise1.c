#include <stdio.h>
#include <Math.h>

/*function declaration*/
int gdc(int, int);
float squareRoot(float);
float absolute(float);

int gdc(int n1, int n2){
	int result;
	result = n1%n2;
	if(n1 < 0 || n2 < 0){
		printf("The numbers have to be non negative\n");
		return 0;
	}
	else if(result ==0){
			return n2;
		}else return gdc(n2,result);
}

float absolute(float n){
	if(n < 0){
	return ((-1)*(n));
	}else return n;
}
float squareRoot(float n){
	if(n<0) {
	printf("imaginary root"
			"\nThe correct answer should be:");
	float result;
	result =absolute(n);
	return sqrt(result);
	}
			else return sqrt(n);
}

int main(void){
	int result =gdc(20,200);
	printf("%d\n",result);

	float result2 = absolute(10);
	printf("%.2f\n", result2);

	float result3 = squareRoot(-9);
	printf("%.2f\n", result3);

return 0;

}
