#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

typedef struct {
    char* mode_name;
    void (*launch)();
} simple_calculator_handle_t;

/*
    Constructor() will dynamic allocate for member.
    When program exits, destructor() MUST be called.
*/
void simple_calculator_constructor(simple_calculator_handle_t* sc_handler, const char* mode_name, void (*launch)());
void simple_calculator_destructor(simple_calculator_handle_t* sc_handler);

#endif