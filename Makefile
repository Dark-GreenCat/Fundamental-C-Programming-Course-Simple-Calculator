CC 			:= gcc
CFLAGS 		:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

INCDIR		:= inc
SRCDIR		:= src
BUILDDIR	:= build

CFLAGS		+= $(addprefix -I , $(INCDIR)) 
SRCS		:= $(wildcard $(SRCDIR)/*.c)
OBJS		:= $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

build: $(BUILDDIR)/ build/main.exe

$(BUILDDIR)/:
	mkdir "$(BUILDDIR)"

build/main.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f build/*.o build/main.exe

.PHONY: clean build