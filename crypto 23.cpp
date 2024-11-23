#include <stdio.h>
#include <string.h>

void xorStrings(char *a, char *b, char *result) {
    for (int i = 0; i < strlen(a); i++) {
        result[i] = (a[i] == b[i]) ? '0' : '1';
    }
    result[strlen(a)] = '\0';
}

void sdesEncrypt(char *input, char *key, char *output) {
    strcpy(output, input);
}

void ctrMode(char *plaintext, char *key, char *counter, char *output, int isEncrypt) {
    char counterCopy[9], xorResult[9], encryptedCounter[9];
    strcpy(counterCopy, counter);

    for (int i = 0; i < strlen(plaintext); i += 8) {
        char block[9];
        strncpy(block, plaintext + i, 8);
        block[8] = '\0';

        // Encrypt the counter using S-DES
        sdesEncrypt(counterCopy, key, encryptedCounter);

        // XOR the encrypted counter with the plaintext or ciphertext block
        xorStrings(block, encryptedCounter, xorResult);

        // Copy result to output
        strncpy(output + i, xorResult, 8);

        // Increment counter
        for (int j = 7; j >= 0; j--) {
            if (counterCopy[j] == '0') {
                counterCopy[j] = '1';
                break;
            } else {
                counterCopy[j] = '0';
            }
        }
    }
    output[strlen(plaintext)] = '\0';
}

int main() {
    char plaintext[128], key[11], counter[9], ciphertext[128], decrypted[128];

    printf("Enter binary plaintext: ");
    scanf("%s", plaintext);

    printf("Enter 10-bit binary key: ");
    scanf("%s", key);

    printf("Enter 8-bit binary counter: ");
    scanf("%s", counter);

    // Encrypt
    printf("Encrypting...\n");
    ctrMode(plaintext, key, counter, ciphertext, 1);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt
    printf("Decrypting...\n");
    ctrMode(ciphertext, key, counter, decrypted, 0);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
