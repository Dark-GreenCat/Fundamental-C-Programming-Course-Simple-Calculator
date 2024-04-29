CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

SRCS	:= $(wildcard src/*.c)
OBJS	:= $(patsubst src/%.c, build/%.o, $(SRCS))

build: build/main.exe

build/main.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^
