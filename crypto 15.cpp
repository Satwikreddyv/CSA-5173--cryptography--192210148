#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MOD 26
void generateKeyStream(int key[], int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % MOD;  
    }
}

void encryptVigenere(char *plaintext, int *key, int length) {
    printf("Encrypted text: ");
    for (int i = 0; i < length; i++) {
        int encryptedChar = (plaintext[i] - 'a' + key[i]) % MOD;
        printf("%c", encryptedChar + 'a');
    }
    printf("\n");
}

void decryptVigenere(char *ciphertext, int *key, int length) {
    printf("Decrypted text: ");
    for (int i = 0; i < length; i++) {
        int decryptedChar = (ciphertext[i] - 'a' - key[i] + MOD) % MOD;
        printf("%c", decryptedChar + 'a');
    }
    printf("\n");
}

int main() {
    char plaintext[100], ciphertext[100];
    int length, key[100];

    srand(time(NULL));

    printf("Enter the plaintext (lowercase letters only): ");
    scanf("%s", plaintext);

    length = strlen(plaintext);

    generateKeyStream(key, length);

    encryptVigenere(plaintext, key, length);

    printf("Key stream used for encryption (as shifts): ");
    for (int i = 0; i < length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    printf("Enter the ciphertext for decryption: ");
    scanf("%s", ciphertext);

    decryptVigenere(ciphertext, key, length);

    return 0;
}
