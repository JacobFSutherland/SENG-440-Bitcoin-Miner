#include "sha256.c"

#include <stdint.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
  (void)argc;
  uint8_t output[SHA256_HASH_LEN];
  char* s = argv[1];
  sha256((uint8_t*)s, strlen(s), output);
  // raw bytes, not hex
  write(1, output, SHA256_HASH_LEN);
  return 0;
}