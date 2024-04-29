#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

/*
    This function is used to get operand or operator from user.
        +) is_operator = false: get operand
        +) is_operator = true: get operator. Required type-cast to char
*/
int get_input(const char input_message[], const char error_message[], bool is_operator);

#endif