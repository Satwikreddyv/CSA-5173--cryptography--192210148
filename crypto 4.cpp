#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char* plaintext, char* key, char* ciphertext) {
    int keyLen = strlen(key);
    int textLen = strlen(plaintext);
    for (int i = 0, j = 0; i < textLen; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int keyShift = toupper(key[j % keyLen]) - 'A';
            ciphertext[i] = ((ch - base + keyShift) % 26) + base;
            j++;
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[textLen] = '\0';
}
int main() {
    char plaintext[100], key[100], ciphertext[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key must contain only alphabetic characters.\n");
            return 1;
        }
    }
    vigenereEncrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    return 0;
}
