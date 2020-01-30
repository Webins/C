#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/poll.h>
#include <stdbool.h>

//Declarations of functions
char printRand();
void searchWord(char c);

// Function that print a random character from the alphabet
char printRand(char str[26]){
	int randN = rand() % 27;
	char selectedChar;
	for (int i = 0; i < strlen(str); i++){
		if (i == randN){
			selectedChar = str[i];
			printf("\n\t\"%c\" is the char for look hurry up!\n\n", str[i]);
			printf("\nEnter a word starting with %c: ", str[i]);
		}
	}
	return selectedChar;
}

void searchWord(char c){
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct pollfd fds[1];
	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char decision[25];

	// Initialize for generate the random number
	time_t t;
	srand((unsigned)time(&t));

	printf("\t\tS p R e A d W o R d S g A m E!\n\n");
	//sleep(2);
	printf("The game consist in show to you a random letter from the alphabet and you have to answer a complete word"
		   "that begins with that letter.\nif you already guess the word it will be erase from the list of possible "
		   "words\nGood luck!\n");
	//sleep(5);
	printf("The game starts in...\n");
	for (int i = 1; i < 4; i++){
		printf("%d\n", i);
		//sleep(2);
	}
	searchWord(printRand(alphabet));
	printf("\n");
	bool dataAvailable = false;
	for (int i = 10; i >= 0 && !dataAvailable; i--){
		switch (poll(fds, 1, 1000)){
		case -1:
			perror("poll failed");
			exit(1);
		case 0:
			printf("%d seconds left\n", i);
			break;
		default:
			dataAvailable = true;
		}
	}
	if (dataAvailable){
		gets(decision);
	}
	else{
		fprintf(stderr, "Time over\n");
		exit(1);
	}

	//		for(int i=10;i>=0;i--){
	//			if(i==0)printf("time over\n");
	//			else printf("%d seconds left\n",i);
	//			scanf("%s", decision);
	//			sleep(1);
	//		}

	return 0;
}
