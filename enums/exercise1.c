#include <stdio.h>

int main(void){
	enum Weekdays {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
	enum Weekdays today = Friday;

	switch(today){
	case Monday: printf("Is monday\n");break;
	case Tuesday: printf("Is tuesday\n");break;
	case Wednesday: printf("Is wednesday\n");break;
	case Thursday: printf("Is thursday\n");break;
	case Friday: printf("Is friday\n");break;
	case Saturday: printf("Is saturday\n");break;
	case Sunday: printf("Is sunday\n");break;
	}
}
