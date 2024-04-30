#include "mode_manager.h"

#include <stdlib.h>

void simple_calculator_constructor(simple_calculator_handle_t* sc_handler, char* allocated_mode_name, void(*launch)()) {
    sc_handler->mode_name = allocated_mode_name;
    sc_handler->launch = launch;
}

void simple_calculator_destructor(simple_calculator_handle_t* sc_handler) {
    free(sc_handler->mode_name);
}
