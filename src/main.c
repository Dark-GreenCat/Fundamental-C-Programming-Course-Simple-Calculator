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
/*
    This function is used to calculate the result and print to console.
    The result is returned as long long type (which means double number will lose the fractional part).
*/
long long show_result(int first_operand, int second_operand, char operator);
void launch_basic_calculation();

int main() {
    printf("%s", welcome_message);
    printf("\n-----------------------------");

    char mode = 0;
    printf("\nSimple Calculator Mode");
    printf("\n\t1. Basic calculation");
    printf("\nSelect mode [1]: ");
    scanf(" %c", &mode);
    while(getchar() != '\n');

    switch (mode)
    {
    case '1':
        launch_basic_calculation();
        break;
    
    default:
        printf("\nInvalid mode!");
        break;
    }
}

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
    int first_operand = default_number[0];
    int second_operand = default_number[1];
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
