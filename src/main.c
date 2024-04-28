#include <stdio.h>
#include <stdbool.h>

const int default_number[] = { 1, 2 };
const char welcome_message[] = "Welcome to Simple Calculator";

/*
    This function is used to get operand or operator from user.
        +) is_operator = false: get operand
        +) is_operator = true: get operator. Required type-cast to char
*/
int get_input(const char input_message[], const char error_message[], bool is_operator);
void show_result(int first_operand, int second_operand, char operator);

int main() {
    printf("%s\n", welcome_message);

    int first_operand = default_number[0];
    int second_operand = default_number[1];
    char operator;
    int scanned_count;

    printf("-----------------------------\n");
    first_operand = get_input("Enter first operand", "[Error] Input should be a number!", false);
    operator = get_input("Enter operator [+|-|*|/]", "[Error] Input should be [+|-|*|/]!", true);
    second_operand = get_input("Enter second operand", "[Error] Input should be a number!", false);

    printf("-----------------------------");
    show_result(first_operand, second_operand, operator);
}

int get_input(const char input_message[], const char error_message[], bool is_operator) {
    int input;

    do {
        printf("%s: ", input_message);

        if (is_operator) {
            scanf(" %c", &input);
            while (getchar() != '\n');
            if ((char) input == '+' || (char) input == '-' || (char) input == '*' || (char) input == '/') return input;
        }
        else {
            int scanned_count = scanf("%d", &input);
            while (getchar() != '\n');
            if (scanned_count != 0) return input;
        }
        printf("%s\n", error_message);
    } while (1);
}

void show_result(int first_operand, int second_operand, char operator) {
    if (operator == '+') {
        long long sum = first_operand + second_operand;
        printf("\n%-10s: %d + %d = %lld", "Sum", first_operand, second_operand, sum);
    }
    else if (operator == '-') {
        int difference = first_operand - second_operand;
        printf("\n%-10s: %d - %d = %d", "Difference", first_operand, second_operand, difference);
    }
    else if (operator == '*') {
        long long product = first_operand * second_operand;
        printf("\n%-10s: %d * %d = %lld", "Product", first_operand, second_operand, product);
    }
    else if (operator == '/') {
        if (second_operand == 0) {
            printf("\nDivision by 0 is not allowed!");
        }
        else {
            double quotient = ((double)first_operand) / second_operand;
            printf("\n%-10s: %d / %d = %.15g", "Quotient", first_operand, second_operand, quotient);
        }
    }
}