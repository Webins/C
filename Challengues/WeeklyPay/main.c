#include <stdio.h>

#define normalSalary 12.00
#define overtimeSalary 15.00
#define maxHours 40
#define firstTaxe 300
#define firstTaxePercentage 0.15
#define secondTaxe 450
#define secondTaxePercentage 0.20
#define thirdTaxePercentage 0.25

void netPay(float salary, float taxe){
		int result = (int)(salary-taxe);
		printf("Your total payment is %d$", result);
	}

int main(int argcs, char *argv[]){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int hours;
	float overtimeHours,firstTaxeResult,secondTaxeResult,taxeOvertime, thirdTaxeResult;

	printf("*********************************************************************\n"
			"		Weekly payment calculation							  \n"
			"*********************************************************************\n\n");

	printf("Enter the numbers of hours that you have worked in this week\n");
	scanf("%d", &hours);
	if(hours > maxHours) overtimeHours = hours - maxHours;
	float normal = (float)((hours-overtimeHours) * normalSalary);
	float overtime = (float)(overtimeHours * overtimeSalary);
	float overtimeTotal = (overtime+normal);
	hours > maxHours ? printf("Your salary is %.2f$ \n", overtimeTotal):
			printf("Your salary is %.2f$\n", normal);

				/*Results of the taxes */
	firstTaxeResult = normal * firstTaxePercentage;
	secondTaxeResult = normal  * secondTaxePercentage;
	thirdTaxeResult = normal * thirdTaxePercentage;
	taxeOvertime = overtimeTotal * thirdTaxePercentage;

					// 0 to 300$ -> 15%
	if(normal <= firstTaxe){
		printf("Your taxe is %.2f$\n", firstTaxeResult);
		netPay(normal, firstTaxeResult);

	}
					// 300$ to 450$ -> 20%
	if(normal <secondTaxe && normal >firstTaxe){
		printf("Your taxe is %2.f$\n", secondTaxeResult);
		netPay(normal, secondTaxeResult);
	}
					//450$ to 480$ -> 25%
	if(normal >= secondTaxe && normal <= (secondTaxe +30)){
					// 480$ to > Infinite
		if(overtimeTotal > secondTaxe +30){
				printf("Your taxe is %2.f$\n", taxeOvertime);
				netPay(overtimeTotal, taxeOvertime);
			}else {
				printf("Your taxe is %2.f$\n", thirdTaxeResult);
				netPay(normal, thirdTaxeResult);
			}
	}
}
