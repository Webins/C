#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
};

struct employee{
    char name[20];
    struct date hiredate;
    double salary;
};

int main(){
    struct employee employee1;
    printf("Hello, enter your name\n");
    fgets(employee1.name, 20, stdin);
    printf("Enter your salary\n");
    scanf("%lf", &employee1.salary);
    printf("Enter the date when you were hired(dd/mm/yyyy)\n");
    scanf("%d/%d/%d", &employee1.hiredate.day, &employee1.hiredate.month,&employee1.hiredate.year);
    /* printf("First the day\n");
    scanf("%d", &employee1.hiredate.day);
    printf("Second the month\n");
    scanf("%d",&employee1.hiredate.month);
    printf("Lastly the year\n");
    scanf("%d", &employee1.hiredate.year); */


    printf("The employee of name %swas hired in %d/%d/%d and has a salary of %.3f $\n", employee1.name, employee1.hiredate.day, employee1.hiredate.month, employee1.hiredate.year, employee1.salary);
    return 0;

}

