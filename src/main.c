#include <stdio.h>

const int firstNumber = 1;
const int secondNumber = 2;

int main() {
    printf("Welcome to Simple Calculator\n");

    int firstOperand = firstNumber;
    int secondOperand = secondNumber;

    long long sum = firstOperand + secondOperand;
    int difference = firstOperand - secondOperand;
    long long product = firstOperand * secondOperand;
    double quotient = firstOperand / secondOperand;

    printf("-----------------------------");
    printf("\nSum: %d + %d = %ld", firstOperand, secondOperand, sum);
    printf("\nDifference: %d - %d = %d", firstOperand, secondOperand, difference);
    printf("\nProduct: %d * %d = %ld", firstOperand, secondOperand, product);
    printf("\nQuotient: %d / %d = %lf", firstOperand, secondOperand, quotient);
}