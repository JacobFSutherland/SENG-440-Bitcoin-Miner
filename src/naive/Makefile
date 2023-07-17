CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all clean debug release

all: debug

clean:
	rm -f main *_test

debug: CFLAGS += -g3 -fsanitize=address -fsanitize=undefined
debug: main sha256_test

release: main sha256_test

main: main.c
	$(CC) $(CFLAGS) -o main main.c

sha256_test: sha256_test.c
	$(CC) $(CFLAGS) -o sha256_test sha256_test.c

