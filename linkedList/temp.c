#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
/* add any other prototypes as needed */

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

/* Place your function definitions here. Be sure to include the definition for 
   createStudent() and any other functions you created for the previous task. */

struct student * createStudent(char name[50], int age){
    struct student * ptr = NULL;
    ptr = (struct student *) malloc(sizeof(struct student));
    if(!ptr){
        printf("Couldn't allocate the memory\n");
        exit(EXIT_FAILURE);
    }
    ptr-> age = age;
    strcpy(ptr -> name,name);
    ptr ->next = NULL;
    return ptr;
}

struct student * append(struct student * end, struct student * new){
    end->next = new;
    end = new;
    return end;
}
void printStudents(struct student * start){
    struct student * ptr = start;
    while(ptr != NULL){
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr-> next;
    }
}

void freeStudents(struct student *start){
    struct student * ptr = start, *temp;
    while(ptr != NULL){
        temp = ptr -> next;
        free(ptr);
        ptr = temp;
    }
    
}