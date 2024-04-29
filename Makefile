CC 			:= gcc
CFLAGS 		:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

SRCDIR		:= src
BUILDDIR	:= build

SRCS		:= $(wildcard $(SRCDIR)/*.c)
OBJS		:= $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

build: build/main.exe

build/main.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^
