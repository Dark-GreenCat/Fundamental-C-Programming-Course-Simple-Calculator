#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ui.h"

#include "input.h"
#include "basic_calculation.h"
#include "base_converter.h"
#include "gcd.h"

const char welcome_message[] = "Welcome to Simple Calculator";

void (*launch_calculator[])(void) = {
    launch_basic_calculation,
    launch_base_10_to_2_converter,
    launch_gcd
};
int number_of_mode = sizeof(launch_calculator) / sizeof(*launch_calculator);

int main() {
    ui_printf("%s", welcome_message);
    ui_printf("\n-----------------------------");

    unsigned short mode = 0;
    ui_printf("\nSimple Calculator Mode");
    ui_printf("\n\t1. Basic calculation");
    ui_printf("\n\t2. Base 10 to 2 converter");
    ui_printf("\n\t3. Greatest common divisor");
    ui_printf("\nSelect mode [1-3]: ");
    scanf("%hu", &mode);
    while(getchar() != '\n');
    ui_printf("-----------------------------\n");

    if (mode >= 1 && mode <= number_of_mode) {
        launch_calculator[mode - 1]();
    }
    else {
        ui_printf("\nInvalid mode!");
    }
}
