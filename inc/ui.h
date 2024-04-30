#ifndef UI_H
#define UI_H

#include <stdbool.h>

/*
    This function is to get input from user then check validation by get_input() function pointer.
    The "unsigned int" return value allows to type-cast to any number data type that are smaller or equal in size
*/
unsigned int ui_get_input(const char input_message[], const char error_message[], bool (*get_input)(const char*, void*));

bool get_operator(const char* stream, void* p_operator);
bool get_operand(const char* stream, void* p_operand);

#endif