CC 			:= gcc
CFLAGS 		:= -Wall -Wextra -Wpedantic -Wconversion -Wunreachable-code --std=c99

INCDIR		:= inc
SRCDIR		:= src
BUILDDIR	:= build
APPDIR		:= bin
APPNAME		:= simple_calculator

CFLAGS		+= $(addprefix -I , $(INCDIR)) 
SRCS		:= $(wildcard $(SRCDIR)/*.c)
OBJS		:= $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
DEPS		:= $(wildcard $(addsuffix /*.h, $(INCDIR)))

release: build
	cp "$(BUILDDIR)/$(APPNAME)" "$(APPDIR)/$(APPNAME)"

run: build
	build/$(APPNAME)

build: $(BUILDDIR)/ $(BUILDDIR)/ $(BUILDDIR)/$(APPNAME)

$(BUILDDIR)/:
	mkdir "$(BUILDDIR)"

$(BUILDDIR)/$(APPNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f build/*.o build/$(APPNAME)

.PHONY: clean build run