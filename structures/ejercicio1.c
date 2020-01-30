#include <stdio.h>
#include <stdbool.h>
#include <string.h>




struct Family{
    char name[20];
    char mother[20];
    int age[20];
}family1, family2;
bool sibilings(const struct Family *, const struct Family *);


int main(){
    struct Family *pfamily1 = &family1, *pfamily2 = &family2;
    strcpy(pfamily1 ->mother, "Maria");
    strcpy(pfamily2 ->mother, "Maria");
    if((sibilings(pfamily1, pfamily2)) == true) printf("Hermanos\n");
    else printf("No hermanos\n");
}


bool sibilings(const struct Family *member1, const struct Family *member2){
    if(strcmp(member1 -> mother, member2->mother) == 0) return true;
    else return false;
}