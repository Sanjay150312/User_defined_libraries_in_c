CC ?= ${CC}
CFLAGS = -Wall -Iinclude
LIB_SRC = src/rbgpio.c
MAIN = main.c

all: switch_toggle

switch_toggle:
	$(CC) $(CFLAGS) $(LIB_SRC) $(MAIN) -o switch_toggle

clean:
	rm -f switch_toggle

