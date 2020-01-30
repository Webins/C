#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(){
    // 0x7FFFFFFF = 2,147,483,647 in decimal. represent the maximun positive value for a 32-bit signed binary integer.
    /* is the same that INT_MAX printf("%d\n", INT_MAX); */
    time_t biggest = 0x7FFFFFFF; 
    double seconds;
    unsigned long days;
    printf("%s\n", ctime(&biggest));
    printf("%s\n", asctime(gmtime(&biggest)));
    time_t current = time(NULL);
    struct tm tm = *localtime(&current);
    struct tm tm2 = *localtime(&biggest);
    printf("Current: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Biggest: %d-%d-%d %d:%d:%d\n", tm2.tm_year + 1900, tm2.tm_mon + 1,tm2.tm_mday, tm2.tm_hour, tm2.tm_min, tm2.tm_sec);
    seconds = difftime(biggest, current);
    days = seconds / (60*60*24);
    printf("Difference in days %llu", days);
    return 0;
}