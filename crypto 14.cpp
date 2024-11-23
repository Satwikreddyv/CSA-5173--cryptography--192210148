#include <stdio.h>
#include <string.h>

void encryptVigenere(char *plaintext, int key[], int keyLength) {
    int length = strlen(plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < length; i++) {
        int shift = key[i % keyLength];
        char encChar = ((plaintext[i] - 'a') + shift) % 26 + 'a';
        printf("%c", encChar);
    }
    printf("\n");
}

int main() {
    char plaintext[] = "sendmoremoney";
    int key[] = {3, 19, 5, 21, 14, 11, 11, 1, 2, 8};
    int keyLength = sizeof(key) / sizeof(key[0]);
    
    encryptVigenere(plaintext, key, keyLength);
    return 0;
}
