#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "sha256.c"

int main(int argc, char** argv) {
  if (argc < 2) {
    printf(
        "Usage: %s <input_len> <iterations>\n"
        "  input_len: length of input\n"
        "  iterations: number of iterations\n",
        argv[0]);
    return 1;
  }
  uint8_t output[SHA256_HASH_LEN];
  int input_len = atoi(argv[1]);
  int iterations = atoi(argv[2]);
  uint8_t* input = (uint8_t*)malloc(input_len);
  for (int i = 0; i < input_len; i++) {
    input[i] = i & 0xFF;
  }
  for (int i = 0; i < iterations; i++) {
    sha256(input, input_len, output);
    input[input_len - 1] = output[0];
  }
  free(input);
  return 0;
}