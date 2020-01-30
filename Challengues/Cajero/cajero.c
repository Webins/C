#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define currentPassword 1902 
int main(int argc, char *argv[]){
  char password[5];
  int montoInicial = 520000;
  int awnser, awnser2;
  bool correctPas= false;
       back:
      printf("Introduzca su clave secreta\n");
      fgets(password, 5, stdin);
      awnser = atoi(password);
      if(awnser <=0 || awnser != currentPassword){
                printf("clave invalida\n");
                fflush(stdin);
                goto back;
                }
  correctPas = true;  
  while(correctPas == true){
  int opt;
  askAgain:
  printf("Ingrese una opcion para realizar las siguientes operaciones\n");
  printf("1. Consulta de saldo\n2. Retiro\n3. Deposito\n4. Salir\n");
  awnser = scanf("%d", &opt);
          if(awnser <= 0 || awnser == EOF || opt> 4){
             system("clear");
             fprintf(stderr, "Ingrese un numero comprendido entre 1 y 4\n");
             getchar();
             fflush(stdin);
             goto askAgain;           
             }
             switch(opt){
             case 1: system("clear");printf("El monto actual es %d\n", montoInicial); break;
             
             case 2: {
                int retire;
                askMontoR: 
                printf("Ingrese el monto para retirar\n");
                awnser = scanf("%d", &retire);
                    if(awnser <= 0 || awnser == EOF || retire > montoInicial){
                     fprintf(stderr, "Usted ingreso un monto invalido\n");
                     getchar();
                     system("clear");
                     fflush(stdin);
                     goto askMontoR;           
                     }
                     system("clear");  
             printf("Usted retiro de su cuenta %d Bss ", retire);
             montoInicial = montoInicial - retire;
             printf("y quedo con un saldo de %d Bss\n", montoInicial);   
             }
             break;
             
             case 3:{
                int deposit;
                askDeposit: 
                printf("Ingrese el monto para depositar\n");
                awnser = scanf("%d", &deposit);
                    if(awnser <= 0 || awnser == EOF || deposit <= 0){
                     getchar();
                     fprintf(stderr, "Ingrese un monto correcto\n");
                     system("clear");
                     fflush(stdin);
                     goto askDeposit;           
                     }
                     system("clear");  
             printf("Usted deposito de su cuenta %d Bss ", deposit);
             montoInicial = montoInicial + deposit;
             printf("y quedo con un saldo de %d Bss\n", montoInicial);    
             } 
              break; 
             case 4: correctPas = false;
             }
             
 }
   
 	
  return 0;
}
