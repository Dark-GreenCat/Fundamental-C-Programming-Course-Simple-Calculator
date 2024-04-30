#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <stdbool.h>

#define ui_printf(...) printf(__VA_ARGS__)

/*
    This function is to get input from user then check validation by get_input() function pointer.
    The "unsigned int" return value allows to type-cast to any number data type that are smaller or equal in size
*/
unsigned int ui_get_input(const char input_message[], const char error_message[], bool (*get_input)(const char*, void*));

#endif