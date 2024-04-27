#include <stdio.h>

const int first_number = 1;
const int second_number = 2;
const char welcome_message[] = "Welcome to Simple Calculator";

int main() {
    printf("%s\n", welcome_message);

    int first_operand = first_number;
    int second_operand = second_number;
    char operator;
    int scanned_count;

    printf("-----------------------------\n");
    do {
        printf("Enter first operand: ");
        scanned_count = scanf("%d", &first_operand);
        while (getchar() != '\n');

        if (scanned_count != 0) break;
        printf("[Error] Input should be a number!\n");
    } while (1);

    do {
        printf("Enter operator [+|-|*|/]: ");
        scanned_count = scanf(" %c", &operator);
        while (getchar() != '\n');

        if (operator == '+' || operator == '-' || operator == '*' || operator == '/') break;
        printf("[Error] Input should be [+|-|*|/]!\n");
    } while (1);

    do {
        printf("Enter second operand: ");
        scanned_count = scanf("%d", &second_operand);
        while (getchar() != '\n');

        if (scanned_count != 0) break;
        printf("[Error] Input should be a number!\n");
    } while (1);



    printf("-----------------------------");
    if (operator == '+') {
        long long sum = first_operand + second_operand;
        printf("\n%-10s: %d + %d = %ld", "Sum", first_operand, second_operand, sum);
    }
    else if (operator == '-') {
        int difference = first_operand - second_operand;
        printf("\n%-10s: %d - %d = %d", "Difference", first_operand, second_operand, difference);
    }
    else if (operator == '*') {
        long long product = first_operand * second_operand;
        printf("\n%-10s: %d * %d = %ld", "Product", first_operand, second_operand, product);
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