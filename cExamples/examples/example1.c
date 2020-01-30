



void conteoCaracteres(void){
	int nc, c, lj, ws, bs, cr, tb, num, charact, isIn;
	nc=c=lj= ws=bs=cr=tb=num=charact=0;
	printf("Conteo de caracteres: ");
	while((c =getchar()) != EOF) {
		nc++;
		if(isdigit(c)) {
			num++;
			isIn =1;
		}
		else {
		charact++;
		isIn=1;
		if(c == '\n') {
					lj++;
					isIn =0;
				}
				else if(c == ' ') {
					ws++;
					isIn =0;
				}
				else if(c == '\b') {
					isIn =0;
					bs++;
				}
				else if(c == '\r') {
					isIn =0;
					cr++;
				}
				else if(c == '\t') {
					tb++;
					isIn =0;
				}
		}
		if(isIn==1){
			puts("Es una palabra o letra\n");
		}else
			puts("No es una palabra o letra\n");

		printf("\nCaracter leido : %c Conteo %d\nNumero :%d\nCaracter: %d\nSalto de linea: %d\nEspacio en blanco : "
				"%d\nEspacio atras: %d\nRetroceso : %d", c, nc, num, charact, lj, ws, bs, cr);
		printf("\nTabulador : %d", tb);
		fpurge(stdin);
	}
}

