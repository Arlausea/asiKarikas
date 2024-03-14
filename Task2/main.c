#include <stdio.h>
#include <stdlib.h>

/*
 * Account saving:
 * ..\accounts\user_pass.txt -> includes password
 * ..\accounts\user_tickets.txt -> includes tickets
 */ 

// Prototypes.

char* login(int *lenght); //Should be 1 of the commands.
int ask_for_command(); // Don't know what to use as a variable.

int main(void){
	
	int command;
	int lenght = 0;
	// username array / pointer here.
	
	while(1){ // Command zone.
		command = ask_for_command();
		switch(command){
		case 0: //exit command.
			// If needed, save here.
			return 0;
			break;
		case 1: // output manual
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
	
	return;
}
