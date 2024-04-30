#include "ui.h"

#include <stdio.h>
#include <stdbool.h>

unsigned int ui_get_input(const char input_message[], const char error_message[], bool (*get_input)(const char*, void*)) {
    char buffer[100];
    unsigned int input;

    do {
        printf("%s: ", input_message);

        scanf("%101[^\n]", buffer);
        while (getchar() != '\n');

        if (get_input(buffer, (void*) &input))
            break;

        printf("%s\n", error_message);
    } while (1);

    return input;
}