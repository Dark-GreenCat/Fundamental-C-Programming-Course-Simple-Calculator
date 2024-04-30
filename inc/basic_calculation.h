#ifndef BASIC_CALCULATION_H
#define BASIC_CALCULATION_H

double calculate(double first_operand, double second_operand, char operator);
/*
    This function is used to calculate the result and print to console.
    The result is returned as long long type (which means double number will lose the fractional part).
*/
void show_result(int first_operand, int second_operand, double result, char operator);
void launch_basic_calculation();

#endif