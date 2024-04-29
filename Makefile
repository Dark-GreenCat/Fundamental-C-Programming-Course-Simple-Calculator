CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

build: build/main.exe

build/main.exe: build/main.o build/input.o build/gcd.o build/basic_calculation.o build/base_converter.o
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^
