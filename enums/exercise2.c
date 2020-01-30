#include <stdio.h>
#include <stdlib.h>

int main(){
	enum companies{GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
	enum companies Google= 0, Xerox = 2,  Ebay= 4;
	// o tambien enum companies xerox = XEROX;
	printf(" %d \n %d \n %d \n", Xerox, Google, Ebay);
}
