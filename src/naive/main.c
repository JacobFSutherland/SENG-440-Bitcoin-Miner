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
  if (argc < 4) {
    printf(
        "Usage: %s <difficulty> <input> <iterations>\n"
        "  difficulty: number of leading zeros in the hash\n"
        "  input: the genesis block\n",  // pass straight to sha256 for testing
        "  iterations: the number of blocks you want to solve\n",
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

  int iterations = atoi(argv[3]);
  int blocks = 0;
  uint8_t currBlock[SHA256_HASH_LEN + NONCE_LEN];
  memcpy(currBlock, s, SHA256_HASH_LEN);
  memset(currBlock + SHA256_HASH_LEN, 0, NONCE_LEN);  // Initialize nonce to 0

  while(blocks < iterations) {
    sha256((uint8_t*)currBlock, strlen(s) + NONCE_LEN, output);
    if(is_valid_block(output, difficulty)) {
      //Print or do something with the block here
      memcpy(currBlock, output, SHA256_HASH_LEN);  // Copy hash to current block for next computation
      memset(currBlock + SHA256_HASH_LEN, 0, NONCE_LEN);  // Reset nonce to 0
      
      blocks++;
    }
    (*(uint32_t*)(currBlock + SHA256_HASH_LEN))++;  // Increment nonce
  }

  write(1, output, SHA256_HASH_LEN);

  return 0;
}