// #include "ui.h"

#include <stdio.h>
#include <stdbool.h>

bool get_operator(const char* stream, void* p_operator) {
    char* p_char_operator = (char*) p_operator;
    sscanf(stream, " %c", p_char_operator);

    char operator = *p_char_operator;
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
        return true;
    
    return false;
}

bool get_operand(const char* stream, void* p_operand) {
    int* p_int_operand = (int*) p_operand;
    int scanned_count = sscanf(stream, "%d", p_int_operand);

    if (scanned_count != 0 && scanned_count != EOF)
        return true;
    
    return false;
}

unsigned int ui_get_input(const char input_message[], const char error_message[], bool (*get_input)(const char*, void*)) {
    char buffer[100];
    int input;

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

int main() {
    unsigned int input = ui_get_input("Input", "Error", get_operand);
    printf("\nReceived int: %d\nReceive char: %c", (int) input, *((char*) &input));
}