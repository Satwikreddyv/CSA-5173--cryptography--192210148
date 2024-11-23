#include <stdio.h>
#include <stdint.h>

void generateKeys(uint64_t key, uint64_t keys[16]) {
    for (int i = 0; i < 16; i++) {
        keys[i] = (key >> i) & 0xFFFFFFFFFFFFFF;
    }
}

void desDecrypt(uint64_t ciphertext, uint64_t keys[16]) {
    uint64_t decrypted = ciphertext;
    for (int i = 15; i >= 0; i--) {
        decrypted ^= keys[i];
    }
    printf("Decrypted Plaintext: %llX\n", decrypted);
}

int main() {
    uint64_t key = 0x133457799BBCDFF1;
    uint64_t ciphertext = 0x85E813540F0AB405;
    uint64_t keys[16];

    generateKeys(key, keys);
    desDecrypt(ciphertext, keys);

    return 0;
}
