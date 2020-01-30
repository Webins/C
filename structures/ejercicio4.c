#include <stdio.h>

struct time{
	struct{
		int day;
		int months;
		int years;
	}date;
	int hours;
	int minutes;
	int seconds;
}dateAndTime;

struct intPtrs{
	int *p1;
	int *p2;
}containPtrs;
	
int main(){
	struct time *dateAndTimeptr = &dateAndTime;
	dateAndTimeptr ->date.months = 11;
	dateAndTimeptr ->date.years = 1997;
	printf("The value is : %d\n", dateAndTimeptr->date.months);
	
	containPtrs.p1 = &dateAndTimeptr ->date.months;
	containPtrs.p2= &dateAndTimeptr ->date.years;
	
	printf("p1 %d: p2: %d \ndate.month: %d date.year: %d\n", *containPtrs.p1, *containPtrs.p2,dateAndTimeptr ->date.months, dateAndTimeptr ->date.years);
	
	*containPtrs.p1 = 30;
	*containPtrs.p2= 46;
	
	printf("p1 %d: p2: %d \ndate.month: %d date.year: %d", *containPtrs.p1, *containPtrs.p2,dateAndTimeptr ->date.months, dateAndTimeptr ->date.years);
	 
	return 0;
}
