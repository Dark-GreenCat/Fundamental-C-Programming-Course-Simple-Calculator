#include "app.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

const char welcome_message[] = "Welcome to Simple Calculator";

sc_handle_t default_sc_handler[] = {
    { "Exit", app_exit },
    { "Basic calculation", launch_basic_calculation },
    { "Base 10 to 2 converter", launch_base_10_to_2_converter },
    { "Greatest common divisor", launch_gcd }
};

int number_of_mode = sizeof(default_sc_handler) / sizeof(*default_sc_handler);

sc_handle_t* sc_handler = NULL;

void app_main() {
    ui_printf("%s", welcome_message);
    ui_printf("\n-----------------------------");

    unsigned short mode = 0;
    while (true) {
        ui_printf("\nSimple Calculator Mode");
        for (int i = 0; i < number_of_mode; i++) {
            ui_printf("\n\t%hu. %s", i, sc_handler[i].mode_name);
        }
        
        char input_message[30];
        sprintf(input_message, "\nSelect mode [0-%d]", number_of_mode - 1);
        mode = (unsigned short) ui_get_input(input_message, "[ERROR] Invalid mode!", get_mode);
        ui_printf("Mode selected: %hu\n", mode);
        ui_printf("-----------------------------\n");

        sc_handler[mode].launch();

        ui_printf("\n-----------------------------");
        ui_printf("\nPress any to continue...");
        getch();
        
        system("cls");
    }
}

int get_number_of_mode() {
    return number_of_mode;
}

void app_init() {
    int number_of_mode = get_number_of_mode();
    sc_handle_t* _sc_handler = (sc_handle_t*) malloc((unsigned int) number_of_mode * sizeof(sc_handle_t));

    for (int i = 0; i < number_of_mode; i++) {
        simple_calculator_constructor(_sc_handler + i, default_sc_handler[i].mode_name, default_sc_handler[i].launch);
    }

    sc_handler = _sc_handler;
}

void app_exit() {
    for (int i = 0; i < number_of_mode; i++) {
        simple_calculator_destructor(sc_handler + i);
    }
    free(sc_handler);

    ui_printf("Hope to see you again!");
    ui_printf("\n[Simple Calculator exitted]");
    exit(0);
}