#include "../inc/gcd.h"

#include <stdio.h>
#include <stdbool.h>
#include "../inc/input.h"

void launch_gcd() {
    unsigned int first_number = (unsigned int) get_input("Enter first positive integer", "[ERROR] Input should be a number", false);
    unsigned int second_number = (unsigned int) get_input("Enter second positive integer", "[ERROR] Input should be a number", false);

    sort(&first_number, &second_number);
    printf("\nGCD: %u", calculate_gcd(first_number, second_number));
}

unsigned int calculate_gcd(unsigned int smaller_number, unsigned int greater_number) {
    if (smaller_number == 0) return greater_number;
    return calculate_gcd(greater_number % smaller_number, smaller_number);
}

void swap(unsigned int* first_number, unsigned int* second_number) {
        unsigned int temp = *first_number;
        *first_number = *second_number;
        *second_number = temp;
}

void sort(unsigned int* first_number, unsigned int* second_number) {
    if (*first_number > *second_number)
        swap(first_number, second_number);
}