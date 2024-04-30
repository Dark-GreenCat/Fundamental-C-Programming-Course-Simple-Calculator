#include "app.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include "text.h"

sc_handle_t default_sc_handler[] = {
    { "Exit", app_exit },
    { "Basic calculation", launch_basic_calculation },
    { "Base 10 to 2 converter", launch_base_10_to_2_converter },
    { "Greatest common divisor", launch_gcd }
};

const char text_filepath[] = "data/text.csv";

int number_of_mode = sizeof(default_sc_handler) / sizeof(*default_sc_handler);

sc_handle_t* sc_handler = NULL;

void app_main() {
    text_app_t* p_sc_text_app = &(get_sc_text()->text_app);

    ui_printf("%s", p_sc_text_app->welcome_msg);
    ui_printf("\n-----------------------------");

    unsigned short mode = 0;
    while (true) {
        ui_printf("\n%s", p_sc_text_app->mode_list_msg);
        for (int i = 0; i < number_of_mode; i++) {
            ui_printf("\n\t%hu. %s", i, sc_handler[i].mode_name);
        }
        
        char input_message[30];
        sprintf(input_message, "\n%s [0-%d]", p_sc_text_app->mode_input_select_msg, number_of_mode - 1);
        mode = (unsigned short) ui_get_input(input_message, p_sc_text_app->mode_input_invalid_msg, get_mode);
        ui_printf("%s: %hu\n", p_sc_text_app->mode_selected_msg, mode);
        ui_printf("-----------------------------\n");

        sc_handler[mode].launch();

        ui_printf("\n-----------------------------");
        ui_printf("\n%s", p_sc_text_app->continue_msg);
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

    text_t* p_sc_text = get_sc_text();
    FILE* p_text_file = database_connect(text_filepath, "r");
    database_load_text_app(p_text_file, &(p_sc_text->text_app));
    database_disconnect(p_text_file);
}

void app_exit() {
    text_app_t* p_sc_text_app = &(get_sc_text()->text_app);

    for (int i = 0; i < number_of_mode; i++) {
        simple_calculator_destructor(sc_handler + i);
    }
    free(sc_handler);


    ui_printf("%s", p_sc_text_app->goodbye_msg);
    ui_printf("\n%s", p_sc_text_app->exit_msg);

    database_free_text_app(p_sc_text_app);
    exit(0);
}