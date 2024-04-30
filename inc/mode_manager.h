#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

typedef struct {
    char* mode_name;
    void (*launch)();
} simple_calculator_handle_t;

/*
    String "allocated_mode_name" should be dynamic allocated before pass to constructor().
    When program exits, destructor() MUST be called.
*/
void simple_calculator_constructor(simple_calculator_handle_t* sc_handler, char* allocated_mode_name, void (*launch)());
void simple_calculator_destructor(simple_calculator_handle_t* sc_handler);

#endif