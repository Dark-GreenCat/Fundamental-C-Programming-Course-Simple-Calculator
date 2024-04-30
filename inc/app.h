#ifndef APP_H
#define APP_H

#include "main.h"
#include "mode_manager.h"

typedef simple_calculator_handle_t sc_handle_t;

void app_main();
int get_number_of_mode();
void app_init();
void app_exit();

#endif