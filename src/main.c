#include <stdio.h>

const int firstNumber = 1;
const int secondNumber = 2;

int main() {
    printf("Welcome to Simple Calculator\n");

    int firstOperand = firstNumber;
    int secondOperand = secondNumber;

    printf("-----------------------------\n");
    printf("Enter first operand: ");
    scanf("%d", &firstOperand);
    printf("Enter second operand: ");
    scanf("%d", &secondOperand);

    long long sum = firstOperand + secondOperand;
    int difference = firstOperand - secondOperand;
    long long product = firstOperand * secondOperand;
    double quotient = ((double) firstOperand) / secondOperand;

    printf("-----------------------------");
    printf("\n%-10s: %d + %d = %ld", "Sum", firstOperand, secondOperand, sum);
    printf("\n%-10s: %d - %d = %d", "Difference", firstOperand, secondOperand, difference);
    printf("\n%-10s: %d * %d = %ld", "Product", firstOperand, secondOperand, product);
    printf("\n%-10s: %d / %d = %.15g", "Quotient", firstOperand, secondOperand, quotient);
}