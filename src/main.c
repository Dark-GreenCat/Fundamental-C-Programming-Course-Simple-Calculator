#include <stdio.h>

const int firstNumber = 1;
const int secondNumber = 2;

int main() {
    printf("Welcome to Simple Calculator\n");

    int firstOperand = firstNumber;
    int secondOperand = secondNumber;
    char operator;

    printf("-----------------------------\n");
    printf("Enter first operand: ");
    while(scanf("%d", &firstOperand) == 0) {
        while(getchar() != '\n');
        printf("[Error] Input should be a number!");
        printf("\nEnter first operand: ");
    }

    while(getchar() != '\n');
    printf("Enter operator [+|-|*|/]: ");
    scanf("%c", &operator);
    
    printf("Enter second operand: ");
    while(scanf("%d", &secondOperand) == 0) {
        while(getchar() != '\n');
        printf("[Error] Input should be a number!");
        printf("\nEnter second operand: ");
    }


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