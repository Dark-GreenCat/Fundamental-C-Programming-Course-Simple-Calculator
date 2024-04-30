#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

#include "main.h"

const char welcome_message[] = "Welcome to Simple Calculator";

void (*launch_calculator[])(void) = {
    launch_exit,
    launch_basic_calculation,
    launch_base_10_to_2_converter,
    launch_gcd
};
int number_of_mode = sizeof(launch_calculator) / sizeof(*launch_calculator);

const char mode_name[][30] = {
    "Basic calculation",
    "Base 10 to 2 converter",
    "Greatest common divisor",
    "Exit"
};

sc_handle_t* sc_handler = NULL;

int main() {
    app_main();
}

void app_main() {
    ui_printf("%s", welcome_message);
    ui_printf("\n-----------------------------");

    unsigned short mode = 0;
    while (true) {
        system("cls");
        ui_printf("\nSimple Calculator Mode");
        ui_printf("\n\t1. Basic calculation");
        ui_printf("\n\t2. Base 10 to 2 converter");
        ui_printf("\n\t3. Greatest common divisor");
        ui_printf("\n\t0. Exit");
        
        mode = (unsigned short) ui_get_input("\nSelect mode [0-3]", "[ERROR] Invalid mode!", get_mode);
        ui_printf("Mode selected: %hu\n", mode);
        ui_printf("-----------------------------\n");

        launch_calculator[mode]();

        ui_printf("\n-----------------------------");
        ui_printf("\nPress any to continue...");
        getch();
    }
}

int get_number_of_mode() {
    return number_of_mode;
}

void app_init() {
    int number_of_mode = get_number_of_mode();
    sc_handle_t* _sc_handler = (sc_handle_t*) malloc((unsigned int) number_of_mode * sizeof(sc_handle_t));

    for (int i = 0; i < number_of_mode; i++) {
        simple_calculator_constructor(_sc_handler + i, (char *) mode_name[i], launch_calculator[i]);
    }

    sc_handler = _sc_handler;
}

void app_exit() {
    simple_calculator_destructor(sc_handler);
    free(sc_handler);

    ui_printf("Hope to see you again!");
    ui_printf("\n[Simple Calculator exitted]");
    exit(0);
}
