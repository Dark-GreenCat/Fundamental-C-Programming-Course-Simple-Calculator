#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../inc/input.h"
#include "../inc/basic_calculation.h"
#include "../inc/base_converter.h"
#include "../inc/gcd.h"

const char welcome_message[] = "Welcome to Simple Calculator";

void (*launch_calculator[])(void) = {
    launch_basic_calculation,
    launch_base_10_to_2_converter,
    launch_gcd
};
int number_of_mode = sizeof(launch_calculator) / sizeof(*launch_calculator);

int main() {
    printf("%s", welcome_message);
    printf("\n-----------------------------");

    unsigned short mode = 0;
    printf("\nSimple Calculator Mode");
    printf("\n\t1. Basic calculation");
    printf("\n\t2. Base 10 to 2 converter");
    printf("\n\t3. Greatest common divisor");
    printf("\nSelect mode [1-3]: ");
    scanf("%hu", &mode);
    while(getchar() != '\n');
    printf("-----------------------------\n");

    if (mode >= 1 && mode <= number_of_mode) {
        launch_calculator[mode - 1]();
    }
    else {
        printf("\nInvalid mode!");
    }
}
