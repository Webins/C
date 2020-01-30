#include <stdio.h>
#define MONTHS 12
#define YEARS 5
int main(){
float totalRainfallForEachYear, avgYearlyRainfall, sumAvg;
float totalRainfallMonthPerYear=0;
// 2015, 2019
float rainfall[YEARS][MONTHS] = {
//Jan Feb  Mar	Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec
 {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
 {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
 {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
 {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
 {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
};


//printf("Escoge el mes:\n");
//scanf("%d", &cMonth);
	printf("Year:\t\t");
	printf("Rainfall: (inches)\n\n");
for(int i=0; i< YEARS; i++){
	for(int j=0; j<MONTHS; j++){
		totalRainfallForEachYear += rainfall[i][j];

	}
	sumAvg +=totalRainfallForEachYear;
	avgYearlyRainfall = sumAvg / YEARS;

	printf("%d\t\t",i+2015);
	printf("%.1f\n", totalRainfallForEachYear);
	totalRainfallForEachYear=0;
}

	printf("The yearly average is %.1f\n\n", avgYearlyRainfall);
	printf("MONTHLY AVERAGES:\n");
printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
for(int h =0; h< MONTHS; h++){//12
	for(int k = 0; k < YEARS; k++){//5
		totalRainfallMonthPerYear += rainfall[k][h];
	}
		printf("%.2f ", totalRainfallMonthPerYear/YEARS);
		totalRainfallMonthPerYear=0;

}

return 0;
}
