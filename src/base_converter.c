#include "../inc/base_converter.h"

#include <stdio.h>
#include <stdlib.h>
#include "../inc/input.h"

void base_10_to_2_convert(unsigned int number, bool* binary_array) {
    for (int i = 0; i < 32; i++) {
        binary_array[i] = (number % 2);
        number /= 2;
    }
}

void launch_base_10_to_2_converter() {
    unsigned int number_of_conversion = 0;
    number_of_conversion = (unsigned int) get_input("Enter number of conversion", "[Error] Input shoule be a number!", false);
    printf("Number of conversion received: %u", number_of_conversion);

    unsigned int* number_array = NULL;
    number_array = (unsigned int*) malloc(number_of_conversion * sizeof(unsigned int));
    if (number_array == NULL) {
        printf("\n[ERROR] Failed to allocate memory");
        printf("\nExiting...");
        return;
    }

    for (unsigned int i = 0; i < number_of_conversion; i++) {
        printf("\n\nGetting number_array[%d]:", i);
        number_array[i] = (unsigned int) get_input("\nEnter a 32-bit integer", "[Error] Input shoule be a number!", false);
        printf("number_array[%d] = %u", i, number_array[i]);
    }

    printf("\n\nConverion result:");
    for (unsigned int i = 0; i < number_of_conversion; i++) {
        bool binary[32] = { 0 };
        base_10_to_2_convert(number_array[i], binary);

        char message[30];
        sprintf(message, "number_array[%d]: %u", i, number_array[i]);
        printf("\n%-30s - binary form: ", message);
        for (int j = 31; j >= 0; j--) {
            printf("%d", binary[j]);
        }
    }

    free(number_array);
}