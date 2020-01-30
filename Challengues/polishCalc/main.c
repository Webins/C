#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathFunctions(char[]);

/* reverse polish calculator */

int main(void)
{
    int type, var;
    double op2, op1, variables[26], v;
    char s[MAXOP];

   
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
                case NUMBER:
                        push(atof(s));
                        break;
                case NAME :
                        mathFunctions(s);
                        break;
                case '+':
                        push(pop()+pop());
                        break;
                case '*':
                        push(pop()*pop());
                        break;
                case '-':
                        op2 = pop();
                        push(pop()-op2);
                        break;
                case '/':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(pop()/op2);
                        else
                            printf("error:zero divisor\n");
                        break;
                case '%':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(((int)pop() % (int)op2));
                        else
                            printf("erro:zero divisor\n");
                        break;
                case '\n':
                        v = pop();
                        printf("\t%.8g\n",pop());
                        break;
                case '=':
                        pop();
                        if(var>='A' && var <='Z')
                            variables[var-'A']=pop();
                        else
                            printf("error: novariablename\n");
                            break;
                case 'd':
                        op2= pop();
                        printf("\tDouble of the last element of the stack : %.8g\n", op2 *2);
                        push(op2);
                        break;
                case '?': 
                        op2 = pop();
                        printf("\tlast element %.8g", op2);
                        push(op2);
                        break;
                case 's':
                        op1 = pop();
                        op2 = pop();
                        printf("\tSwapping the two last element: 1:%.8g, 2: %.8g", (op2), (op1));
                        break;
                case 'c':
                        clear();
                        break;
                default:
                        printf("error: unknown command %s\n",s);
                        break;

        }
        var = type;
    }
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}


double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;
    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;

     if(islower(c))
    {
        while(islower(s[++i]=c=getch()));
            ;
        s[i]='\0';
        if(c!=EOF)
            ungetch(c);
        if(strlen(s)>1)
            return NAME;
        else
            return c;
    }
    //si c no es un numero o un punto para decimales o un signo de -, regresalo
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    //si c es un negativo, pides otro caracter verificando que sea diferente un numero o un punto
    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void clear(void){
    sp =0;
}

void mathFunctions(char s[]){
    double op2;
    if(strcmp(s, "exp") == 0){
        push(exp(pop()));
    }
    else if(strcmp(s, "sin") == 0){
        push(sin(pop()));
    }
    else if(strcmp(s, "cos") == 0){
        push(cos(pop()));
    }
    else if(strcmp(s, "tan") == 0){
        push(tan(pop()));
    }
    else if(strcmp(s, "pow") == 0){
        op2 =pop();
        push(pow(pop(), op2));
    }
    else{
        printf("Function not supported\n");
    }
}