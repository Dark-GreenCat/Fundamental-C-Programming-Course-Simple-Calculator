CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

build: src/main.c src/input.c src/gcd.c src/basic_calculation.c src/base_converter.c 
	$(CC) $(CFLAGS) -o build/main src/*.c