CC? = ${CC}
CFLAGS = -Wall -Iinclude
LIB_SRC = src/servo.c
MAIN =set_servo.c

all: set_servo

set_servo:
	$(CC) $(CFLAGS) $(LIB_SRC) $(MAIN) -o set_servo

clean:
	rm -f set_servo

