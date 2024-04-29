CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

build: src/*.c
	$(CC) $(CFLAGS) -o build/main src/*.c