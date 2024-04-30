#include "basic_calculation.h"

#include <stdio.h>
#include <stdbool.h>
#include "input.h"
#include "ui.h"

double calculate(double first_operand, double second_operand, char operator) {
    switch (operator) {
        case '+': return (first_operand + second_operand);
        case '-': return (first_operand - second_operand);
        case '*': return (first_operand * second_operand);
        case '/': return (first_operand / second_operand);
    }

    return 0;
}

void show_result(int first_operand, int second_operand, double result, char operator) {
    if (operator == '/' && second_operand == 0) {
        ui_printf("\nDivision by 0 is not allowed!");
        return;
    }

    ui_printf("\n%-10s: %d %c %d = %.15g", "Sum", first_operand, operator, second_operand, result);
}

void launch_basic_calculation() {
    double result;
    int first_operand;
    int second_operand;
    char operator;

    first_operand = (int) ui_get_input("\nEnter first operand", "[Error] Input should be a number!", get_operand);
    while (true) {
        operator = (char) ui_get_input("Enter operator [+|-|*|/]", "[Error] Input should be [+|-|*|/]!", get_operator);
        second_operand = (int) ui_get_input("Enter operand", "[Error] Input should be a number!", get_operand);
        ui_printf("-----------------------------");
        result = calculate(first_operand, second_operand, operator);
        show_result(first_operand, second_operand, result, operator);
        ui_printf("\n-----------------------------");

        first_operand = (int) result;
        ui_printf("\nCurrent value: %d\n", first_operand);
    }   
}