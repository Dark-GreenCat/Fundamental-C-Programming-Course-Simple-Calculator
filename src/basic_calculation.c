#include "basic_calculation.h"

#include <stdio.h>
#include <stdbool.h>
#include "input.h"

long long show_result(int first_operand, int second_operand, char operator) {
    long long result;

    if (operator == '+') {
        long long sum = (long long) first_operand + second_operand;
        printf("\n%-10s: %d + %d = %lld", "Sum", first_operand, second_operand, sum);
        result = sum;
    }
    else if (operator == '-') {
        int difference = first_operand - second_operand;
        printf("\n%-10s: %d - %d = %d", "Difference", first_operand, second_operand, difference);
        result = difference;
    }
    else if (operator == '*') {
        long long product = (long long) first_operand * second_operand;
        printf("\n%-10s: %d * %d = %lld", "Product", first_operand, second_operand, product);
        result = product;
    }
    else if (operator == '/') {
        if (second_operand == 0) {
            printf("\nDivision by 0 is not allowed!");
        }
        else {
            double quotient = ((double)first_operand) / second_operand;
            printf("\n%-10s: %d / %d = %.15g", "Quotient", first_operand, second_operand, quotient);
            result = (long long) quotient;
        }
    }

    return result;
}

void launch_basic_calculation() {
    int first_operand;
    int second_operand;
    char operator;

    first_operand = get_input("\nEnter first operand", "[Error] Input should be a number!", false);
    while (true) {
        operator = (char) get_input("Enter operator [+|-|*|/]", "[Error] Input should be [+|-|*|/]!", true);
        second_operand = get_input("Enter operand", "[Error] Input should be a number!", false);
        printf("-----------------------------");
        first_operand = (int) show_result(first_operand, second_operand, operator);
        printf("\n-----------------------------");
        printf("\nCurrent value: %d\n", first_operand);
    }   
}