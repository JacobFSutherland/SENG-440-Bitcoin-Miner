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

struct block {
  uint8_t prev_hash[SHA256_HASH_LEN];
  uint32_t nonce;  // this is UB but we don't care, we just need a unique value
} __attribute__((packed));

int main(int argc, char** argv) {
  if (argc < 4) {
    printf(
        "Usage: %s <difficulty> <input> <iterations>\n"
        "  difficulty: number of leading zeros in the hash\n"
        "  input: the hash of the genesis block (in hex)\n"
        "  iterations: the number of blocks you want to solve\n",
        argv[0]);
    return 1;
  }
  int difficulty = atoi(argv[1]);
  if (difficulty < 0 || difficulty > 256) {
    printf("Difficulty must be between 0 and 256\n");
    return 1;
  }
  char* s = argv[2];
  struct block startingBlock = {0};
  if (strlen(s) != SHA256_HASH_LEN * 2) {
    printf("Input must be a hash of length %d bytes\n", SHA256_HASH_LEN);
    return 1;
  }
  for (int i = 0; i < SHA256_HASH_LEN * 2; i++) {
    char c = s[i];
    int x = 0;
    if (c >= '0' && c <= '9') {
      x = c - '0';
    } else if (c >= 'a' && c <= 'f') {
      x = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
      x = c - 'A' + 10;
    } else {
      printf("Input must be a hash in hex\n");
      return 1;
    }
    if (i % 2 == 0) {
      startingBlock.prev_hash[i / 2] = x << 4;
    } else {
      startingBlock.prev_hash[i / 2] |= x;
    }
  }

  int iterations = atoi(argv[3]);
  int blocks = 0;

  size_t len;
  struct block* currBlock = sha256_alloc_padded((uint8_t*)&startingBlock,
                                                sizeof(startingBlock), &len);
  uint32_t* nonces = malloc(iterations * sizeof(uint32_t));

  while (blocks < iterations) {
    uint8_t output[SHA256_HASH_LEN];
    sha256((uint8_t*)currBlock, len, output);
    if (is_valid_block(output, difficulty)) {
      /* real bitcoin network things would go here */
      // Copy hash to current block for next computation
      memcpy(currBlock->prev_hash, output, SHA256_HASH_LEN);
      nonces[blocks] = currBlock->nonce;
      currBlock->nonce = 0;
      blocks++;
      continue;
    }
    currBlock->nonce += 1;
  }

  for (int i = 0; i < iterations; i++) {
    printf("%08x\n", nonces[i]);
  }

  free(nonces);

  return 0;
}