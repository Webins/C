#include <stdio.h>
#include <stdlib.h>

//#define minutes 60/*sec*/
#define hours 60/*min*/
#define days 24/*hours*/
#define years 365/*days*/

void converter(double qnty, int type){
	double result;
	switch(type){
	/*hours to year*/
	case 1: result = (double)(qnty/(days * years));
	printf("%.0f hours is the equivalent to %.6f years\n",qnty, result);
	break;
	/*hours to days*/
	case 2: result = (double)(qnty/days);
	printf("%.0f hours is the equivalent to %.6f days\n",qnty, result);
	break;
	/*Days to year*/
	case 3: result = (double)(qnty/years);
	printf("%.0f days is the equivalent to %.6f days\n",qnty, result);
	break;
	/*Days to hours*/
	case 4: result = (double)(days * qnty);
	printf("%.0f days is the equivalent to %.1f hours\n",qnty, result);
	break;
	/*Years to day*/
	case 5: result = (double)(years*qnty);
	printf("%.0f years is the equivalent to %.1f days\n",qnty, result);
	break;
	/*Years to hours*/
	case 6: result = (double)((qnty*years*days));
	printf("%.0f years is the equivalent to %.1f hours\n",qnty, result);
	break;
	}


}


int main(int argc, char *argv[]){
int type;
double qnty;
_Bool run = 0;
int choice;
printf("_______________________________________________________________________________________\n"
		"Hello, this program transform minutes, hours, days and years into others valid formats\n"
		"HOURS --> YEARS\n"
		"HOURS --> DAYS\n"
		"DAYS  --> YEARS\n"
		"DAYS  --> HOURS\n"
		"YEARS --> DAYS\n"
		"YEARS --> HOURS\n"
	   "_______________________________________________________________________________________\n");
printf("Would you like to run the program?\nPress one (1) to run the program or zero (0) to stop the program:\n");
scanf("%d", &run);
while(run == 1){
	printf(
			"Type 1 to convert hours into years  \t  one (1):\n"
			"Type 2 to convert hours into days   \t  two (2):\n"
			"Type 3 to convert days into years   \t  three (3):\n"
			"Type 4 to convert days into hours   \t  four (4):\n"
			"Type 5 to convert years into days   \t  five (5):\n"
			"Type 6 to convert years into hours  \t  six (6):\n"
			//Faltan minutos
			"Type 0 to close the program         \t  zero(0) to close:\n");
scanf("%d", &choice);
	switch(choice){
	case 1:
		printf("Enter the numbers of hours to convert into year:\n");
		scanf("%lf", &qnty);
		converter(qnty, 1);
		break;
	case 2:
		printf("Enter the numbers of hours to convert into days:\n");
		scanf("%lf", &qnty);
		converter(qnty, 2);
		break;
	case 3:
		printf("Enter the numbers of days to convert into year:\n");
		scanf("%lf", &qnty);
		converter(qnty, 3);
		break;
	case 4:
		printf("Enter the numbers of days to convert into hours:\n");
		scanf("%lf", &qnty);
		converter(qnty, 4);
		break;
	case 5:
		printf("Enter the numbers of years to convert into days:\n");
		scanf("%lf", &qnty);
		converter(qnty, 5);
		break;
	case 6:
		printf("Enter the numbers of year to convert into hours:\n");
		scanf("%lf", &qnty);
		converter(qnty, 6);
		break;
	case 0: run = 0;
	}

}

}
