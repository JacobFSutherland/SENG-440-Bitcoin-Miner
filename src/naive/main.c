#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SHA256_HASH_LEN (256 / 8)

const uint32_t kPrimes[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,  //
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,  //
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,  //
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,  //
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,  //
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,  //
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,  //
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,  //
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,  //
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,  //
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,  //
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,  //
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,  //
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,  //
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,  //
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void sha256_pad(const char* input, size_t size, uint8_t** output,
                size_t* output_size) {
  // - append 1 bit to message
  // - append 0 bits until message length is 448 bits mod 512
  // - append 64 bits representing original message length
  // - return padded message

  // Calculate total size: message size + 1 bit + additional zero bits + 64 bits
  // for length
  size_t bit_size = size * 8;
  size_t padded_bit_size = ((bit_size + 1 + 512) & ~(512 - 1)) + 64;
  *output_size = padded_bit_size / 8;
  *output = (uint8_t*)calloc(*output_size, sizeof(uint8_t));

  // Original message copy
  memcpy(*output, input, size);

  // Append 1 bit
  (*output)[size] = 0b10000000;

  // Append original message length in bits. Assuming the message is shorter
  // than 2^32 bits as we can't handle larger messages
  uint64_t size_bits = size * 8;
  for (int i = 0; i < 8; i++)
    (*output)[*output_size - 1 - i] = (size_bits >> (i * 8)) & 0xff;

  return;
  
}

// precondition: input_len is a multiple of 64
void sha256(char* input, size_t input_len, char* output) {
  // - for each block
  //   - copy block into message schedule (64 32-bit words)
  //   - extend message schedule
  //   - initialize working variables
  //   - for each round
  //     - compute working variables
  // - compute hash value
  // - add hash value to result
  // sha256_pad(&input, &input_len);

  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t d;
  uint32_t e;
  uint32_t f;
  uint32_t g;
  uint32_t h;

  uint32_t w[64];

#define MESSAGE_FOOTER_LEN (64 / 8)

// this but ceil instead of floor
// size_t block_count = (input_len + 1 + MESSAGE_FOOTER_LEN) / 64;
#define CEILDIV(a, b) (((a) + (b)-1) / (b))
  size_t block_count = CEILDIV(input_len + 1 + MESSAGE_FOOTER_LEN, 64);
#undef CEILDIV

  for (size_t block = 0; block < block_count; block++) {
    //   - copy block into message schedule (64 32-bit words)
    //   - extend message schedule
  }

  ((uint32_t*)output)[0] = a;
  ((uint32_t*)output)[1] = b;
  ((uint32_t*)output)[2] = c;
  ((uint32_t*)output)[3] = d;
  ((uint32_t*)output)[4] = e;
  ((uint32_t*)output)[5] = f;
  ((uint32_t*)output)[6] = g;
  ((uint32_t*)output)[7] = h;

  return;
}

// check leading zeroes in hash against difficulty
int is_valid_block(char* hash, int difficulty) {
  for (int i = 0; i < difficulty; i++) {
    if (hash[i / 8] & (1 << (7 - (i % 8)))) {
      return 0;
    }
  }
  return 1;
}

// attempty to mine a block
// returns 1 if block is mined successfully
int mine_block(char* prev_block_hash, size_t prev_block_len, uint32_t nonce,
               int difficulty) {
  char input[SHA256_HASH_LEN + sizeof(uint32_t)];
  char output[SHA256_HASH_LEN];

  memcpy(input, prev_block_hash, SHA256_HASH_LEN);
  *((uint32_t*)(input + SHA256_HASH_LEN)) = nonce;

  sha256(input, sizeof(memcpy), output);

  int success = is_valid_block(output, difficulty);
  return success;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf(
        "Usage: %s <difficulty>\n"
        "  difficulty: number of leading zeros in the hash\n",
        argv[0]);
    return 1;
  }
  int difficulty = atoi(argv[1]);
  if (difficulty < 0 || difficulty > 256) {
    printf("Difficulty must be between 0 and 256\n");
    return 1;
  }
  char output[SHA256_HASH_LEN];
  printf("Hello, bitcoin!\n");
  return 0;
}