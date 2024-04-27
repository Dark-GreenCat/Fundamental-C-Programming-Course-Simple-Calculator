#include <stdio.h>

const int firstNumber = 1;
const int secondNumber = 2;
const char welcome_message[] = "Welcome to Simple Calculator";

int main() {
    printf("%s\n", welcome_message);

    int firstOperand = firstNumber;
    int secondOperand = secondNumber;
    char operator;
    int scanned_count;

    printf("-----------------------------\n");
    do {
        printf("Enter first operand: ");
        scanned_count = scanf("%d", &firstOperand);
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
        scanned_count = scanf("%d", &secondOperand);
        while (getchar() != '\n');

        if (scanned_count != 0) break;
        printf("[Error] Input should be a number!\n");
    } while (1);



    printf("-----------------------------");
    if (operator == '+') {
        long long sum = firstOperand + secondOperand;
        printf("\n%-10s: %d + %d = %ld", "Sum", firstOperand, secondOperand, sum);
    }
    else if (operator == '-') {
        int difference = firstOperand - secondOperand;
        printf("\n%-10s: %d - %d = %d", "Difference", firstOperand, secondOperand, difference);
    }
    else if (operator == '*') {
        long long product = firstOperand * secondOperand;
        printf("\n%-10s: %d * %d = %ld", "Product", firstOperand, secondOperand, product);
    }
    else if (operator == '/') {
        if (secondOperand == 0) {
            printf("\nDivision by 0 is not allowed!");
        }
        else {
            double quotient = ((double)firstOperand) / secondOperand;
            printf("\n%-10s: %d / %d = %.15g", "Quotient", firstOperand, secondOperand, quotient);
        }
    }
}