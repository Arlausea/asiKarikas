#include <stdio.h>
#include <stdlib.h>

/*
 * Account saving:
 * ..\accounts\user_pass.txt -> includes password
 * ..\accounts\user_tickets.txt -> includes tickets
 */ 

// Prototypes.

char* login(int *lenght);
int login(); // Don't know what to use as a variable.

int main(void){
	
	int command;
	int lenght = 0;
	// username array / pointer here.
	
	while(1){ // Command zone.
		do{
			login(lenght);
		}while(); //While username != "NULL"
		
		command = ask_for_command();
		switch(command){
		case 0: //exit command.
			return 0;
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

int login(){
	
	return;
}
