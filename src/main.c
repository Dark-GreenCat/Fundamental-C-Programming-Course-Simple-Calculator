#include <stdio.h>

const int firstNumber = 1;
const int secondNumber = 2;

int main() {
    printf("Welcome to Simple Calculator\n");

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


    long long sum = firstOperand + secondOperand;
    int difference = firstOperand - secondOperand;
    long long product = firstOperand * secondOperand;
    double quotient = ((double) firstOperand) / secondOperand;

    printf("-----------------------------");
    switch (operator)
    {
    case '+':
        printf("\n%-10s: %d + %d = %ld", "Sum", firstOperand, secondOperand, sum);
        break;
    
    case '-':
        printf("\n%-10s: %d - %d = %d", "Difference", firstOperand, secondOperand, difference);
        break;
    
    case '*':
        printf("\n%-10s: %d * %d = %ld", "Product", firstOperand, secondOperand, product);
        break;

    case '/':
        printf("\n%-10s: %d / %d = %.15g", "Quotient", firstOperand, secondOperand, quotient);
        break;

    default:
        printf("\nInvalid operator! Operator must be [+|-|*|/].");
        break;
    }
}