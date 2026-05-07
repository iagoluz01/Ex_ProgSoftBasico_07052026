#include <stdio.h>

// 1. Zera todos os bits
unsigned int clear(unsigned int val) {
    return 0; // Or val & 0
}

// 2. Seta um único bit
unsigned int setbit(unsigned int x, int bit) {
    return x | (1U << bit);
}

// 3. Resseta um único bit
unsigned int clearbit(unsigned int x, int bit) {
    return x & ~(1U << bit);
}

// 4. Inverte o valor de um único bit
unsigned int invertBit(unsigned int x, int bit) {
    return x ^ (1U << bit);
}

// 5. Retorna o estado de um determinado bit (retorna 0 ou 1)
int testBit(unsigned int x, int bit) {
    return (x >> bit) & 1;
}

int main() {
    unsigned int test_val = 0x0000000F; // 15 in decimal, binary: ...00001111
    int bit_to_modify = 4; // 5th bit (0-indexed)

    printf("=== Testando as funcoes de bit ===\n\n");
    printf("Valor original: 0x%08X (%u)\n", test_val, test_val);

    // 1. clear
    printf("1. clear(0x%08X) = 0x%08X\n", test_val, clear(test_val));

    // 2. setbit
    printf("2. setbit(0x%08X, %d) = 0x%08X\n", test_val, bit_to_modify, setbit(test_val, bit_to_modify));

    // 3. clearbit (let's clear bit 0 which is currently 1)
    printf("3. clearbit(0x%08X, 0) = 0x%08X\n", test_val, clearbit(test_val, 0));

    // 4. invertBit (invert bit 0 and bit 4)
    printf("4. invertBit(0x%08X, 0) = 0x%08X\n", test_val, invertBit(test_val, 0));
    printf("   invertBit(0x%08X, %d) = 0x%08X\n", test_val, bit_to_modify, invertBit(test_val, bit_to_modify));

    // 5. testBit
    printf("5. testBit(0x%08X, 0) = %d\n", test_val, testBit(test_val, 0));
    printf("   testBit(0x%08X, %d) = %d\n", test_val, bit_to_modify, testBit(test_val, bit_to_modify));

    return 0;
}
