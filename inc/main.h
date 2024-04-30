#ifndef MAIN_H
#define MAIN_H

#include "ui.h"
#include "mode_manager.h"

#include "input.h"
#include "exit.h"
#include "basic_calculation.h"
#include "base_converter.h"
#include "gcd.h"

typedef simple_calculator_handle_t sc_handle_t;

void app_main();
int get_number_of_mode();
void app_init();
void app_exit();

#endif