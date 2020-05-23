/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
/*INCLUDES*/

/*DEFINES*/
#define FAILURE -1
#define SUCCESS 1
#define FILE_NAME "clientes.csv"
#define DEFAULT_COLOR FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define ERROR_COLOR FOREGROUND_RED | FOREGROUND_INTENSITY
#define TITLE_COLOR FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define INFO_COLOR FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define SUCCESS_COLOR FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define MAX_CLIENTS 1000
/*DEFINES*/

/*GLOBALS*/
FILE *csv_file;
HANDLE hConsole;
typedef struct Client {
    int id;
    char name[21];
    char last_name[21];
    char telf[12];
    char cel[12];
    char email[51];
    char city[31];
    char country[26];
    char deuda[18];
}clients;
clients clients_array[sizeof(clients) *MAX_CLIENTS];
unsigned int lines=1;
/*GLOBALS*/

/*PROTOTYPES*/
int input(char[], int max_size, int flag); //modulo para entrada de datos
void validateSecurityCode(void); // validacion codigo de seguridad

/*funciones de clientes*/
void addClients(void); //modulo para agregar clientes
void showAllClients(void);//modulo para mostrar los datos de los clientes
int searchClient(int, char *); // modulo para buscar clientes
void modifyClient(void); // modulo para editar clientes
void showClientsDebts(void); // modulo para mostrar clientes con deudas
void removeClient(int ); // modulo para eliminar un cliente
int printClient(const clients *, int); //muestra en pantalla un cliente
void showClientsAndRemove(void);
/*funciones de clientes*/

/*funciones auxiliares*/
void initColors(void); //inicializa los colores en la pantalla
char * getLine(int *);
void substr(char *, char *, int);
void deleteNL(char s[]);
int validateDouble(char s[]);
void showMenu(); //menu principal
/*funciones auxiliares*/

/*funciones de archivos */
void initFile(void);
void writeToFile(const clients *, int flag);
/*funciones de archivos */
/*PROTOTYPES*/



/*KLEIVER MARCANO CI:26180407 PROGRAMACION II 502
  PROYECTO AGENDA DIGITAL PARTE 3 */
int main(){
    bool once = true;
    bool run = true;
    char *dec_menu = (char *)malloc(2);
    char *dec_exit = (char *)malloc(2);
    initColors();
    printf("\t\t\t\t");
    SetConsoleTextAttribute(hConsole, TITLE_COLOR);
    printf("===BIENVENIDO A SU AGENDA DIGITAL===\n\n");
    while(run){
    if(once) {
        validateSecurityCode();
        once = false;
        initFile();
    }
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
        ask_menu:
        showMenu();
        if(input(dec_menu, 2, 1) == FAILURE){
            fflush(stdin);
            goto ask_menu;
        };
       system("cls");
       switch(tolower(dec_menu[0])){
        case 'a': addClients(); break;
        case 'b': showAllClients(); break;
        case 'c': searchClient(1, ""); break;
        case 'd': modifyClient(); break;
        case 'e': showClientsDebts(); break;
        case 'f': showClientsAndRemove(); break;
        case 'g':{
        	ask_exit:
            SetConsoleTextAttribute(hConsole, INFO_COLOR);
        	printf("Estas seguro de salir? s/n :");
			SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
			if(input(dec_exit, 2, 2) == FAILURE){
				fflush(stdin);
				goto ask_exit;
			}
			if(tolower(dec_exit[0]) == 's') {
				system("cls");
				printf("Saliendo...\n");
				run = false;
			}else {
                system("cls");
			}
			break;
		}
       }

    }

    free(dec_exit);
    free(dec_menu);
    dec_exit = NULL;
    dec_menu= NULL;
    return 0;
}



void validateSecurityCode(void){
    char bin_code[9];
    ask_code:
    SetConsoleTextAttribute(hConsole, INFO_COLOR);
    printf("Introduzca el codigo de seguridad para continuar: ");
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
    int code = input(bin_code, 9, 0);
    if(code == FAILURE){
        fflush(stdin);
        goto ask_code;
    }else{
        SetConsoleTextAttribute(hConsole, SUCCESS_COLOR);
        printf("Codigo correcto\n");
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
    }
}


void showAllClients(void){
    int i;
    if((lines) == 3) {
        SetConsoleTextAttribute(hConsole, INFO_COLOR);
        printf("No ha agregado ningun cliente a la agenda\n");
        printf("Agrege clientes para poder ver sus datos\n");
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
        return;
    }
    for(i =0; i < lines -3; i++){
        printClient(&clients_array[i], 1);
    }
}

void addClients(void){
    char * name = (char *)malloc(21);
    char * last_name= (char *)malloc(21);
    char * telf= (char *)malloc(12);;
    char * cel= (char *)malloc(12);
    char * email= (char *)malloc(51);
    char * city= (char *)malloc(31);
    char * country= (char *)malloc(26);
    char * deuda = (char *)malloc(18);
    char * selc = (char *) malloc(2);
    ask_again:
    SetConsoleTextAttribute(hConsole, INFO_COLOR);
    printf("Se procedera a requerir los datos necesarios para a%cadir un nuevo cliente a la agenda\n", -92);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);

    ask_name:
    printf("Introduzca el nombre: ");
    if(input(name, 21, 3) == FAILURE){
        fflush(stdin);
        goto ask_name;
    }

    system("cls");
    ask_last_name:
    printf("Introduzca el apellido: ");
     if(input(last_name, 21, 4) == FAILURE){
        fflush(stdin);
        goto ask_last_name;
    }

    system("cls");
    ask_telf:
    printf("Introduzca el numero de telefono: ");
     if(input(telf, 12, 5) == FAILURE){
        fflush(stdin);
        goto ask_telf;
    }
    if(searchClient(0, telf) == FAILURE){
        fflush(stdin);
        goto ask_telf;
    }


    system("cls");
    ask_cel:
    printf("Introduzca el numero de celular: ");
     if(input(cel, 12, 6) == FAILURE){
        fflush(stdin);
        goto ask_cel;
    }

    system("cls");
    ask_email:
    printf("Introduzca el correo electronico: ");
     if(input(email, 51, 7) == FAILURE){
        fflush(stdin);
        goto ask_email;
    }


    system("cls");
    ask_city:
    printf("Introduzca la ciudad: ");
     if(input(city, 31, 8) == FAILURE){
        fflush(stdin);
        goto ask_city;
    }


    system("cls");
    ask_country:
    printf("Introduzca el pais: ");
     if(input(country, 26, 9) == FAILURE){
        fflush(stdin);
        goto ask_country;
    }

    system("cls");
    ask_selec:
    printf("Indique si el cliente actual tiene deudas s/n: ");
     if(input(selc, 2, 2) == FAILURE){
        fflush(stdin);
        goto ask_selec;
    }
    if(!strcmp(selc, "s")){
        system("cls");
        ask_deuda:
        printf("Introduzca el monto de deuda: ");
        if(input(deuda, 18+1, 10) == FAILURE){
            fflush(stdin);
            goto ask_deuda;
        }
    }else{
        strcpy(deuda, "Sin deuda");
    }


    bool val_city_num = false;
    char prefix[4];
    substr(telf, prefix, 4);

    if(!strcmp(prefix, "0212")){
        if(!strcmp(city, "caracas"))
            val_city_num = true;
    }else if(!strcmp(prefix, "0243")){
       if(!strcmp(city, "maracay"))
            val_city_num =true;
    }
    else if(!strcmp(prefix, "0241")){
       if(!strcmp(city, "valencia"))
            val_city_num =true;
    }
    else if(!strcmp(prefix, "0251")){
       if(!strcmp(city, "barquisimeto"))
            val_city_num =true;
    }
    else if(!strcmp(prefix, "0261")){
       if(!strcmp(city, "maracaibo"))
            val_city_num =true;
    }
    if(!val_city_num){
        system("cls");
        fflush(stdin);
        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
        printf("El numero de telefono introducido no concuerda con la ciudad especificada\n");
        printf("Presione cualquier tecla para introducir los datos nuevamente: ");
        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
        getchar();
        system("cls");
        goto ask_again;
    }
        clients c;
        strncpy(c.name, name, strlen(name)+1);
        strncpy(c.last_name, last_name, strlen(last_name)+1);
        strncpy(c.cel, cel, strlen(cel)+1);
        strncpy(c.telf, telf, strlen(telf)+1);
        strncpy(c.email, email, strlen(email)+1);
        strncpy(c.country, country, strlen(country)+1);
        strncpy(c.city, city, strlen(city)+1);
        strncpy(c.deuda, deuda, strlen(deuda) +1);
        c.id = lines-2;
        system("cls");
        SetConsoleTextAttribute(hConsole,SUCCESS_COLOR);
        printf("\t\tCliente A%cadido correctamente\n\n", -92);
        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
        printClient(&c,0);
        writeToFile(&c,0);
        clients_array[lines-3] =c;
        free(name);
        name = NULL;
        free(last_name);
        last_name= NULL;
        free(cel);
        cel= NULL;
        free(telf);
        telf= NULL;
        free(email);
        email= NULL;
        free(country);
        country= NULL;
        free(city);
        city= NULL;
        free(deuda);
        deuda = NULL;
        free(selc);
        selc= NULL;
        lines++;
}

int printClient(const clients * c, int flag){
    if(flag){
        SetConsoleTextAttribute(hConsole,INFO_COLOR);
        printf("\t\tCliente numero: %d de : %d\n", c->id, (lines-3));
        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
    }

    printf("|-------------------------Cliente:-------------------------|\n");
    printf("|Nombre: %-20s                              |\n", c->name);
    printf("|Apellido: %-20s                            |\n", c->last_name);
    printf("|Correo: %-50s|\n", c->email);
    printf("|Telefono: %-11s                                     |\n", c->telf);
    printf("|Celular: %-11s                                      |\n", c->cel);
    printf("|Ciudad: %-30s                    |\n", c->city);
    printf("|Pais: %-25s                           |\n", c->country);
    printf("|Deuda: %-18s                                 |\n", c->deuda);
    printf("|----------------------------------------------------------|\n");
    if(flag == 2){
        char * selc = (char *)malloc(2);
        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
        ask_again:
        printf("Desea eliminar al cliente numero %d?", c->id);
        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
        printf(" s/n: ");
        if(input(selc, 2, 2) == FAILURE){
            fflush(stdin);
            goto ask_again;
        }
        system("cls");
        if(selc[0] =='s'){
            removeClient(c->id);
            SetConsoleTextAttribute(hConsole,SUCCESS_COLOR);
            printf("Cliente removido con exito\n");
            SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
            free(selc);
            selc = NULL;
            return SUCCESS;
        }
        free(selc);
        selc = NULL;
    }else{
    printf("\nPresione una tecla para continuar: ");
    getchar();
    }
    system("cls");
}

int searchClient(int flag, char * telf_init){
    if(lines == 3){
        if(!flag) return SUCCESS;
        else {
            system("cls");
            SetConsoleTextAttribute(hConsole, INFO_COLOR);
            printf("No hay clientes en la agenda para buscar\n");
            printf("Agrega un nuevo cliente antes\n");
            SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
            return FAILURE;
        }
    }
    int i;
    if(!flag){
        for(i =0; i < lines-3; i++){
            if(!strcmp(clients_array[i].telf, telf_init)){
                system("cls");
                SetConsoleTextAttribute(hConsole, ERROR_COLOR);
                printf("El telefono introducido ya le pertenece a otro cliente\nIntroduzca un nuevo numero de telefono\n");
                SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
                return FAILURE;
            }
        }
        return SUCCESS;
    }
    char * telf = (char *) malloc(12);
    system("cls");
    ask_telf:
    printf("Introduzca el numero de telefono del cliente a buscar: ");
     if(input(telf, 12, 5) == FAILURE){
        fflush(stdin);
        goto ask_telf;
    }
    for(i =0; i < lines-3; i++){
        if(!strcmp(clients_array[i].telf, telf)){
            system("cls");
            SetConsoleTextAttribute(hConsole, SUCCESS_COLOR);
            printf("Cliente encontrado!\n");
            SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
            printClient(&clients_array[i], 0);
            free(telf);
            telf = NULL;
            return (clients_array[i].id -1);
        }
    }
    system("cls");
    SetConsoleTextAttribute(hConsole, ERROR_COLOR);
    printf("El cliente con el numero %s no existe en la agenda\n", telf);
    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
    free(telf);
    telf = NULL;
    return FAILURE;
}

void showClientsDebts(void){
    if((lines) == 3) {
        SetConsoleTextAttribute(hConsole, INFO_COLOR);
        printf("No ha agregado ningun cliente a la agenda\n");
        printf("Agrege clientes para poder ver sus datos\n");
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
        return;
    }
    int lenght =0, i=0;
    int indexes[200];
    for(i =0; i < lines -3; i++){
        if(strtod(clients_array[i].deuda, NULL) > 0){
           indexes[lenght] = i;
           lenght ++;
        }
    }
    if(lenght){
        for(i =0; i< lenght; i++){
            SetConsoleTextAttribute(hConsole, INFO_COLOR);
            printf("\tCliente con deuda numero: %d de total : %d\n", i+1, lenght);
            SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
            printClient(&clients_array[indexes[i]], 0);
        }
    }else{
        SetConsoleTextAttribute(hConsole, INFO_COLOR);
        printf("No hay clientes con deudas actualmente\n");
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
    }
}

void modifyClient(void){
    int index;
    if((index=searchClient(1,"nothing")) != FAILURE){
        char * opt = (char *) malloc(2);
        while(true){
            ask_menu:
            SetConsoleTextAttribute(hConsole,INFO_COLOR);
            printf("Eliga que campo del cliente quiere modificar\n");
            SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
            printf("(a) Nombre\n");
            printf("(b) Apellido\n");
            printf("(c) Telefono\n");
            printf("(d) Celular\n");
            printf("(e) Correo\n");
            printf("(f) Deuda\n");
            printf("(g) Volver al menu\n");
            printf(": ");
            if(input(opt, 2, 1) == FAILURE){
                fflush(stdin);
                goto ask_menu;
            };
            switch(opt[0]){
                case 'a': {
                    char * name = (char *)malloc(21);
                    system("cls");
                    ask_name:
                    printf("Introduzca el nuevo nombre: ");
                    if(input(name, 21, 3) == FAILURE){
                        fflush(stdin);
                        goto ask_name;
                    }
                    strncpy(clients_array[index].name, name, strlen(name)+1);
                    free(name);
                    name = NULL;

                };break;
                case 'b':{
                    char * last_name= (char *)malloc(21);
                    system("cls");
                    ask_last_name:
                    printf("Introduzca el apellido: ");
                    if(input(last_name, 21, 4) == FAILURE){
                        fflush(stdin);
                        goto ask_last_name;
                    }
                    strncpy(clients_array[index].last_name, last_name, strlen(last_name)+1);
                    free(last_name);
                    last_name = NULL;
                } ;break;
                case 'c': {
                    char * telf= (char *)malloc(12);
                    system("cls");
                    ask_telf:
                    printf("Introduzca el nuevo telefono");
                    SetConsoleTextAttribute(hConsole,INFO_COLOR);
                    printf("(Al modificar el numero de telefono de un cliente modifica tambien la ciudad)");
                    SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                    printf(": ");
                    if(input(telf, 12, 5) == FAILURE){
                        fflush(stdin);
                        goto ask_telf;
                    }
                    if(searchClient(0, telf) == FAILURE){
                        fflush(stdin);
                        goto ask_telf;
                    }
                    bool val_city_num = false;
                    char prefix[4];
                    substr(telf, prefix, 4);

                    if(!strcmp(prefix, "0212")){
                        strcpy(clients_array[index].city, "caracas");
                    }else if(!strcmp(prefix, "0243")){
                        strcpy(clients_array[index].city, "maracay");
                    }
                    else if(!strcmp(prefix, "0241")){
                       strcpy(clients_array[index].city, "valencia");
                    }
                    else if(!strcmp(prefix, "0251")){
                       strcpy(clients_array[index].city, "barquisimeto");
                    }
                    else if(!strcmp(prefix, "0261")){
                        strcpy(clients_array[index].city, "maracaibo");
                    }
                    strncpy(clients_array[index].telf, telf, strlen(telf)+1);
                    free(telf);
                    telf = NULL;
                };break;
                case 'd':{
                    char * cel= (char *)malloc(12);
                    system("cls");
                    ask_cel:
                    printf("Introduzca el nuevo celular: ");
                    if(input(cel, 12, 6) == FAILURE){
                        fflush(stdin);
                        goto ask_cel;
                    }
                    strncpy(clients_array[index].cel, cel, strlen(cel)+1);
                    free(cel);
                    cel = NULL;
                };break;
                case 'e':{
                    char * email= (char *)malloc(51);
                    system("cls");
                    ask_email:
                    printf("Introduzca el nuevo correo electronico: ");
                    if(input(email, 51, 7) == FAILURE){
                        fflush(stdin);
                        goto ask_email;
                    }
                    strncpy(clients_array[index].email, email, strlen(email)+1);
                    free(email);
                    email = NULL;
                };break;
                case 'f':{
                    char * deuda = (char *)malloc(18);
                    system("cls");
                    ask_debt:
                    printf("Introduzca el nuevo monto de deuda: ");
                    if(input(deuda, 18, 10) == FAILURE){
                        fflush(stdin);
                        goto ask_debt;
                    }
                    strncpy(clients_array[index].deuda, deuda, strlen(deuda) +1);
                    free(deuda);
                    deuda = NULL;
                };break;
                case 'g': {
                free(opt);
                opt = NULL;
                return;
                }; break;
            }
            system("cls");
            SetConsoleTextAttribute(hConsole,SUCCESS_COLOR);
            printf("Cliente modificado\n");
            SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
            printClient(&clients_array[index],0);
            writeToFile(&clients_array[index], 1);
            ask_mod:
            SetConsoleTextAttribute(hConsole,INFO_COLOR);
            printf("Desea modifcar otro campo del cliente %s? s/n: ", clients_array[index].name);
            SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
            if(input(opt, 2, 2) == FAILURE){
                fflush(stdin);
                goto ask_mod;
            }
            if(opt[0] == 'n'){
                free(opt);
                opt = NULL;
                system("cls");
                return;
            }
            system("cls");
        }
    }
}

void showClientsAndRemove(void){
     if((lines) == 3) {
        SetConsoleTextAttribute(hConsole, INFO_COLOR);
        printf("No ha agregado ningun cliente a la agenda\n");
        SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
        return;
    }
    int i;
    for(i =0; i < lines-3; i++){
        if(printClient(&clients_array[i], 2) == SUCCESS){
            return;
        }
    }
}


void removeClient(int idc){
    int i =0 , j=0, max = lines-3, id = idc-1;
    for(i =0; i< max; i++){
        if(i==id){ //found
                continue;
        }else{
            clients_array[j]= clients_array[i];
            clients_array[j].id = j+1;
            j++;
        }
    }
    lines--;
       writeToFile(&clients_array[idc], 1);
}


void initFile(void){
 csv_file = fopen(FILE_NAME, "r");
    if(!csv_file){
            csv_file = fopen(FILE_NAME, "a");
            if(!csv_file){
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("Hubo un error al abrir el archivo \"%s\"\n", FILE_NAME);
                printf("La agenda no funcionara correctamente por lo que se cerrara el programa\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                printf("Presione cualquier tecla...\n");
                getchar();
                exit(-1);
            }
    }
    fseek(csv_file, 0, SEEK_END);
    bool empty = true;
    if(!((unsigned long) ftell(csv_file))){
        fprintf(csv_file, "sep=,\n");
        fprintf(csv_file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n","#","Nombre", "Apellido", "Telefono", "Celular", "Correo electronico", "Ciudad", "Pais", "Deuda");
        lines+=2;
    }else empty = false;
    if(!empty){
        rewind(csv_file);
        char buff[1024];
        while(fgets(buff, 1024, csv_file)){
        clients c;
            if(lines >2 ){
                char temp[51];
                int field =0, i=0, j=0;
                for(i =0; buff[i] != '\0' && buff[i] != EOF; i++){
                    if(buff[i] == ','  || buff[i] == '\n'){
                        temp[j] = '\0';
                        switch(field){
                        case 0: c.id= (atoi(temp)); break;
                        case 1: strcpy(c.name, temp); break;
                        case 2: strcpy(c.last_name, temp); break;
                        case 3: strcpy(c.telf, temp); break;
                        case 4: strcpy(c.cel, temp); break;
                        case 5: strcpy(c.email, temp); break;
                        case 6: strcpy(c.city, temp); break;
                        case 7: strcpy(c.country, temp); break;
                        case 8: strcpy(c.deuda, temp); break;
                        }
                        j=0;
                        field++;
                        strcpy(temp, "");
                    }else{
                    temp[j] = buff[i];
                    j++;
                    }
                 }
                clients_array[lines-3] = c;
            }
            lines++;
        }
    }
    fclose(csv_file);
    csv_file = NULL;
}

void writeToFile(const clients * c, int flag){
     if(flag >0 ){
       csv_file = fopen(FILE_NAME, "w+");
        if(!csv_file){
            SetConsoleTextAttribute(hConsole,ERROR_COLOR);
            printf("Hubo un error al abrir el archivo \"%s\"\n", FILE_NAME);
            printf("La agenda no funcionara correctamente por lo que se cerrara el programa\n");
            SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
            printf("Presione cualquier tecla...\n");
            getchar();
            exit(-1);
        }
        int new_line = 1;
        fprintf(csv_file, "sep=,\n");
        fprintf(csv_file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n","#","Nombre", "Apellido", "Telefono", "Celular", "Correo electronico", "Ciudad", "Pais", "Deuda");
        while(new_line < lines){
            if(new_line > 2){
                int index = new_line -3;
                 fprintf(csv_file, "%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
                         clients_array[index].id, clients_array[index].name, clients_array[index].last_name,
                         clients_array[index].telf, clients_array[index].cel, clients_array[index].email,
                         clients_array[index].city, clients_array[index].country, clients_array[index].deuda);
            }
            new_line++;
        }
    }else{
    csv_file = fopen(FILE_NAME, "a");
    if(!csv_file){
        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
        printf("Hubo un error al abrir el archivo \"%s\"\n", FILE_NAME);
        printf("La agenda no funcionara correctamente por lo que se cerrara el programa\n");
        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
        printf("Presione cualquier tecla...\n");
        getchar();
        exit(-1);
    }
    fprintf(csv_file, "%d,%s,%s,%s,%s,%s,%s,%s,%s\n", c->id, c->name, c->last_name, c->telf, c->cel, c->email, c->city, c->country, c->deuda);
    }
    fclose(csv_file);
    csv_file = NULL;
}



int input(char entry[], int max_size, int flag){
    int count = 0, i =0;
    char *input_string = NULL;
    input_string = getLine(&count);
    if(count > (max_size-1)){
        system("cls");
        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
        if(flag == 0) printf("El codigo de seguridad debe contener exactamente 8 digitos\n");
        else printf("El valor entrante es mas grande de lo solicitado\nIntroduzca un maximo de %d %s\n", (max_size-1), ((max_size-1)==1?"caracter":"caracteres"));
        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
        free(input_string);
        input_string = NULL;
        return FAILURE;
    }
    switch(flag){
        case 0 : {
            int j =0, k =0;
            char first[4], second[4];
            system("cls");
            if(count < (max_size-1)){
                 SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                 printf("El codigo de seguridad debe contener exactamente 8 digitos\n");
                 SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                 free(input_string);
                 input_string = NULL;
                 return FAILURE;
            }else{
                for(i =0; i < (max_size-1); i++){
                    if(input_string[i] == '0' || input_string[i] == '1'){
                        if(i == 4) first[i] = '\0';
                        if(i < 4) first[i] = input_string[i];
                        else {
                            second[j] = input_string[i];
                            j++;
                        }
                    }
                    else{
                        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                        printf("Solo se admiten numeros binarios (0 1)\n");
                        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                        free(input_string);
                        input_string = NULL;
                        return FAILURE;
                    }
                }
            }
            second[4] = '\0';
            /*Si la suma de los unos (1) de las primeras 4 cifras es igual a la suma de ceros(0) de
            las 4 cifras menos significativas*/
            j =0;
            for(i = 0; i< 4; i++){
                if(first[i] == '1') k++;
                if(second[i] == '0') j++;
            }
            if(j != k) {
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El codigo de verificacion es incorrecto\nIntente de nuevo\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            input_string[max_size] = '\0';
            int code = atoi(input_string);
            free(input_string);
            input_string = NULL;
            return code;
            break;
        }
        case 1 : {
             char menu_opts[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
             input_string[max_size] = '\0';
             for(i = 0; i < 7; i++){
                if(tolower(*input_string) == menu_opts[i]) {
                    strncpy(entry, input_string, max_size);
                    free(input_string);
                    return SUCCESS;
                }
             }
              break;
        }
        case 2: {
        	 char exit[2] = {'s','n'};
        	 input_string[max_size] = '\0';
             for(i = 0; i < 2; i++){
                if(tolower(*input_string) == exit[i]) {
                    strncpy(entry, input_string, max_size);
                    free(input_string);
                    return SUCCESS;
                }
            }
            break;
        }
        case 3: {
            if(count < 3 ){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El nombre debe contener mas de 2 caracteres\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            for(i = 0; input_string[i] != '\0'; i++){
                if(!isdigit(input_string[i]) && !ispunct(input_string[i]) && !isspace(input_string[i])){
                    input_string[i] = tolower(input_string[i]);
                }
                else {
                    system("cls");
                    SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                    printf("Introduzca un nombre valido(ejemplo: Pedro)\n");
                    SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                    free(input_string);
                    input_string = NULL;
                    return FAILURE;
                }
            }
            strncpy(entry, input_string, max_size);
            free(input_string);
            return SUCCESS;
        }
        case 4: {
             if(count < 3 ){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El nombre debe contener mas de 2 caracteres\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            for(i = 0; input_string[i] != '\0'; i++){
                if(!isdigit(input_string[i]) && !ispunct(input_string[i]) && !isspace(input_string[i])){
                    input_string[i] = tolower(input_string[i]);
                }
                else {
                    system("cls");
                    SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                    printf("Introduzca un apellido valido(ejemplo: Rodriguez)\n");
                    SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                    free(input_string);
                    input_string = NULL;
                    return FAILURE;
                }
            }
            strncpy(entry, input_string, max_size);
            free(input_string);
            return SUCCESS;
        }
        case 5: {
            int i, j;
            bool val_prefix = false;
            const char *codes [5] = {"0212", "0243", "0241", "0251", "0261"};
            char test[4];
            char prefix[4];
            substr(input_string, prefix, 4);
            for(i =0; i < 5; i++){
                if(strcmp(codes[i], prefix) == 0) val_prefix= true;
            }
            if(!val_prefix){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El codigo de area introducido es invalido\nLos codigos de areas disponibles son (0212, 0243, 0241, 0251, 0261)\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }else{
                 for(i = 4; i < (max_size-1); i++){
                    if(!isdigit(input_string[i])){
                        system("cls");
                        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                        printf("El numero de telefono introducido es invalido\nIntente de nuevo\n");
                        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                        free(input_string);
                        input_string = NULL;
                        return FAILURE;
                    }
                }
                strncpy(entry, input_string, max_size);
                free(input_string);
                return SUCCESS;
            }
        }
        case 6: {
            int i, j;
            bool val_prefix = false;
            const char *codes [5] = {"0414", "0424", "0412", "0416", "0426"};
            char test[4];
            char prefix[4];
            substr(input_string, prefix, 4);
            for(i =0; i < 5; i++){
                if(strcmp(codes[i], prefix) == 0) val_prefix= true;
            }
            if(!val_prefix){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El codigo de area introducido es invalido\nLos codigos de areas disponibles son (0414, 0424, 0412, 0416, 0426)\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }else{
                 for(i = 4; i < (max_size-1); i++){
                    if(!isdigit(input_string[i])){
                        system("cls");
                        SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                        printf("El numero introducido es invalido\nIntente de nuevo\n");
                        SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                        free(input_string);
                        input_string = NULL;
                        return FAILURE;
                    }
                }
                strncpy(entry, input_string, max_size);
                free(input_string);
                return SUCCESS;
            }

        }
        case 7: {
            const char * domains[4] = {"@gmail.com", "@hotmail.com", "@yahoo.es", "@outlook.com"};
            if(isdigit(input_string[0]) || ispunct(input_string[0]) || isspace(input_string[0]) || input_string[0] == '-' ||
               input_string[0] =='_' || input_string[0] == '/'){
                    system("cls");
                    SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                    printf("El correo no puede empezar con caracteres especiales o numeros\n");
                    SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                    free(input_string);
                    input_string = NULL;
                    return FAILURE;
               }
            char * domain_start  = strchr(input_string, '@');
            if(domain_start == NULL) {
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El correo es invalido, recuerda incluir el @\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            bool found = false;
            for(i = 0; i < 4; i++){
                if(strcmp(domain_start, domains[i]) != 0) continue;
                else found = true;
            }
            if(!found){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El correo es invalido, recuerda incluir el dominio del correo\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            strncpy(entry, input_string, max_size);
            free(input_string);
            return SUCCESS;
        }
        case 8:{
            int i;
            bool val_city = false;
            for(i = 0; input_string[i] != '\0'; i++){
                input_string[i] = tolower(input_string[i]);
            }
            const char *cities[5]= {{"caracas"}, {"maracay"}, {"valencia"} , {"barquisimeto"}, {"maracaibo"} };
            for(i =0; i < 5; i++){
                if(strcmp(cities[i], input_string) == 0) val_city= true;
            }
            if(!val_city){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("La ciudad es invalida\nLas ciudades disponible son (Caracas, Maracay, Valencia, Barquisimeto y Maracaibo)\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            strncpy(entry, input_string, max_size);
            free(input_string);
            return SUCCESS;
        }
        case 9: {
          int i;
          for(i = 0; input_string[i] != '\0'; i++){
                input_string[i] = tolower(input_string[i]);
          }
          if(strcmp(input_string, "venezuela") != 0){
            system("cls");
            SetConsoleTextAttribute(hConsole,ERROR_COLOR);
            printf("Solamente se acepta como pais Venezuela\nIntente de nuevo\n");
            SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
            free(input_string);
            input_string = NULL;
            return FAILURE;
          }
            strncpy(entry, input_string, max_size);
            free(input_string);
            return SUCCESS;
        }
        case 10: {
            if(validateDouble(input_string) == FAILURE){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El monto introducido es invalido\nsolo numeros reales pueden mayores a cero son aceptados\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }
            if(strtod(input_string, NULL) < 0.0){
                system("cls");
                SetConsoleTextAttribute(hConsole,ERROR_COLOR);
                printf("El monto introducido es invalido\nIntroduzca solo numeros positivos\n");
                SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
                free(input_string);
                input_string = NULL;
                return FAILURE;
            }else if(strtod(input_string, NULL) ==0.0){
                strcpy(entry, "Sin deuda");
                free(input_string);
                return SUCCESS;
            }
            strcpy(entry, input_string);
            free(input_string);
            return SUCCESS;
        }
    }
    system("cls");
    SetConsoleTextAttribute(hConsole,ERROR_COLOR);
    printf("Por favor introduzca una opcion valida\n");
    SetConsoleTextAttribute(hConsole,DEFAULT_COLOR);
    free(input_string);
    input_string = NULL;
    return FAILURE;
}



void showMenu(){
    printf("Seleccione una opcion:\n");
    printf("(a) Agregar cliente\n");
    printf("(b) Ver datos de todos los clientes\n");
    printf("(c) Buscar clientes por telefono\n");
    printf("(d) Modificar datos de un cliente\n");
    printf("(e) Listar clientes con deudas\n");
    printf("(f) Borrar un cliente\n");
    printf("(g) Salir\n");
    printf(": ");
}

void initColors(void){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
}

void substr(char *string, char *substring, int pos){
    int i;
    for(i = 0; i < pos; i++){
        substring[i] = string[i];
    }
    substring[pos] = '\0';
}

void deleteNL(char s[]){
   unsigned short int i;
    for(i =0; i < strlen(s); i++){
        if(s[i] =='\n') s[i] = '\0';
    }
}

int validateDouble(char s[]){
    deleteNL(s); //BORRAR NEWLINE CHARACTER
    double n;
    short unsigned int i, j, k, m;
    while(s[0] != '\0'){ //MIENTRAS QUE EL STRING NO ESTE VACIO
    if(isdigit(s[0])){ // EVALUA CUANDO ES UN DIGITO
        if(s[0] =='0'){  //EVALUA CUANDO ES 0
            if(s[1] =='\0') return SUCCESS;
            else if(s[1] =='.'){ //EVALUA CUANDO ES 0 CON DECIMAL
            if(s[2] =='\0') return FAILURE;
                    for(i=2, j=3; s[i] !='\0'; j++, i++){
                        if(!isdigit(s[i])) return FAILURE;
                        else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
                    }

                }
            else return FAILURE;
        }
        else if(s[1] =='\0') return SUCCESS;
        else if(isdigit(s[1])){
            if(s[2] =='\0') return SUCCESS;
            for(i=2, j=3; s[i] !='\0';i++, j++){
                if(s[i] =='.'){
                    if(s[i+1] =='\0') return FAILURE;
                        for(k=j, m=j+1; s[k] !='\0'; m++, k++){
                            if(!isdigit(s[k])) return FAILURE;
                            else if(s[m] ='\0' && isdigit(s[k])) return SUCCESS;
                            else if(isdigit(s[k])) continue;
                        }
                }
                else if(!isdigit(s[i])) return FAILURE;
                else if(isdigit(s[i]) && s[j] =='\0') return SUCCESS;
            }
        }
        else if(s[1] =='.'){
             if(s[2] =='\0') return FAILURE;
             else if(isdigit(s[2])){
                        for(i=2, j=3; s[i] !='\0'; i++, j++){
                            if(!isdigit(s[i])) return FAILURE;
                            else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
                        }
             }
             else return FAILURE;
        }
        else return FAILURE;

    }
    //EVALUA LA PARTE NEGATIVA
    else if(s[0] =='-'){
        if(s[1] =='\0') return FAILURE;
        else if(s[1] == '0'){
            if(s[2] =='\0') return FAILURE;
            else if(s[2] =='.'){
            if(s[3] =='\0') return FAILURE;
                for(i=3, j=4; s[i] !='\0'; j++, i++){
                    if(!isdigit(s[i])) return FAILURE;
                    else if(isdigit(s[i])) continue;
                    else if(s[j] =='\0' && isdigit(s[i])) return SUCCESS;
                }
            }
            else return FAILURE;
        }
        else if(isdigit(s[1])){
            for(i=1, j=2; s[i] !='\0';i++, j++){
                if(s[i] =='.'){
                    if(s[i+1] =='\0') return FAILURE;
                        for(k=j, m=j+1; s[k] !='\0'; m++, k++){
                        if(!isdigit(s[k])) return FAILURE;
                        else if(isdigit(s[k])) continue;
                        else if(s[m] ='\0' && isdigit(s[k])) return SUCCESS;
                        }
                }
                else if(!isdigit(s[i])) return FAILURE;
                else if(isdigit(s[i]) && s[j] =='\0') return SUCCESS;
            }
        }
        else return FAILURE;
    }
    else return FAILURE;
}
return FAILURE;
}

char * getLine(int *count){
    int memory = 10, c, counter = *count;
    char * buff = (char *)malloc(memory);
    while((c=getchar()) != '\n' && c != EOF){
        if(memory <= counter) {
            memory += 10;
            buff = (char *) realloc(buff, memory);
        }
        *(buff+counter) = (char)c;
        counter++;
    }
    *(buff+(counter)) = '\0';
    *count = counter;
    return buff;

}
