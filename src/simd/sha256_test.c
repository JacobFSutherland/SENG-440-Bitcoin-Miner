#include "sha256.c"

#include <stdint.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
  (void)argc;
  uint8_t output[SHA256_HASH_LEN];
  char* s = argv[1];
#ifdef DEBUG
  fprintf(stderr, "input='%s'\n", s);
  fprintf(stderr, "len=%ld\n", strlen(s));
#endif
  size_t len;
  uint8_t* input = sha256_alloc_padded((uint8_t*)s, strlen(s), &len);
  sha256(input, len, output);
  // raw bytes, not hex
  write(1, output, SHA256_HASH_LEN);
  return 0;
}