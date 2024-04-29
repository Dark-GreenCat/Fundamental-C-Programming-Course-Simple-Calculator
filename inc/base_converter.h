#ifndef BASE_CONVERTER_H
#define BASE_CONVERTER_H

#include <stdbool.h>

/*
    This function is used to create UI to convert user's inputted number to 32bit binary.
    This function supports 32-bit positive integer only.
*/
void base_10_to_2_convert(unsigned int number, bool* binary_array); 
void launch_base_10_to_2_converter();

#endif