#include <stddef.h>
#include <stdint.h>

#ifdef DEBUG
#include <stdio.h>
#endif

#define NONCE_LEN 4
#define SHA256_HASH_LEN 32
#define SHA256_BLOCK_LEN 64
#define MESSAGE_FOOTER_LEN 8

#define BLOCK_MAX_LEN (SHA256_BLOCK_LEN - MESSAGE_FOOTER_LEN - 1)

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

#define CEILDIV(a, b) (((a) + (b)-1) / (b))

#define WRITE32BE(P, V)                        \
  ((P)[0] = (0x00000000FF000000 & (V)) >> 030, \
   (P)[1] = (0x0000000000FF0000 & (V)) >> 020, \
   (P)[2] = (0x000000000000FF00 & (V)) >> 010, \
   (P)[3] = (0x00000000000000FF & (V)) >> 000)

#define ROTR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

#define MAJORITY(a, b, c) (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)))
#define CHOOSE(a, b, c) (((a) & (b)) ^ (~(a) & (c)))

#define EXPAND0(x) (ROTR32(x, 7) ^ ROTR32(x, 18) ^ ((x) >> 3))
#define EXPAND1(x) (ROTR32(x, 17) ^ ROTR32(x, 19) ^ ((x) >> 10))

#define HASH0(x) (ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22))
#define HASH1(x) (ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25))

void sha256(const uint8_t* input, size_t input_len, uint8_t* output) {
  uint32_t w[64];

  // reinterpret output bytes as 32-bit words
  uint32_t* H = (uint32_t*)output;
  H[0] = 0x6a09e667;
  H[1] = 0xbb67ae85;
  H[2] = 0x3c6ef372;
  H[3] = 0xa54ff53a;
  H[4] = 0x510e527f;
  H[5] = 0x9b05688c;
  H[6] = 0x1f83d9ab;
  H[7] = 0x5be0cd19;

  size_t block_count = CEILDIV(input_len + 1 + MESSAGE_FOOTER_LEN, 64);
#ifdef DEBUG
  fprintf(stderr, "block_count: %zu\n", block_count);
  fprintf(stderr, "input_len: %zu\n", input_len);
#endif

  for (size_t block = 0; block < block_count; block++) {
    // copy block into message schedule (16 32-bit words)
    size_t end_of_block = (block + 1) * 64;
#ifdef DEBUG
    fprintf(stderr, "end of block %zu: %zu\n", block, (block + 1) * 64);
#endif
    if (end_of_block < input_len) {
      for (int i = 0; i < 16; i++) {
        w[i] = ((input[block * 64 + i * 4 + 0] & 0xFF) << 24) |
               ((input[block * 64 + i * 4 + 1] & 0xFF) << 16) |
               ((input[block * 64 + i * 4 + 2] & 0xFF) << 8) |
               ((input[block * 64 + i * 4 + 3] & 0xFF) << 0);
      }
    } else {
      for (int i = 0; i < 16; i++) {
        w[i] = 0;
      }
      size_t input_bytes = block * 64 > input_len ? 0 : input_len - block * 64;
#ifdef DEBUG
      fprintf(stderr, "input_bytes: %zu\n", input_bytes);
#endif

      if (input_bytes != 0) {
        // copy message bytes
        for (size_t i = 0; i < input_bytes; i++) {
          w[i / 4] |= (input[block * 64 + i] & 0xFFu) << (8 * (3 - (i % 4)));
        }
        // append 1 bit
        w[input_bytes / 4] |= (0x80u & 0xFF) << (8 * (3 - (input_bytes % 4)));
      } else if (input_len % 64 == 0 && block == block_count - 1) {
        // append 1 bit
        w[0] |= (0x80u & 0xFF) << (8 * (3 - (input_bytes % 4)));
      }

      if (block == block_count - 1) {
        //  append message length
        uint64_t total_len = input_len * 8;
        w[14] = (total_len & 0xFFFFFFFF00000000) >> 32;
        w[15] = (total_len & 0x00000000FFFFFFFF) >> 0;
      }
    }

#ifdef DEBUG
// print message schedule
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                \
  ((byte)&0x80 ? '1' : '0'), ((byte)&0x40 ? '1' : '0'),     \
      ((byte)&0x20 ? '1' : '0'), ((byte)&0x10 ? '1' : '0'), \
      ((byte)&0x08 ? '1' : '0'), ((byte)&0x04 ? '1' : '0'), \
      ((byte)&0x02 ? '1' : '0'), ((byte)&0x01 ? '1' : '0')

    for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 4; j++) {
        fprintf(stderr, BYTE_TO_BINARY_PATTERN " ",
                BYTE_TO_BINARY(w[i] >> (8 * (3 - j))));
      }
      fprintf(stderr, "\n");
    }
#undef BYTE_TO_BINARY
#undef BYTE_TO_BINARY_PATTERN
#endif

    // expand message schedule into 64 32-bit words
    for (int i = 16; i < 64; i++) {
      w[i] = EXPAND1(w[i - 2]) + w[i - 7] + EXPAND0(w[i - 15]) + w[i - 16];
    }

    // hash message schedule
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

    // update hash state
    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
  }

  // output is always big endian
  for (int i = 0; i < 8; i++) {
    int v = H[i];
    WRITE32BE((uint8_t*)(H + i), v);
  }

  return;
}