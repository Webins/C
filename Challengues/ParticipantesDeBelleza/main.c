#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAXPOINTS 10
#define MINPOINTS 1
#define LENGHT 35
#define PARTICIPANTS 14
int main(){
    int i, awnser, sumIntelPoints, sumBeautyPoints, sumGeneralCulture, result, result2;
    i = awnser = sumIntelPoints= sumBeautyPoints= sumGeneralCulture= result= result2= 0;
    int indexMax, indexMin, highPoint, lowPoint;
    double sumTotalPoints;
    char firstName[LENGHT], lastName[LENGHT];
    //Arreglos de las participantes
    char firstNameTotal[PARTICIPANTS][LENGHT], lastNameTotal[PARTICIPANTS][LENGHT];
    //Arreglos de puntajes
    int intelPoints[PARTICIPANTS], beautyPoints[PARTICIPANTS], generalCulturePoints[PARTICIPANTS];
    //Arreglo del total de puntaje de cada participante
    int puntosTotales[PARTICIPANTS];

    while(i < PARTICIPANTS ){
         askFirstName:
        printf("Ingrese el nombre de la participante numero %d : \n", i+1);
        scanf("%s", firstName);
            for(int j =0; firstName[j] != '\0' && firstName[j] !='\n'; j++){
                if((tolower(firstName[j])) < 97 || (tolower(firstName[j])) >125){
                    fprintf(stderr, "El nombre introducido no es valido. Intente de nuevo\n");
                    sleep(1);
                    system("clear");
                    fflush(stdin);
                    goto askFirstName;
                }
            }       
        strcpy(firstNameTotal[i], firstName); 
        system("clear");
        askLastName:
        printf("Ingrese el apellido de la participante numero %d : \n", i+1);
        scanf("%s", lastName);
            for(int j =0; lastName[j] != '\0' && lastName[j] !='\n'; j++){
                if((tolower(lastName[j])) < 97 || (tolower(lastName[j])) >125){
                    fprintf(stderr, "El nombre introducido no es valido. Intente de nuevo\n");
                    sleep(1);
                    system("clear");
                    fflush(stdin);
                    goto askLastName;
                }
            }       
        strcpy(lastNameTotal[i], lastName); 
        system("clear");
        int c;
        askPointsI:
        printf("Introduzca el puntaje en inteligencia de la participante numero %d (%d-%d) : \n", i+1, MINPOINTS, MAXPOINTS);
        awnser = scanf("%d", &intelPoints[i]);
        printf("%d", awnser);
        while((c= getchar()) != EOF && c != '\n');
        if(awnser <=0 || intelPoints[i] < MINPOINTS || intelPoints[i] >MAXPOINTS){
            fprintf(stderr, "Seleccione un puntaje correcto\n");
            sleep(1);
            system("clear");
            fflush(stdin);
            goto askPointsI;
        }
        system("clear");
        askPointsB:
        printf("Introduzca el puntaje en belleza de la participante numero %d (%d-%d) : \n", i+1, MINPOINTS, MAXPOINTS);
        awnser = scanf("%d", &beautyPoints[i]);
        printf("%d", awnser);
        while((c= getchar()) != EOF && c != '\n');
        if(awnser <=0 || beautyPoints[i] < MINPOINTS || beautyPoints[i] >MAXPOINTS){
            fprintf(stderr, "Seleccione un puntaje correcto\n");
            sleep(1);
            system("clear");
            fflush(stdin);
            goto askPointsB;
        }
        system("clear");
        askPointsCG:
        printf("Introduzca el puntaje en belleza de la participante numero %d (%d-%d) : \n", i+1, MINPOINTS, MAXPOINTS);
        awnser = scanf("%d", &generalCulturePoints[i]);
        printf("%d", awnser);
        while((c= getchar()) != EOF && c != '\n');
        if(awnser <=0 || generalCulturePoints[i] < MINPOINTS || generalCulturePoints[i] >MAXPOINTS){
            fprintf(stderr, "Seleccione un puntaje correcto\n");
            sleep(1);
            system("clear");
            fflush(stdin);
            goto askPointsCG;
        }
        //sum totales de puntajes
        sumIntelPoints +=intelPoints[i];
        sumBeautyPoints += beautyPoints[i];
        sumGeneralCulture += generalCulturePoints[i];

        //sum puntos totales de cada participante
        puntosTotales[i] = intelPoints[i]+beautyPoints[i]+generalCulturePoints[i];
        sumTotalPoints += puntosTotales[i];
        i++;
    }
            // chequear por el mayor de los puntajes
        if(sumIntelPoints > sumBeautyPoints && sumIntelPoints > sumGeneralCulture) highPoint = sumIntelPoints;
        else if(sumBeautyPoints> sumIntelPoints && sumBeautyPoints> sumGeneralCulture) highPoint =sumBeautyPoints;
        else if(sumGeneralCulture > sumIntelPoints && sumGeneralCulture > sumBeautyPoints) highPoint = sumGeneralCulture;
        
        //chequear por el menor de los puntajes
        if(sumIntelPoints < sumBeautyPoints && sumIntelPoints < sumGeneralCulture) lowPoint = sumIntelPoints;
        else if(sumBeautyPoints< sumIntelPoints && sumBeautyPoints< sumGeneralCulture) lowPoint =sumBeautyPoints;
        else if(sumGeneralCulture < sumIntelPoints && sumGeneralCulture < sumBeautyPoints) lowPoint = sumGeneralCulture;

        //Chequear cual es la participante con el menor y la de mayor puntaje
        int max = puntosTotales[0];
        int min = puntosTotales[0];
            for(i =1; i< PARTICIPANTS; i++){
                if(puntosTotales[i] > max) {
                    max = puntosTotales[i];
                        if(puntosTotales[0] > max) indexMax = 0;
                        
                    indexMax = i;
                }
                if(min > puntosTotales[i]){
                    min = puntosTotales[i];
                        if(puntosTotales[0] < min) indexMin= 0;
                    indexMin= i;
                } 
                result = max;
                result2 = min;
            }
    
    system("clear");

    printf("\n");
    printf("El mayor resultado fue %d de la participante %s %s\n", result, firstNameTotal[indexMax], lastNameTotal[indexMax]);
    printf("El menor resultado fue %d de la participante %s %s\n", result2, firstNameTotal[indexMin], lastNameTotal[indexMin]);
    printf("La sumatoria total de los puntajes de inteligencia fue: %d\n", sumIntelPoints);
    printf("La sumatoria total de los puntajes de belleza fue:%d\n", sumBeautyPoints);
    printf("La sumatoria total de los puntajes de cultura general fue:%d\n", sumGeneralCulture);
    printf("La categoria de puntaje mas bajo fue %d, mientras que el mas alto fue %d\n", lowPoint, highPoint);
    printf("El promedio de puntaje por participante fue de %.2f \n", (sumTotalPoints / PARTICIPANTS));
    return 0;
}