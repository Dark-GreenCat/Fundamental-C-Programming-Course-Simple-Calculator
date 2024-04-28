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
/*
    This function is used to create UI to convert user's inputted number to 32bit binary.
    This function supports 32-bit positive integer only.
*/
void launch_base_10_to_2_converter();
void launch_gcd();
unsigned int calculate_gcd(unsigned int first_number, unsigned int second_number);

int main() {
    printf("%s", welcome_message);
    printf("\n-----------------------------");

    char mode = 0;
    printf("\nSimple Calculator Mode");
    printf("\n\t1. Basic calculation");
    printf("\n\t2. Base 10 to 2 converter");
    printf("\n\t3. Greatest common divisor");
    printf("\nSelect mode [1-2]: ");
    scanf(" %c", &mode);
    while(getchar() != '\n');
    printf("-----------------------------\n");

    switch (mode)
    {
    case '1':
        launch_basic_calculation();
        break;
    
    case '2':
        launch_base_10_to_2_converter();
        break;

    case '3':
        launch_gcd();
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

void launch_base_10_to_2_converter() {
    unsigned int number;
    number = (unsigned int) get_input("Enter a 32-bit integer", "[Error] Input shoule be a number!", false);
    printf("\nNumber received: %u", number);

    bool binary[32] = { 0 };
    for (int i = 0; i < 32; i++) {
        binary[i] = (number % 2);
        number /= 2;
    }

    printf("\nBinary form: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

void launch_gcd() {
    unsigned int first_number = (unsigned int) get_input("Enter first positive integer", "[ERROR] Input should be a number", false);
    unsigned int second_number = (unsigned int) get_input("Enter second positive integer", "[ERROR] Input should be a number", false);

    printf("\nGCD: %d", calculate_gcd(first_number, second_number));
}

unsigned int calculate_gcd(unsigned int first_number, unsigned int second_number) {
    if (first_number == 0 || second_number == 0)
        return (first_number + second_number);
    
    if (first_number > second_number) 
        return calculate_gcd(first_number - second_number, second_number);
    else
        return calculate_gcd(first_number, second_number - first_number);
}
