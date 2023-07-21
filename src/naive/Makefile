CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

TARGETS = main sha256_test sha256_benchmark

.PHONY: all clean debug release

all: debug

clean:
	rm -f main *_test *_benchmark

debug: CFLAGS += -g3 -fsanitize=address -fsanitize=undefined
debug: $(TARGETS)

release: $(TARGETS)

main: main.c
	$(CC) $(CFLAGS) -o main main.c

sha256_test: sha256_test.c
	$(CC) $(CFLAGS) -o sha256_test sha256_test.c

