#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

typedef struct {
    char* mode_name;
    void (*launch)();
} simple_calculator_handle_t;

#endif