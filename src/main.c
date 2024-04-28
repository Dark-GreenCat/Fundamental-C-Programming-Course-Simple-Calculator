#include <stdio.h>

const int default_number[] = { 1, 2 };
const char welcome_message[] = "Welcome to Simple Calculator";

int get_operand(const char input_message[], const char error_message[]);
char get_operator();
void show_result(int first_operand, int second_operand, char operator);

int main() {
    printf("%s\n", welcome_message);

    int first_operand = default_number[0];
    int second_operand = default_number[1];
    char operator;
    int scanned_count;

    printf("-----------------------------\n");
    first_operand = get_operand("Enter first operand", "[Error] Input should be a number!");
    operator = get_operator();
    second_operand = get_operand("Enter second operand", "[Error] Input should be a number!");

    printf("-----------------------------");
    show_result(first_operand, second_operand, operator);
}

int get_operand(const char input_message[], const char error_message[]) {
    int operand;
    int scanned_count;

    do {
        printf("%s: ", input_message);
        scanned_count = scanf("%d", &operand);
        while (getchar() != '\n');

        if (scanned_count != 0) break;
        printf("%s\n", error_message);
    } while (1);

    return operand;    
}

char get_operator() {
    char operator;
    int scanned_count;

    do {
        printf("Enter operator [+|-|*|/]: ");
        scanned_count = scanf(" %c", &operator);
        while (getchar() != '\n');

        if (operator == '+' || operator == '-' || operator == '*' || operator == '/') break;
        printf("[Error] Input should be [+|-|*|/]!\n");
    } while (1);

    return operator;
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