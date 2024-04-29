CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

build: build/main.exe

build/main.exe: build/main.o build/input.o build/gcd.o build/basic_calculation.o build/base_converter.o
	$(CC) $(CFLAGS) -o $@ $^

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c -o $@ $^

build/input.o: src/input.c
	$(CC) $(CFLAGS) -c -o $@ $^

build/gcd.o: src/gcd.c
	$(CC) $(CFLAGS) -c -o $@ $^

build/basic_calculation.o: src/basic_calculation.c
	$(CC) $(CFLAGS) -c -o $@ $^

build/base_converter.o: src/base_converter.c
	$(CC) $(CFLAGS) -c -o $@ $^
