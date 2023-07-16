#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHA256_HASH_LEN (256 / 8)
#define SHA256_BLOCK_LEN 64

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

// char* sha256_pad(const char* input, size_t size, size_t* output_size) {
//   // - append 1 bit to message
//   // - append 0 bits until message length is 448 bits mod 512
//   // - append 64 bits representing original message length
//   // - return padded message

//   // Calculate total size: message size + 1 bit + additional zero bits + 64
//   bits
//   // for length
//   size_t bit_size = size * 8;
//   size_t padded_bit_size = ((bit_size + 1 + 512) & ~(512 - 1)) + 64;
//   *output_size = padded_bit_size / 8;
//   *output = (uint8_t*)calloc(*output_size, sizeof(uint8_t));

//   // Original message copy
//   memcpy(*output, input, size);

//   // Append 1 bit
//   (*output)[size] = 0b10000000;

//   // Append original message length in bits. Assuming the message is shorter
//   // than 2^32 bits as we can't handle larger messages
//   uint64_t size_bits = size * 8;
//   for (int i = 0; i < 8; i++)
//     (*output)[*output_size - 1 - i] = (size_bits >> (i * 8)) & 0xff;

//   return;
// }

#define WRITE32BE(P, V)                        \
  ((P)[0] = (0x00000000FF000000 & (V)) >> 030, \
   (P)[1] = (0x0000000000FF0000 & (V)) >> 020, \
   (P)[2] = (0x000000000000FF00 & (V)) >> 010, \
   (P)[3] = (0x00000000000000FF & (V)) >> 000)

#define WRITE64BE(P, V)                        \
  ((P)[0] = (0xFF00000000000000 & (V)) >> 070, \
   (P)[1] = (0x00FF000000000000 & (V)) >> 060, \
   (P)[2] = (0x0000FF0000000000 & (V)) >> 050, \
   (P)[3] = (0x000000FF00000000 & (V)) >> 040, \
   (P)[4] = (0x00000000FF000000 & (V)) >> 030, \
   (P)[5] = (0x0000000000FF0000 & (V)) >> 020, \
   (P)[6] = (0x000000000000FF00 & (V)) >> 010, \
   (P)[7] = (0x00000000000000FF & (V)) >> 000)

#define ROTR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

#define MAJORITY(a, b, c) (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)))
#define CHOOSE(a, b, c) (((a) & (b)) ^ (~(a) & (c)))

#define EXPAND0(x) (ROTR32(x, 7) ^ ROTR32(x, 18) ^ ((x) >> 3))
#define EXPAND1(x) (ROTR32(x, 17) ^ ROTR32(x, 19) ^ ((x) >> 10))

#define HASH0(x) (ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22))
#define HASH1(x) (ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25))

// precondition: input_len is a multiple of 64
void sha256(const char* input, size_t input_len, char* output) {
  // - for each block
  //   - copy block into message schedule (64 32-bit words)
  //   - extend message schedule
  //   - initialize working variables
  //   - for each round
  //     - compute working variables
  // - compute hash value
  // - add hash value to result
  // sha256_pad(&input, &input_len);

  uint32_t* H = (uint32_t*)output;

  // WRITE32BE(H + 0, 0x6a09e667);
  // WRITE32BE(H + 1, 0xbb67ae85);
  // WRITE32BE(H + 2, 0x3c6ef372);
  // WRITE32BE(H + 3, 0xa54ff53a);
  // WRITE32BE(H + 4, 0x510e527f);
  // WRITE32BE(H + 5, 0x9b05688c);
  // WRITE32BE(H + 6, 0x1f83d9ab);
  // WRITE32BE(H + 7, 0x5be0cd19);
  H[0] = 0x6a09e667;
  H[1] = 0xbb67ae85;
  H[2] = 0x3c6ef372;
  H[3] = 0xa54ff53a;
  H[4] = 0x510e527f;
  H[5] = 0x9b05688c;
  H[6] = 0x1f83d9ab;
  H[7] = 0x5be0cd19;

  uint32_t w[64];

#define MESSAGE_FOOTER_LEN (64 / 8)

// this but ceil instead of floor
// size_t block_count = (input_len + 1 + MESSAGE_FOOTER_LEN) / 64;
#define CEILDIV(a, b) (((a) + (b)-1) / (b))
  size_t block_count = CEILDIV(input_len + 1 + MESSAGE_FOOTER_LEN, 64);
#undef CEILDIV

  for (size_t block = 0; block < block_count; block++) {
    //   - copy block into message schedule (64 32-bit words)
    if (block == block_count - 1) {
      // TODO consider the case where the last block more than 55 bytes but less
      // than 64 in that case, we need to pad the remainder of the block with
      // the one and zeroes, and add a second block with all zeroes and the
      // header.

      // last block
      // - append 1 bit to message
      // - append 0 bits until message length is 448 bits mod 512
      // - append 64 bits representing original message length

      for (int i = 0; i < 16; i++) {
        w[i] = 0;
      }

      // copy message bytes
      size_t block_len = input_len % 64;
      size_t offset = 0;
      for (; offset < block_len; offset++) {
        w[offset / 4] |=
            ((input[block * 64 + offset] & 0xFF) << (8 * (3 - (offset % 4))));
      }
      // append 1 bit
      w[offset / 4] |= (0x80u & 0xFF) << (8 * (3 - (offset % 4)));
      offset += 1;
      // pad with zeros
      for (; offset < 64 - MESSAGE_FOOTER_LEN; offset++) {
        w[offset / 4] |= (0u & 0xFF) << (8 * (3 - (offset % 4)));
      };
      //  append message length
      uint64_t total_len = input_len * 8;
      w[14] = (total_len & 0xFFFFFFFF00000000) >> 32;
      w[15] = (total_len & 0x00000000FFFFFFFF) >> 0;
    } else {
      // FIXME, needs padding and stuff
      for (size_t i = 0; i < 64; i++) {
        w[i / 4] |= ((input[block * 64 + i] & 0xFF) << (8 * (3 - (i % 4))));
      }
      // memcpy(w, input + block * 64, 64);
    }

    // expand message schedule
    for (int i = 16; i < 64; i++) {
      w[i] = EXPAND1(w[i - 2]) + w[i - 7] + EXPAND0(w[i - 15]) + w[i - 16];
    }

    // BELOW HERE IS WRONG?

    // hash block
    uint32_t a = H[0];
    uint32_t b = H[1];
    uint32_t c = H[2];
    uint32_t d = H[3];
    uint32_t e = H[4];
    uint32_t f = H[5];
    uint32_t g = H[6];
    uint32_t h = H[7];

    uint32_t t1 = 0;
    uint32_t t2 = 0;
    for (int i = 0; i < 64; i++) {
      t1 = h + HASH1(e) + CHOOSE(e, f, g) + kPrimes[i] + w[i];
      t2 = HASH0(a) + MAJORITY(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
  }

  for (int i = 0; i < 8; i++) {
    int v = H[i];
    WRITE32BE((char*)(H + i), v);
  }

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

// // attempty to mine a block
// // returns 1 if block is mined successfully
// int mine_block(char* prev_block_hash, size_t prev_block_len, uint32_t nonce,
//                int difficulty) {
//   char input[SHA256_HASH_LEN + sizeof(uint32_t)];
//   char output[SHA256_HASH_LEN];

//   memcpy(input, prev_block_hash, SHA256_HASH_LEN);
//   *((uint32_t*)(input + SHA256_HASH_LEN)) = nonce;

//   sha256(input, sizeof(memcpy), output);

//   int success = is_valid_block(output, difficulty);
//   return success;
// }

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
  char output[SHA256_HASH_LEN];
  char* s = argv[2];
  // fprintf(stderr, "input='%s'\n", s);
  // fprintf(stderr, "len=%ld\n", strlen(s));
  sha256(s, strlen(s), output);
  write(1, output, SHA256_HASH_LEN);

  return 0;
}