#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int choice =0;
    _Bool run;
    double width, height, area, perimeter; 
    printf("Hello, this program will calculate the area or the perimeter of a rectangle.\n");
    printf("Would you like to run the program?\nPress one (1) to run the program or zero (0) to stop the program");
    scanf("%d", &run);
    while(run == 1){
    	printf("Remember: \n");
    	printf("Perimeter is calculated by adding the height and with and then multiplying by two.\nExample: (Height + Width) *2 = Perimeter\n\n");
    	printf("Area is calculated by multiplying the width * height\nExample: Width * Height = Area \n\n");
    	printf("Select one (1) if you want to calculate the area. \nSelect two (2) if you want to calculate the perimeter\n");
    	scanf("%d", &choice);
    		if(choice == 1){
        		printf("Enter the width\n");
        		scanf("%lf", &width);
        		printf("Enter the height\n");
        		scanf("%lf", &height);
        				area = (width * height);
        				printf("The area is %.2f \n", area);
        				printf("enter a valid number\n");
        				run =0;
        		}
        	if(choice ==2){
        		printf("Enter the width\n");
        		scanf("%lf", &width);
        		printf("Enter the height\n");
        		scanf("%lf", &height);
        			perimeter = (width + height)  *2;
        			printf("The perimeter is %.2f\n", perimeter);
        			printf("enter a valid number\n");
        			run =0;
        	}
        	printf("Would you like to calculate something else?\n Select one (1) if yes, Select zero (0) if not\n");
        	scanf("%d", &run);
    }


		return 0;
}


