/*
 * TIC TAC TOE GAME
 * 14/09/19
 * C BASIC COURSE FROM UDEMY
 * MADE BY WEBINS
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TURNS 9 // TOTAL NUMBERS OF TURNS
#define DEFAULT_VALUE 10 // DEFAULT VALUE FOR THE INDEX
#define LENGHT 8 // THE LENGHT OF THE ARRAY

// DECLARATION OF FUNCTIONS
void makeGrid(char arr[LENGHT],char c ,int index);
int decision(int n, char c);
int selectPlayer(int n);
char charOfPlayer(int player);
void fill(char arr[LENGHT]);
void checkForWin(char arr[LENGHT], int player);



//DEFAULT VALUE FOR INDEX, IT'S NECESSARY TO KNOW WHERE SET THE CHAR 'X' OR 'O'
void defaultValue(char arr[LENGHT], char c, int index){
	index=DEFAULT_VALUE;
	return makeGrid(arr, c, index);
}

//DECLARATION OF THE ARRAY OF NUMBERS THAT IS GOING TO BE USED IN THE GRID
char grid[8];


//FILL THE GRID
void fill(char arr[LENGHT]){
for(int i =0; i<=LENGHT; i++){
	arr[i] =i+1+'0';
	}
}

//CHECK WHETHER THE PLAYER WIN OR NOT
void checkForWin(char arr[LENGHT], int player){
	short int i, j, k, m, n;
		j=0;k=0;
		m=0;n=0;
	for(i =0; i<= 3;i++){
		// HORIZONTAL
		if(((arr[j]=='X') && (arr[j+1]=='X') && (arr[j+2]=='X')) ||
			((arr[j]=='O') && (arr[j+1]=='O') && (arr[j+2]=='O'))){
			printf("\nplayer %d has won", player);
			pause();
		}
		//VERTICAL
		else if(((arr[k]=='X') && (arr[k+3]=='X') && (arr[k+6]=='X')) ||
			((arr[k]=='O') && (arr[k+3]=='O') && (arr[k+6]=='O'))){
			printf("\nplayer %d has won", player);
			pause();
		}
		j+=3;
		k+=1;
	}
		// LEFT DIAGONAL
		if(((arr[m]=='X') && (arr[m+4]=='X') && (arr[m+8]=='X')) ||
			((arr[m]=='O') && (arr[m+4]=='O') && (arr[m+8]=='O'))){
			printf("\nplayer %d has won", player);
			pause();
		}
		//RIGHT DIAGONAL
		else if(((arr[n+2]=='X') && (arr[n+4]=='X') && (arr[n+6]=='X')) ||
			((arr[n+2]=='O') && (arr[n+4]=='O') && (arr[n+6]=='O'))){
			printf("\nplayer %d has won", player);
			pause();
		}
}




// IT RETURN THE CORRECT CHAR FOR THE CORRECT PLAYER, PLAYER 1 IS X PLAYER 2 IS O
char charOfPlayer(int player){
	char x = 'X';
	char o = 'O';
	if(player==1) return x;
	else return o;
}

// SELECT IF THE PLAYER IS 1 OR 2
int selectPlayer(int count){
int result;
if(count % 2 ==0) result = 2;
else result = 1;
return result;
}




// MAKE THE GRID FOR THE TIC TAC TOE GAME
void makeGrid(char arr[LENGHT], char c, int index){
			for(int i =0; i <=LENGHT; i++){
			if(index == i) arr[index] = c;

			printf(" %c ", arr[i]);
			if(i==0 || i== 1 || i==3 ||i==4 ||i==6 ||i==7) printf("|");
			if(i==2 || i== 5 || i==8) printf("\n___|___|___\n");
		}
}

// IT GOING TO CHANGE THE NUMBER THE PLAYER CHOOSE FOR AN CHARACTER
int decision(int n, char c){
int index = n-1;
if(grid[index] == 'X' || grid[index] =='O' ){
			printf("The selected box is occupied, try again.\n");
			makeGrid(grid, 'c', DEFAULT_VALUE);
			return 1;
		}else

printf("\n\n");
makeGrid(grid,c,index);
return 0;
}


int main(){
	//VARIABLES
	int n, count=1, player;
	int i=0, resultDecision;
	char charSelect;

	printf("Tic Tac Toe Game\n");
	printf("Player 1 is X, Player 2 is O\n");
	fill(grid);
	makeGrid(grid, 'c', DEFAULT_VALUE);

	while(i < TURNS){
	player = selectPlayer(count);
	charSelect = charOfPlayer(player);

	askAgain:
	printf("player %d enter a number: ", player);
	scanf("%d", &n);
	printf("\n");
	if(n >9 || n <1) {
		printf("Enter a valid number between one and nine [1-9]\n\n");
		makeGrid(grid, 'c', DEFAULT_VALUE);
		goto askAgain;

	}
	resultDecision=decision(n, charSelect);

	// check if the decision function throw an error when the user put a number that was occupied and ask again
	if(resultDecision == 1) goto askAgain;

	checkForWin(grid, player);
	if(i == 8) printf("\nDRAW!");
	count++;
	i++;
	}
	return 0;
}
