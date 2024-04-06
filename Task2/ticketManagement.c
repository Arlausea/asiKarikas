#include "main.h"




int main(){
        int command;
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
                return -1;
		}
    }
}
