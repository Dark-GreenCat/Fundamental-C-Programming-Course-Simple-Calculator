#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

#include "main.h"

const char welcome_message[] = "Welcome to Simple Calculator";

void (*launch_calculator[])(void) = {
    app_exit,
    launch_basic_calculation,
    launch_base_10_to_2_converter,
    launch_gcd
};
int number_of_mode = sizeof(launch_calculator) / sizeof(*launch_calculator);

const char mode_name[][30] = {
    "Exit",
    "Basic calculation",
    "Base 10 to 2 converter",
    "Greatest common divisor"
};

sc_handle_t* sc_handler = NULL;

int main() {
    app_init();
    app_main();
    app_exit();
}

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
