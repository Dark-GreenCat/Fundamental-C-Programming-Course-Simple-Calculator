#include "mode_manager.h"

#include <stdlib.h>
#include <string.h>

void simple_calculator_constructor(simple_calculator_handle_t* sc_handler, const char* mode_name, void(*launch)()) {
    char* name = (char *) malloc(strlen(mode_name) * sizeof(char));
    strcpy(name, mode_name);
    
    sc_handler->mode_name = name;
    sc_handler->launch = launch;
}

void simple_calculator_destructor(simple_calculator_handle_t* sc_handler) {
    free(sc_handler->mode_name);
}
