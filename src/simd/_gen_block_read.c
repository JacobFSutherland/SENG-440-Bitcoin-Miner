
    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 0];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[0], %w1" ::"w"(q0), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 1];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[1], %w1" ::"w"(q0), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 2];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[2], %w1" ::"w"(q0), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 3];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[3], %w1" ::"w"(q0), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 4];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[0], %w1" ::"w"(q1), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 5];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[1], %w1" ::"w"(q1), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 6];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[2], %w1" ::"w"(q1), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 7];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[3], %w1" ::"w"(q1), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 8];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[0], %w1" ::"w"(q2), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 9];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[1], %w1" ::"w"(q2), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 10];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[2], %w1" ::"w"(q2), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 11];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[3], %w1" ::"w"(q2), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 12];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[0], %w1" ::"w"(q3), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 13];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[1], %w1" ::"w"(q3), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 14];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[2], %w1" ::"w"(q3), "r"(v));;
    }
    

    {
      register uint32_t v = ((uint32_t*)input)[(block * 16) + 15];
      asm("rev32 %[v], %[v]" : [v] "+r"(v));
      asm("mov %0.s[3], %w1" ::"w"(q3), "r"(v));;
    }
    
