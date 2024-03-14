#include <stdio.h>
#include <stdlib.h>

#define COMMAND_EXIT 0
#define COMMAND_MANUAL 1
#define AMOUNT_OF_COMMANDS 2

/*
 * Account saving:
 * ..\accounts\user_pass.txt -> includes password
 * ..\accounts\user_tickets.txt -> includes tickets
 */ 

// Prototypes.

char* login(int *lenght); //Should be 1 of the commands.
int ask_for_command(); // Should this have a variable?

int main(void){
	
	int command;
	int lenght = 0;
	char *username = NULL;
	
	while(1){ // Command zone.
		output_command_list();
		command = ask_for_command();
		switch(command){
		case COMMAND_EXIT:
			// If needed, save here.
			return 0;
			break;
		case COMMAND_MANUAL:
			// Needs to be added.
			break;
		default:
			printf("ERROR\n");
		}
	}
}

// Returns a pointer to a user name and sets lenght to the lenght of the username.
// makes username "NULL" on fail.
char* login(*lenght){
	
	return;
}

int ask_for_command(){
	int command = 0;
	while(1){
		if(scanf("%d", &command) == 1){
			if(command > -1 && command < AMOUNT_OF_COMMANDS){
				return command;
			}
		}
		while(getchar); // Cleans buffer when a error appears.
	}
}

void output_command_list(){
	printf("\
	All available commands:\n\
	0. Exit.\n\
	1. Show manual\n\
	Write command here and press enter: ");
}
