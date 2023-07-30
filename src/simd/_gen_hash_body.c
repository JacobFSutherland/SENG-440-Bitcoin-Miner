asm("mov %w0, %1.s[0]" : "=r"(wi) : "w"(q0));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x428a2f98 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[1]" : "=r"(wi) : "w"(q0));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x71374491 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[2]" : "=r"(wi) : "w"(q0));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xb5c0fbcf + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[3]" : "=r"(wi) : "w"(q0));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xe9b5dba5 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[0]" : "=r"(wi) : "w"(q1));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x3956c25b + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[1]" : "=r"(wi) : "w"(q1));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x59f111f1 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[2]" : "=r"(wi) : "w"(q1));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x923f82a4 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[3]" : "=r"(wi) : "w"(q1));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xab1c5ed5 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[0]" : "=r"(wi) : "w"(q2));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xd807aa98 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[1]" : "=r"(wi) : "w"(q2));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x12835b01 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[2]" : "=r"(wi) : "w"(q2));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x243185be + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[3]" : "=r"(wi) : "w"(q2));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x550c7dc3 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[0]" : "=r"(wi) : "w"(q3));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x72be5d74 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[1]" : "=r"(wi) : "w"(q3));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x80deb1fe + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[2]" : "=r"(wi) : "w"(q3));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x9bdc06a7 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
asm("mov %w0, %1.s[3]" : "=r"(wi) : "w"(q3));;
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xc19bf174 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q3),
            "w"(q2),
            "w"(q0),
            "w"(q0)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q4), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xe49b69c1 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q3),
            "w"(q2),
            "w"(q0),
            "w"(q0)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q4), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xefbe4786 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q4),
            "w"(q2),
            "w"(q0),
            "w"(q0)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q4), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x0fc19dc6 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q4),
            "w"(q3),
            "w"(q1),
            "w"(q0)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q4), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x240ca1cc + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q4),
            "w"(q3),
            "w"(q1),
            "w"(q1)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q5), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x2de92c6f + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q4),
            "w"(q3),
            "w"(q1),
            "w"(q1)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q5), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x4a7484aa + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q5),
            "w"(q3),
            "w"(q1),
            "w"(q1)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q5), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x5cb0a9dc + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q5),
            "w"(q4),
            "w"(q2),
            "w"(q1)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q5), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x76f988da + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q5),
            "w"(q4),
            "w"(q2),
            "w"(q2)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q6), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x983e5152 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q5),
            "w"(q4),
            "w"(q2),
            "w"(q2)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q6), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xa831c66d + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q6),
            "w"(q4),
            "w"(q2),
            "w"(q2)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q6), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xb00327c8 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q6),
            "w"(q5),
            "w"(q3),
            "w"(q2)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q6), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xbf597fc7 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q6),
            "w"(q5),
            "w"(q3),
            "w"(q3)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q7), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xc6e00bf3 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q6),
            "w"(q5),
            "w"(q3),
            "w"(q3)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q7), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xd5a79147 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q7),
            "w"(q5),
            "w"(q3),
            "w"(q3)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q7), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x06ca6351 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q7),
            "w"(q6),
            "w"(q4),
            "w"(q3)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q7), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x14292967 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q7),
            "w"(q6),
            "w"(q4),
            "w"(q4)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q8), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x27b70a85 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q7),
            "w"(q6),
            "w"(q4),
            "w"(q4)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q8), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x2e1b2138 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q8),
            "w"(q6),
            "w"(q4),
            "w"(q4)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q8), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x4d2c6dfc + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q8),
            "w"(q7),
            "w"(q5),
            "w"(q4)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q8), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x53380d13 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q8),
            "w"(q7),
            "w"(q5),
            "w"(q5)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q9), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x650a7354 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q8),
            "w"(q7),
            "w"(q5),
            "w"(q5)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q9), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x766a0abb + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q9),
            "w"(q7),
            "w"(q5),
            "w"(q5)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q9), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x81c2c92e + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q9),
            "w"(q8),
            "w"(q6),
            "w"(q5)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q9), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x92722c85 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q9),
            "w"(q8),
            "w"(q6),
            "w"(q6)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q10), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xa2bfe8a1 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q9),
            "w"(q8),
            "w"(q6),
            "w"(q6)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q10), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xa81a664b + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q10),
            "w"(q8),
            "w"(q6),
            "w"(q6)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q10), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xc24b8b70 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q10),
            "w"(q9),
            "w"(q7),
            "w"(q6)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q10), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xc76c51a3 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q10),
            "w"(q9),
            "w"(q7),
            "w"(q7)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q11), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xd192e819 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q10),
            "w"(q9),
            "w"(q7),
            "w"(q7)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q11), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xd6990624 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q11),
            "w"(q9),
            "w"(q7),
            "w"(q7)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q11), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xf40e3585 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q11),
            "w"(q10),
            "w"(q8),
            "w"(q7)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q11), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x106aa070 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q11),
            "w"(q10),
            "w"(q8),
            "w"(q8)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q12), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x19a4c116 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q11),
            "w"(q10),
            "w"(q8),
            "w"(q8)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q12), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x1e376c08 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q12),
            "w"(q10),
            "w"(q8),
            "w"(q8)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q12), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x2748774c + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q12),
            "w"(q11),
            "w"(q9),
            "w"(q8)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q12), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x34b0bcb5 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q12),
            "w"(q11),
            "w"(q9),
            "w"(q9)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q13), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x391c0cb3 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q12),
            "w"(q11),
            "w"(q9),
            "w"(q9)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q13), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x4ed8aa4a + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q13),
            "w"(q11),
            "w"(q9),
            "w"(q9)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q13), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x5b9cca4f + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q13),
            "w"(q12),
            "w"(q10),
            "w"(q9)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q13), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x682e6ff3 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q13),
            "w"(q12),
            "w"(q10),
            "w"(q10)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q14), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x748f82ee + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q13),
            "w"(q12),
            "w"(q10),
            "w"(q10)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q14), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x78a5636f + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q14),
            "w"(q12),
            "w"(q10),
            "w"(q10)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q14), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x84c87814 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q14),
            "w"(q13),
            "w"(q11),
            "w"(q10)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q14), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x8cc70208 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[2]\n\t"
          "mov %w1, %5.s[1]\n\t"
          "mov %w2, %6.s[1]\n\t"
          "mov %w3, %7.s[0]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q14),
            "w"(q13),
            "w"(q11),
            "w"(q11)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[0], %w1" ::"w"(q15), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0x90befffa + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[3]\n\t"
          "mov %w1, %5.s[2]\n\t"
          "mov %w2, %6.s[2]\n\t"
          "mov %w3, %7.s[1]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q14),
            "w"(q13),
            "w"(q11),
            "w"(q11)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[1], %w1" ::"w"(q15), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xa4506ceb + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[0]\n\t"
          "mov %w1, %5.s[3]\n\t"
          "mov %w2, %6.s[3]\n\t"
          "mov %w3, %7.s[2]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q15),
            "w"(q13),
            "w"(q11),
            "w"(q11)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[2], %w1" ::"w"(q15), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xbef9a3f7 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
{
        asm(
          "mov %w0, %4.s[1]\n\t"
          "mov %w1, %5.s[0]\n\t"
          "mov %w2, %6.s[0]\n\t"
          "mov %w3, %7.s[3]\n\t"
          : "=r"(w2),
            "=r"(w7),
            "=r"(w15),
            "=r"(w16)
          : "w"(q15),
            "w"(q14),
            "w"(q12),
            "w"(q11)
        );
        wi = expand1(w2) + w7 + expand0(w15) + w16;
        asm("mov %0.s[3], %w1" ::"w"(q15), "r"(wi));;
        }
{
      t1 = h + hash1(e) + choose(e, f, g) + 0xc67178f2 + wi;
      t2 = hash0(a) + majority(a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }
