
kPrimes = [
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
  0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
  0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
  0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
  0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
  0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
  0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
  0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
  0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
]

def get_neon_at(position, result_var):
  q = position // 4
  i = position % 4
  return f'asm("mov %w0, %1.s[{i}]" : "=r"({result_var}) : "w"(q{q}));'

def set_neon_at(position, value):
  q = position // 4
  i = position % 4
  return f'asm("mov %0.s[{i}], %w1" ::"w"(q{q}), "r"({value}));'

with open("_gen_block_read.c", "w") as f:
  for i in range(16):
    # print(f"BLOCK_READ_ITER({i}, w[{i}]);", file=f)
    # q = f"w[{i}]"
    print(f"""
    {{
      register uint32_t v = ((uint32_t*)input)[(block * 16) + {i}];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      {set_neon_at(i, 'v')};
    }}
    """, file=f)

with open("_gen_hash_body.c", "w") as f:
  for i in range(64):
    if (i >= 16):
      print(f"""{{
        asm(
          "mov %w0, %4.s[{(i-2)%4}]\\n\\t"
          "mov %w1, %5.s[{(i-7)%4}]\\n\\t"
          "mov %w2, %6.s[{(i-15)%4}]\\n\\t"
          "mov %w3, %7.s[{(i-16)%4}]\\n\\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q{(i-2)//4}),
            "w"(q{(i-7)//4}),
            "w"(q{(i-15)//4}),
            "w"(q{(i-16)//4})
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        {set_neon_at(i, 'wi')};
        }}""", file=f)
    else:
      # print(f"wi = w[{i}];", file=f)
      print(f"{get_neon_at(i, 'wi')};", file=f)
    print(f"""{{
      t1 = h + hash1(e) + choose(e, f, g) + {kPrimes[i]:#010x} + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }}""", file=f)
    # print(f"HASH_ITER({kPrimes[i]:#010x});", file=f)