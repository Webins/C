#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct student {
      char * name;
      int age;
      struct student *next;
}student;

student * createStudent(char *, int);
student * append(student *, student *);
void printStudents(student *, int);
void storeStudents(student *, int, int flag);
void freeStudents(student *);

int main(){
    student *end, *start , *newStudent, *tmp;
    int studentAge, nStudents, i = 1;
    char * studentName = (char *)malloc(sizeof(char) *50);
    if(!studentName){
        printf("Couldn't allocate the memory\n");
        exit(EXIT_FAILURE);
    }
    printf("Ingrese el numero de estudiantes a inscribir : ");
    scanf("%d", &nStudents);
    while(nStudents > 0){
        printf("Ingrese la edad del %d alumno: ", i);
        scanf("%d", &studentAge);
        printf("Ingrese el nombre del %d alumno: ", i);
        scanf("%s", studentName);
         if((i-1) ==0){
            start = createStudent(studentName, studentAge);
            end = start;
            storeStudents(start, i , 0);
            printStudents(start, i);
        }else{
            newStudent = createStudent(studentName, studentAge);
            end = append(end, newStudent);
            storeStudents(end, i , 1);
            printStudents(end, i);
        }
        nStudents--;
        i++;
    }
    freeStudents(start);
    free(studentName);
    return 0;
}

void freeStudents(student * start){
    student * ptr = start, * tmp;
    while(ptr != NULL){
        tmp = ptr -> next;
        free(ptr);
        ptr = tmp;
    }
}

void printStudents(student * start, int i){
    if(start != NULL) printf("Estudiante numero %d\nNombre: %s\nEdad: %d\n", i, start -> name, start -> age);
    return;
}

void storeStudents(student * ptr, int i, int flag){
    FILE *pfile = NULL;
    switch (flag){
    case 0: pfile = fopen("students.txt", "w+"); break;
    case 1: pfile = fopen("students.txt", "a+"); break;  
    }
    if(!pfile){
        fprintf(stderr, "No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    else if(ptr != NULL){
        fprintf(pfile, "*************\n");
        fprintf(pfile, "Estudiante %d\nNombre: %s\nEdad: %d\n", i, ptr -> name, ptr -> age);
    }
    fclose(pfile);
    pfile = NULL;
    return;
}

student * createStudent(char * name, int age){
    student * ptr = NULL;
    ptr = (student *) malloc(sizeof(student));
    if(!ptr){
        printf("Couldn't allocate the memory\n");
        exit(EXIT_FAILURE);
    }
    ptr-> age = age;
    ptr ->name = name;
    ptr ->next = NULL;
    return ptr;
}

student * append(student * end, student * new){
    end->next = new;
    end = new;
    return end;
}
