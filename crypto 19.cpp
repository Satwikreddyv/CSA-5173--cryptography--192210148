#include <stdio.h>
#include <stdint.h>

void cbcEncrypt(uint64_t plaintext, uint64_t key1, uint64_t key2, uint64_t iv) {
    uint64_t ciphertext = plaintext ^ iv;
    ciphertext ^= key1;
    ciphertext ^= key2;

    printf("Ciphertext: %llX\n", ciphertext);
}

int main() {
    uint64_t plaintext = 0x123456789ABCDEF;
    uint64_t key1 = 0x133457799BBCDFF1;
    uint64_t key2 = 0x123456789ABCDEF0;
    uint64_t iv = 0xAABBCCDDEEFF0011;

    cbcEncrypt(plaintext, key1, key2, iv);

    return 0;
}
