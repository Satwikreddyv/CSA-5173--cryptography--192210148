#include <stdio.h>
#include <stdint.h>

void generateSubkeys(uint64_t key) {
    for (int i = 0; i < 16; i++) {
        uint64_t subkey = (key >> (i * 4)) & 0xFFFFFF;
        printf("Subkey %d: %llX\n", i + 1, subkey);
    }
}

int main() {
    uint64_t key = 0x133457799BBCDFF1;
    generateSubkeys(key);

    return 0;
}
