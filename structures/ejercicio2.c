#include <stdio.h>
#define FUNDLEN 200

struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(struct funds);
int main(){
    struct funds stan = {
        "Banco Mercantil",
        4037.5,
        "Banco Banesco Universal",
        2024.47
    };
    printf("Stan has a total of %.2f $\n", sum(stan));
}

double sum(struct funds moolah){
    return(moolah.bankfund + moolah.savefund);
}