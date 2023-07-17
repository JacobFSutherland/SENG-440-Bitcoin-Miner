#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "sha256.c"

// check leading zeroes in hash against difficulty
int is_valid_block(uint8_t* hash, int difficulty) {
  for (int i = 0; i < difficulty; i++) {
    if (hash[i / 8] & (1 << (7 - (i % 8)))) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    printf(
        "Usage: %s <difficulty> <input>\n"
        "  difficulty: number of leading zeros in the hash\n"
        "  input: the genesis block\n",  // pass straight to sha256 for testing
        argv[0]);
    return 1;
  }
  int difficulty = atoi(argv[1]);
  if (difficulty < 0 || difficulty > 256) {
    printf("Difficulty must be between 0 and 256\n");
    return 1;
  }
  uint8_t output[SHA256_HASH_LEN];
  char* s = argv[2];
#ifdef DEBUG
  fprintf(stderr, "input='%s'\n", s);
  fprintf(stderr, "len=%ld\n", strlen(s));
#endif
  sha256((uint8_t*)s, strlen(s), output);
  write(1, output, SHA256_HASH_LEN);

  return 0;
}