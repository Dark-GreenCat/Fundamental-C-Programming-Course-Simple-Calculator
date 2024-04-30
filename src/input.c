#include "input.h"

#include <stdio.h>

int get_input(const char input_message[], const char error_message[], bool is_operator) {
    int input;

    do {
        printf("%s: ", input_message);

        if (is_operator) {
            char operator;
            scanf(" %c", &operator);
            while (getchar() != '\n');
            if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
                input = operator;
                break;
            }
        }
        else {
            int scanned_count = scanf("%d", &input);
            while (getchar() != '\n');
            if (scanned_count != 0) break;
        }

        printf("%s\n", error_message);
    } while (1);

    return input;
}