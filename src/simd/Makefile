CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g3

TARGETS = main sha256_test sha256_benchmark

.PHONY: all clean debug release codegen

all: debug

clean:
	rm -f main *_test *_benchmark codegen.c

debug: CFLAGS += -fsanitize=address -fsanitize=undefined
debug: $(TARGETS)

release: $(TARGETS)

release-opt: CFLAGS += -O3 -march=native
release-opt: $(TARGETS)

main: main.c sha256.c codegen
	$(CC) $(CFLAGS) -o main main.c

sha256_test: sha256_test.c sha256.c codegen
	$(CC) $(CFLAGS) -o sha256_test sha256_test.c

codegen: codegen.py
	python3 codegen.py
