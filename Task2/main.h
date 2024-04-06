#include "general.h"


#define COMMAND_EXIT 0
#define COMMAND_MANUAL 1
#define AMOUNT_OF_COMMANDS 2

// Prototypes.

char* login(int *lenght); //Should be 1 of the commands.
int ask_for_command(); // Should this have a variable?
void output_command_list();