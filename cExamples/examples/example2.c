
int getLine(char s[], int len);
void copy(char to[], char from[]);
int getLine(char s[], int len){
	int c, i;
	for(i =0; i< len -1 && (c =getchar())!= EOF && c != '\n'; i++){
		s[i] = c;
		if(c == '\n') {
			s[i] = c;
			i++;
		}
	}
		s[i] = '\0';
		return i;
}
void copy(char to[], char from[]){
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
i++;
}
#define MAXLINE 1000
void conteoMayorLinea(void){
	int len, max=0;
	char originalString[MAXLINE];
	char largeSubString[MAXLINE];
	while((len = getLine(originalString, MAXLINE)) > 0){
		if(len > max) {
			max = len;
			copy(originalString, largeSubString);
		}
		if (max >0) /* hubo una línea */{
			printf("%s", largeSubString);
		}

	}
}

