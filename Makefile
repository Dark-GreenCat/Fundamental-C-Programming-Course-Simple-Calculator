build: src/main.c src/input.c src/gcd.c src/basic_calculation.c src/base_converter.c 
	gcc -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99 -o build/main src/*.c