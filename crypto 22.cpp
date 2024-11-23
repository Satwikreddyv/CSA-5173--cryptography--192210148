#include <stdio.h>
#include <string.h>

void xorStrings(char *a, char *b, char *result) {
    for (int i = 0; i < strlen(a); i++) {
        result[i] = (a[i] == b[i]) ? '0' : '1';
    }
    result[strlen(a)] = '\0';
}

void sdesEncrypt(char *block, char *key, char *encryptedBlock) {
    strcpy(encryptedBlock, block);
}

void sdesDecrypt(char *block, char *key, char *decryptedBlock) {
    strcpy(decryptedBlock, block);
}

int main() {
    char plaintext[128], key[11], iv[9];
    char encrypted[128], decrypted[128];

    printf("Enter plaintext (binary): ");
    scanf("%s", plaintext);

    printf("Enter 10-bit key (binary): ");
    scanf("%s", key);

    printf("Enter 8-bit Initialization Vector (IV): ");
    scanf("%s", iv);

    printf("Encrypting using CBC mode...\n");
    char prevBlock[9];
    strcpy(prevBlock, iv);
    for (int i = 0; i < strlen(plaintext); i += 8) {
        char block[9], xorResult[9], encryptedBlock[9];
        strncpy(block, plaintext + i, 8);
        block[8] = '\0';

        xorStrings(block, prevBlock, xorResult);
        sdesEncrypt(xorResult, key, encryptedBlock);
        strncpy(encrypted + i, encryptedBlock, 8);
        strcpy(prevBlock, encryptedBlock);
    }
    encrypted[strlen(plaintext)] = '\0';
    printf("Encrypted text: %s\n", encrypted);

    printf("Decrypting...\n");
    strcpy(prevBlock, iv);
    for (int i = 0; i < strlen(encrypted); i += 8) {
        char encryptedBlock[9], decryptedBlock[9], xorResult[9];
        strncpy(encryptedBlock, encrypted + i, 8);
        encryptedBlock[8] = '\0';

        sdesDecrypt(encryptedBlock, key, xorResult);
        xorStrings(xorResult, prevBlock, decryptedBlock);
        strncpy(decrypted + i, decryptedBlock, 8);
        strcpy(prevBlock, encryptedBlock);
    }
    decrypted[strlen(encrypted)] = '\0';
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
