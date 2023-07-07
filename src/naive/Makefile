CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all clean debug release

all: release

clean:
	rm -f main

debug: CFLAGS += -g3 -fsanitize=address -fsanitize=undefined
debug: main 

release: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

