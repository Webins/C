#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
/*
 *Un supermercado ha puesto en oferta la venta al por mayor de ciertos productos, ofreciendo un descuento del 15% de la compra de mas de tres docenas y el
 *10 % en caso contrario. Ademas, por la compra de mas de tres docenas se obsequia una unidad del producto por cada docena en exceso sobre 3.
 *
 *Desarrolle un programa que determine el monto de la compra, el monto del descuento, el monto a pagar y el numero de unidades de obsequios por la compra
 *de ciertas cantidades de docenas de producto
 * */
#define IVA 0.16
#define BSS "BSS"
#define DISC1 0.10
#define DISC2 0.15
#define DOZEN 12
#define PRICEARIEL 5
#define PRICEVANISH 4
#define PRICEAXION 3
#define MILLION 1000000
#define lenght 20
int countProducts(char str[10]);
char* noJump(char string[]);




int main(){
	time_t now;

	char name[lenght], city[lenght], state[lenght], ci[lenght], telf[lenght];
	char firstDigitsNumber[5][4] = {
		{"0414"},{"0424"},{"0416"},{"0426"},{"0412"}
	};
	
	char products[4], buyAgain[3];
	int arielQnty=0, arielQntyTotal=0, axionQnty =0,axionQntyTotal=0, vanishQnty=0,vanishQntyTotal=0, clientProduct=0, justOneTime=0, awnser=0, arielFree=0, vanishFree=0, axionFree=0, freeTotal=0;
	float resultAriel=0,arielPercValue, resultVanish=0,vanishPercValue,resultAxion=0,axionPercValue,resultTotal=0;
	system("clear");
	askNameAgain:
	printf("****BIENVENIDO A SUPER MERCADO PLAZA'S****\n\nPorfavor introduzca su nombre: \n");
	fgets(name, lenght -1, stdin);
		 for(int j = 0; name[j] != '\0'; j++){
			int c;
			c= toupper(name[j]);
			if((c > 64 && c<=90) || c== '\n');
			else {
				system("clear");
				printf("Por favor introduzca un nombre valido\n");
				fflush(stdin);
				goto askNameAgain;
			}
			name[j] = c;
		} 
	system("clear");
	int cedula=0;
	askCIAgain:

	printf("Porfavor introduzca su numero de cedula de identidad: \n");
	fgets(ci, lenght -1, stdin);
	cedula = atoi(ci);
	 if(cedula < MILLION|| cedula > (MILLION *50)){
			system("clear");
			printf("Por favor introduzca un numero de cedula valida\n");
			fflush(stdin);
				goto askCIAgain;
	} 
	system("clear");
	askTelfAgain:
	printf("Porfavor introduzca su numero de telefono: \n");
	fgets(telf, lenght -1, stdin);

		 //evaluar que empieze con 0414, 0412...
		for(int j=0; j<4; j++){
			if(telf[j] != firstDigitsNumber[0][j]){
				if(telf[j] != firstDigitsNumber[1][j]){
					if(telf[j] != firstDigitsNumber[2][j]){
						if(telf[j] != firstDigitsNumber[3][j]){
							if(telf[j] != firstDigitsNumber[4][j]){
								system("clear");
								printf("Por favor introduzca un numero de Venezuela\n");
								fflush(stdin);
								goto askTelfAgain;	
							}
						}
					}
				}
			}						
		}

		
		
	//evaluar que no tenga mas de 11 digitos
	if(isdigit(telf[11])){
		system("clear");
		printf("Por favor introduzca un numero correcto(11 digitos Vzla)\n");
			fflush(stdin);
			goto askTelfAgain;	
	}
	//evaluar que sea un numero
	for(int i =3; i< 10; i++){
		if(telf[i] < 48 || telf[i] >57){
			system("clear");
			printf("Por favor introduzca un numero correcto(11 digitos Vzla)\n");
			fflush(stdin);
			goto askTelfAgain;	
		}
	} 
	
	system("clear");
	askStateAgain:
	printf("Introduzca el nombre del estado donde reside\n");
	fgets(state, lenght -1, stdin);
		 for(int j = 0; state[j] != '\0'; j++){
			int c;
			c= toupper(state[j]);
			if((c > 64 && c<=90) || c== '\n' || c==32);
			else {
				system("clear");
				printf("Por favor introduzca un estado valido\n");
				fflush(stdin);
				goto askStateAgain;
			}
			state[j] = c;
		}
 
	system("clear");
	askCityAgain:
	printf("Introduzca el nombre de la ciudad donde reside\n");
	fgets(city, lenght -1, stdin);
	 	for(int j = 0; city[j] != '\0'; j++){
			int c;
			c= toupper(city[j]);
			if((c > 64 && c<=90) || c== '\n'|| c== 32);
			else {
				system("clear");
				printf("Por favor introduzca un nombre de ciudad valida\n");
				fflush(stdin);
				goto askCityAgain;
			}
			city[j] = c;
		} 
	system("clear");

	printf("\n\n\t\t\t\t\t_______________________________________________________________________\n"
			"\t\t\t\t\t|                          Super Mercado Plazas                       |\n"
			"\t\t\t\t\t|                                                                     |\n"
			"\t\t\t\t\t|En super mercado plazas estamos ofreciendo un 10%% por la compra de   |\n"
			"\t\t\t\t\t|ciertos productos de limpieza seleccionados. Ademas ofrecemos un 15%% |\n"
			"\t\t\t\t\t|por la compra de mas de 3 docenas en esos productos. Y aun mejor, si |\n"
			"\t\t\t\t\t|Si ya tienes mas de 3 docenas por cada 4 productos adicionales uno   |\n"
			"\t\t\t\t\t|te saldra gratis, ya sea Ariel, Vanish o Axion                       |\n");
	do{
	printf("\t\t\t\t\t|_____________________________________________________________________|\n");
	printf("\t\t\t\t\t|                       Productos en descuentos:                      |\n"
		   "\t\t\t\t\t|_____________________________________________________________________|\n"
		   "\t\t\t\t\t|      Producto 1:     |     Producto 2:    |       Producto 3:       |\n"
		   "\t\t\t\t\t|   Detergente Ariel   |   Vanish Multiuso  | Jabon lava platos Axion |\n"
		   "\t\t\t\t\t|          5$          |          4$        |           3$            |\n"
		   "\t\t\t\t\t|______________________|____________________|_________________________|\n\n\n");
		if(!justOneTime){
			sleep(1);
		}
		justOneTime =1;
	

	while(clientProduct <=0 || clientProduct >3){
	printf("\nPor favor indique el numero del producto a comprar\n");
	fgets(products, 4 , stdin);
	clientProduct = atoi(products);
	fflush(stdin);
	}
		switch(clientProduct){
			case 1: {
				system("clear");
				int arielPrice;
				arielQnty = countProducts("Ariel");
				arielQntyTotal+=arielQnty;
				arielPrice = (arielQnty * PRICEARIEL);
					if(arielQntyTotal < (DOZEN * 3)) {
						arielPercValue = arielPrice * DISC1;
						resultAriel+= (arielPrice - arielPercValue);
						printf("El monto de la compra es %d\nEl descuento es %.2f\nEl monto total es %.2f\n", arielPrice, arielPercValue, resultAriel);
					}
					else if(arielQntyTotal>=(DOZEN * 3)){

						for(int i = arielQnty; i > (DOZEN*3); i-=4){
							if(i <=39) continue;
							else arielFree++;
						}
						arielPercValue = arielPrice * DISC2;
						resultAriel+= (arielPrice - arielPercValue);
						freeTotal+= (arielFree * PRICEARIEL);
						printf("El monto de la compra de los productos ariel es %d\nEl descuesto es %.2f\nEl monto total es %.2f\n", arielPrice, arielPercValue, resultAriel);
						if(arielFree > 0) printf("Tienes %d producto ariel gratis", arielFree);

					}

		break;
		}
		case 2:{
			system("clear");
			int vanishPrice;
				vanishQnty = countProducts("Vanish");
				vanishQntyTotal+= vanishQnty;
				vanishPrice = (vanishQnty * PRICEVANISH);
					if(vanishQntyTotal < (DOZEN * 3)) {
						vanishPercValue = vanishPrice * DISC1;
						resultVanish+= (vanishPrice - vanishPercValue);
						printf("El monto de la compra de los productos vanish es %d\nEl descuento es de un %.2f\nEl monto total es %.2f\n", vanishPrice, vanishPercValue, resultVanish);
					}
					else if(vanishQntyTotal >=(DOZEN * 3)){
						for(int i = vanishQnty; i > (DOZEN*3); i-=4){
							if(i <=39) continue;
							else vanishFree++;
						}
						vanishPercValue = vanishPrice * DISC2;
						resultVanish += (vanishPrice - vanishPercValue);
						freeTotal+= (vanishFree *PRICEVANISH);
						printf("El monto de la compra de los productos vanish es %d\nEl descuesto es %.2f\nEl monto total es %.2f\n", vanishPrice, vanishPercValue, resultVanish);
						if(vanishFree > 0) printf("Tienes %d producto vanish gratis", vanishFree);

					}
		} 
		break;
		case 3: {
			system("clear");
			int axionPrice;
				axionQnty = countProducts("Axion");
				axionQntyTotal+= axionQnty;
				axionPrice = (axionQnty * PRICEAXION);
					if(axionQntyTotal < (DOZEN * 3)) {
						axionPercValue = axionPrice * DISC1;
						resultAxion+= (axionPrice - axionPercValue);
						printf("El monto de la compra de los productos axion es %d\nEl descuento es %.2f\nEl monto total es %.2f\n", axionPrice, axionPercValue, resultAxion);
					}
					else if(axionQntyTotal>=(DOZEN * 3)){

						for(int i = axionQnty; i > (DOZEN*3); i-=4){
							if(i <=39) continue;
							else axionFree++;
						}
						axionPercValue = axionPrice * DISC2;
						resultAxion +=(axionPrice - axionPercValue);
						freeTotal+= (axionFree *PRICEAXION);
						printf("El monto de la compra de los productos axion es %d\nEl descuesto es %.2f\nEl monto total es %.2f\n", axionPrice, axionPercValue, resultAxion);
						if(axionFree > 0) printf("Tienes %d producto axion gratis", axionFree);	
		} 

		break;
		}
		}
		back:
		printf("\n\n\n\t\t\t\t\t\t\t¿Termino su compra?\n");
		printf("\t\t\t\t\t\t\t0 Para salir\n\t\t\t\t\t\t\tCualquier numero para seguir\n");
		fgets(buyAgain, 3, stdin);
		awnser= atoi(buyAgain);
		if(awnser < 0){
			printf("Ingrese solo numeros\n");
			fflush(stdin);
			goto back;
		}
		system("clear");
		clientProduct=0;

    }while(awnser!= 0);
		char strTime[50];
		strcpy(strTime, ctime(&now));
		for(int k =0; k<49 ;k++){
		if(strTime[k] == '\n') strTime[k] = '\0';
}

		resultTotal = (resultAxion+resultAriel+resultVanish) - freeTotal;
		//factura
		printf("\t\t _________________________________________________________________________\n");
		printf("\t\t|*SUPER*                         |                 CLIENTE:               |\n"
			   "\t\t|    *MERCADO*                   |     NOMBRE     :%-20s   |\n"
			   "\t\t|           *PLAZA'S*            |CEDULA IDENTIDAD:%-20d   |\n"
			   "\t\t|*GENTE EN QUE CONFIAR*          |     ESTADO     :%-20s   |\n"
			   "\t\t|********************************|     CIUDAD     :%-20s   |\n"
			   "\t\t|********************************|    TELEFONO    :%-20s   |\n"
			   "\t\t|________________________________|________________________________________|\n"
			   "\t\t|                                                                         |\n"
               "\t\t|CONCEPTOS                                                                |\n"
               "\t\t|_________________________________________________________________________|\n",noJump(name), cedula, noJump(state), noJump(city), noJump(telf));
			   if(arielQnty!=0){
        printf("\t\t|CANTIDAD ARIEL=%5d  |PRECIO ARIEL = %-12.2f %-3s |ARIEL GRATIS=%3d |\n",arielQntyTotal, resultAriel, BSS, arielFree);
			   }
			   if(vanishQnty!=0){
        printf("\t\t|CANTIDAD VANISH=%5d |PRECIO VANISH= %-12.2f %-3s |VANISH GRATIS=%3d|\n", vanishQntyTotal, resultVanish, BSS, vanishFree);
			   }
			   if(axionQnty!=0){
        printf("\t\t|CANTIDAD AXION=%5d  |PRECIO AXION = %-12.2f %-3s |AXION GRATIS=%3d |\n", axionQntyTotal, resultAxion, BSS, axionFree);
			   }
			   printf("\t\t|                      |PRECIO TOTAL = %-12.2f %-3s |                 |\n", (resultAriel + resultAxion+ resultVanish), BSS);
        printf("\t\t|_________________________________________________________________________|\n"
               "\t\t|                      TOTAL BASE = %-15.2f %-3s                   |\n"
               "\t\t|                         I.V.A   = %.0f%-36c|\n"
               "\t\t|                         TOTAL   = %-15.2f %-3s                   |\n"
			   "\t\t|****************** VENEZUELA %-25s*******************|\n"
               "\t\t|_________________________________________________________________________|\n", resultTotal, BSS, (IVA *100), '%', ((resultTotal*IVA) +resultTotal), BSS, strTime);


printf("\n\n \t\t\t\tGRACIAS POR ELEGIR SUPER MERCADO PLAZA'S HASTA PRONTO");
	return 0;
}


int countProducts(char str[10]){
	char qnty[10];
	int totalQnty = 0;
	while(totalQnty<=0){
	printf("Ingrese la cantidad del producto %s\n", str);
	fgets(qnty, 10, stdin);
	totalQnty = atoi(qnty);
	}
	system("clear");
	return totalQnty;
}

char* noJump(char s[]){
    for(int i =0; i<lenght -1;i++){
		if(s[i] == '\n') s[i] = '\0';
}
    return s;
}

