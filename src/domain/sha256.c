#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NONCE_LEN 4
#define SHA256_HASH_LEN 32
#define SHA256_BLOCK_LEN 64
#define MESSAGE_FOOTER_LEN 8

#define BLOCK_MAX_LEN (SHA256_BLOCK_LEN - MESSAGE_FOOTER_LEN - 1)

#define CEILDIV(a, b) (((a) + (b)-1) / (b))

#define write32be(p, v)                       \
  (p)[0] = (0x00000000FF000000 & (v)) >> 030; \
  (p)[1] = (0x0000000000FF0000 & (v)) >> 020; \
  (p)[2] = (0x000000000000FF00 & (v)) >> 010; \
  (p)[3] = (0x00000000000000FF & (v)) >> 000;

#define rotr32(x, n) ((x >> n) | (x << (32 - n)))
#define majority(a, b, c) ((a & b) ^ (a & c) ^ (b & c))
#define choose(a, b, c) ((a & b) ^ (~a & c))
#define expand0(x) (rotr32(x, 7) ^ rotr32(x, 18) ^ (x >> 3))
#define expand1(x) (rotr32(x, 17) ^ rotr32(x, 19) ^ (x >> 10))
#define hash0(x) (rotr32(x, 2) ^ rotr32(x, 13) ^ rotr32(x, 22))
#define hash1(x) (rotr32(x, 6) ^ rotr32(x, 11) ^ rotr32(x, 25))

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

  size_t block_count = CEILDIV(input_len, 64);

  for (size_t block = 0; block < block_count; block++) {
    // copy block into message schedule (16 32-bit words)
    for (int i = 0; i < 16; i++) {
      w[i] = ((input[block * 64 + i * 4 + 0] & 0xFF) << 24) |
             ((input[block * 64 + i * 4 + 1] & 0xFF) << 16) |
             ((input[block * 64 + i * 4 + 2] & 0xFF) << 8) |
             ((input[block * 64 + i * 4 + 3] & 0xFF) << 0);
    }

    // expand and hash message schedule
    register uint32_t a = H[0];
    register uint32_t b = H[1];
    register uint32_t c = H[2];
    register uint32_t d = H[3];
    register uint32_t e = H[4];
    register uint32_t f = H[5];
    register uint32_t g = H[6];
    register uint32_t h = H[7];

    register uint32_t t1 = 0;
    register uint32_t t2 = 0;

    register uint32_t w2;
    register uint32_t w15;
    register uint32_t wi;

#define EXPAND_ITER(i)                                    \
  w2 = w[i - 2];                                          \
  w15 = w[i - 15];                                        \
  wi = expand1(w2) + w[i - 7] + expand0(w15) + w[i - 16]; \
  w[i] = wi;

#define HASH_ITER(k)                            \
  t1 = h + hash1(e) + choose(e, f, g) + k + wi; \
  t2 = hash0(a) + majority(a, b, c);            \
  h = g;                                        \
  g = f;                                        \
  f = e;                                        \
  e = d + t1;                                   \
  d = c;                                        \
  c = b;                                        \
  b = a;                                        \
  a = t1 + t2;

#include "codegen.c"

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
    write32be((uint8_t*)(H + i), v);
  }

  return;
}

void* sha256_alloc_padded(uint8_t* input, size_t input_len,
                          size_t* padded_len) {
  size_t block_count = CEILDIV(input_len + 1 + MESSAGE_FOOTER_LEN, 64);
  *padded_len = block_count * 64;
  uint8_t* padded = malloc(*padded_len);
  memcpy(padded, input, input_len);
  padded[input_len] = 0x80;
  // pad with zeros
  memset(padded + input_len + 1, 0, *padded_len - input_len - 1);
  // add footer
  size_t total_len = input_len * 8;
  for (int i = 0; i < MESSAGE_FOOTER_LEN; i++) {
    padded[*padded_len - MESSAGE_FOOTER_LEN + i] = (total_len >> (8 * (7 - i)));
  }
  return padded;
}