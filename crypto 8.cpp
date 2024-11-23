#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_LENGTH 26
void generateCipherSequence(const char *keyword, char cipher[ALPHABET_LENGTH]) {
    int used[ALPHABET_LENGTH] = {0};
    int index = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char c = toupper(keyword[i]);
        if (!used[c - 'A']) {
            cipher[index++] = c;
            used[c - 'A'] = 1;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            cipher[index++] = c;
        }
    }
    cipher[index] = '\0';
}
void encrypt(const char *plaintext, const char *cipher, char *encrypted) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            encrypted[i] = cipher[toupper(plaintext[i]) - 'A'];
            if (islower(plaintext[i])) {
                encrypted[i] = tolower(encrypted[i]);
            }
        } else {
            encrypted[i] = plaintext[i];
        }
    }
    encrypted[strlen(plaintext)] = '\0';
}

void decrypt(const char *ciphertext, const char *cipher, char *decrypted) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            for (int j = 0; j < ALPHABET_LENGTH; j++) {
                if (toupper(ciphertext[i]) == cipher[j]) {
                    decrypted[i] = j + base;
                    if (islower(ciphertext[i])) {
                        decrypted[i] = tolower(decrypted[i]);
                    }
                    break;
                }
            }
        } else {
            decrypted[i] = ciphertext[i];
        }
    }
    decrypted[strlen(ciphertext)] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char cipher[ALPHABET_LENGTH + 1];
    char plaintext[256], encrypted[256], decrypted[256];
    generateCipherSequence(keyword, cipher);
    printf("Keyword: %s\n", keyword);
    printf("Cipher Sequence: %s\n", cipher);
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    encrypt(plaintext, cipher, encrypted);
    printf("Encrypted Text: %s\n", encrypted);
    decrypt(encrypted, cipher, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
