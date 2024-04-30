#include "input.h"

#include <stdio.h>

bool get_operator(const char* stream, void* p_operator) {
    char* p_char_operator = (char*) p_operator;
    sscanf(stream, " %c", p_char_operator);

    char operator = *p_char_operator;
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == 'x')
        return true;
    
    return false;
}

bool get_operand(const char* stream, void* p_operand) {
    int* p_int_operand = (int*) p_operand;
    int scanned_count = sscanf(stream, "%d", p_int_operand);

    if (scanned_count != 0 && scanned_count != EOF)
        return true;
    
    return false;
}

bool get_mode(const char* stream, void* p_mode) {
    unsigned short* p_ushort_mode = (unsigned short*) p_mode;
    sscanf(stream, "%hu", p_ushort_mode);

    unsigned short mode = *p_ushort_mode;
    if (mode < get_number_of_mode())
        return true;
    
    return false;
}