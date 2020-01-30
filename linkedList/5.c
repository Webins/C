#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
struct digit * readNumber(void);
struct digit * findNumber(struct digit *, int );
struct digit * reverseNumber(struct digit *);
struct digit * insertAtFront(struct digit * , struct digit * );
struct digit * insertIntoSorted(struct digit * , struct digit *);
struct digit * sortedCopy(struct digit *);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
int countRedun(struct digit *);
int divisibleByThree(struct digit *);
int changeThrees(struct digit *);



int main(void) {
    struct digit *start, *numberFound, *backward, *sorted;
    int numberToSearch=5;
    printf("Enter a digit\n");
    start = readNumber();
    printf("The number\n");
    printNumber(start);
    printf("The redundace is %d\n", countRedun(start));
    if (divisibleByThree(start)) printf("is divisible by 3.\n");
    else printf("is not divisible by 3.\n");
    numberFound = findNumber(start, numberToSearch);
    printf("and was modified in %d places.\n", changeThrees(start));
    printf("The new number is : \n");
    printNumber(start);
    if(!numberFound) printf("The number %d is not at location %p\n", numberToSearch, numberFound);
    else printf("The number %d is at location %p\n", numberToSearch, numberFound);
    backward = reverseNumber(start);
    printNumber(backward);
    printf("Sorted by digit : \n");
    sorted = sortedCopy(start);
    printNumber(sorted);
    freeNumber(backward);
    freeNumber(start);
    freeNumber(sorted);
    return 0;
}

int countRedun(struct digit * start){
    int redun;
    struct digit * ptr = sortedCopy(start), *prev = sortedCopy(start);
    ptr = ptr -> next;
    while(ptr != NULL){
        if(ptr -> num == prev -> num) redun++;
        ptr = ptr -> next;
        prev = prev -> next;
    }
    freeNumber(prev);
    freeNumber(ptr);
    return redun;

}

struct digit * sortedCopy(struct digit * start){
    struct digit * ptr = start, *sortedStart = NULL, *newdigit;
    if(ptr != NULL){
        sortedStart = createDigit(ptr -> num);
        ptr = ptr-> next;
    }
    while(ptr != NULL){
        newdigit = createDigit(ptr -> num);
        sortedStart = insertIntoSorted(sortedStart, newdigit);
        ptr = ptr->next;
    }
    return sortedStart;
}

struct digit * insertIntoSorted(struct digit * sortedStart, struct digit * newdigit){
    struct digit * ptr = sortedStart, *prev = NULL;
    while((ptr != NULL) && ptr -> num > newdigit -> num){
            prev = ptr;
            ptr = ptr -> next;
    }
    if(prev == NULL) sortedStart = insertAtFront(sortedStart, newdigit);
    else {
        prev -> next = newdigit;
        newdigit -> next = ptr;
    }
    return sortedStart;
}


struct digit * reverseNumber(struct digit * start){
    struct digit * ptr = start, *backStart=NULL, *newdigit;
    if(start != NULL){
        backStart = createDigit(start -> num); 
        ptr = ptr-> next;
    }
    while(ptr!= NULL){
        newdigit = createDigit(ptr->num); 
        backStart= insertAtFront(backStart, newdigit);
        ptr = ptr -> next;
    }
    return backStart;

}

struct digit * insertAtFront(struct digit * backstart, struct digit * newdigit){
    newdigit -> next = backstart;
    return newdigit;
}


int changeThrees(struct digit * start){
    struct digit * ptr = start;
    int threeCounter=0;
    while(ptr != NULL){
        if((ptr -> num) == 3) {
            ptr -> num = 9;
            threeCounter++;
        }
        ptr = ptr -> next;
    }
    return threeCounter;
}
struct digit * findNumber(struct digit * start, int numberToSearch){
    struct digit *ptr = start;
    while(ptr != NULL){
        if((ptr ->num) == numberToSearch) return ptr;
        else {
            ptr = ptr -> next;
        }
    }
    return ptr;
}

int divisibleByThree(struct digit * start){
    if((start ->num % 3) == 0) return 1;
    else return 0;
}

struct digit *readNumber(void){
    char c;
    int d;
    struct digit *start = NULL, *newDigptr, *end;
    while((c = getchar()) !='\n' && c !=EOF){
        d = c -48;
        newDigptr = createDigit(d);
        if(start == NULL){
            start = newDigptr;
            end = start;
        }else{
            end = append(end, newDigptr);
        }
    }
    return start;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

