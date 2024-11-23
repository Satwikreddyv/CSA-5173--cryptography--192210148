#include <stdio.h>
#include <stdint.h>

void simulateError(uint64_t ciphertext1, uint64_t ciphertext2) {
    uint64_t errorBlock = ciphertext1 ^ 0x1; // Simulate 1-bit error
    printf("Corrupted Block 1: %llX\n", errorBlock);
    printf("Block 2 remains unaffected: %llX\n", ciphertext2);
}

int main() {
    uint64_t block1 = 0x123456789ABCDEF;
    uint64_t block2 = 0xFEDCBA987654321;

    printf("Simulating error in ECB mode...\n");
    simulateError(block1, block2);

    return 0;
}
