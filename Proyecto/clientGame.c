#include "clientGame.h"

unsigned int readMove (){

	int i, isValid, column;
	tString enteredMove;

		// Init...
		column = 0;

		// While player does not enter a correct move...
		do{

			// Init...
			bzero (enteredMove, STRING_LENGTH);
			isValid = TRUE;

			// Show input message
			printf ("Enter a move [0-%d]:", BOARD_WIDTH-1);

			// Read move
			fgets(enteredMove, STRING_LENGTH-1, stdin);

			// Remove new-line char
			enteredMove[strlen(enteredMove)-1] = 0;

			// Check if each character is a digit
			for (i=0; i<strlen(enteredMove) && isValid; i++){

				if (!isdigit(enteredMove[i]))
					isValid = FALSE;
			}

			// Entered move is not a number
			if (!isValid){
				printf ("Entered move is not correct. It must be a number between [0-%d]\n", BOARD_WIDTH-1);
			}

			// Entered move is a number...
			else{

				// Conver entered text to an int
				column = atoi (enteredMove);
			}

		}while (!isValid);

	return ((unsigned int) column);
}

int main(int argc, char *argv[]){

	// Check arguments!
	if (argc != 3){
		fprintf(stderr,"ERROR wrong number of arguments\n");
		fprintf(stderr,"Usage:\n$>%s serverIP port\n", argv[0]);
		exit(0);
	}
}
