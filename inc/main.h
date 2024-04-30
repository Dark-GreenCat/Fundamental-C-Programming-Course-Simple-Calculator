#ifndef MAIN_H
#define MAIN_H

#include "ui.h"

#include "input.h"
#include "basic_calculation.h"
#include "base_converter.h"
#include "gcd.h"

extern int number_of_mode;

void app_main();
bool get_mode(const char* stream, void* p_mode);

static inline int get_number_of_mode() {
    return number_of_mode;
}

#endif