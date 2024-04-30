#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"

const char welcome_message[] = "Welcome to Simple Calculator";

void (*launch_calculator[])(void) = {
    launch_basic_calculation,
    launch_base_10_to_2_converter,
    launch_gcd
};
int number_of_mode = sizeof(launch_calculator) / sizeof(*launch_calculator);

int main() {
    app_main();
}

void app_main() {
    ui_printf("%s", welcome_message);
    ui_printf("\n-----------------------------");

    unsigned short mode = 0;
    ui_printf("\nSimple Calculator Mode");
    ui_printf("\n\t1. Basic calculation");
    ui_printf("\n\t2. Base 10 to 2 converter");
    ui_printf("\n\t3. Greatest common divisor");
    
    mode = (unsigned short) ui_get_input("\nSelect mode [1-3]", "[ERROR] Invalid mode!", get_mode);
    ui_printf("Mode selected: %hu\n", mode + 1);
    ui_printf("-----------------------------\n");

    launch_calculator[mode]();
}

int get_number_of_mode() {
    return number_of_mode;
}