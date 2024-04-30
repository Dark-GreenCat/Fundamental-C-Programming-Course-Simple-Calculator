#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

bool get_operator(const char* stream, void* p_operator);
bool get_operand(const char* stream, void* p_operand);

#endif