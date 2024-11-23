#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modularInverse(int a, int mod) {
    for (int i = 1; i < mod; i++) {
        if ((a * i) % mod == 1) {
            return i;
        }
    }
    return -1;
}
void affineEncrypt(char* plaintext, char* ciphertext, int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ciphertext[i] = ((a * (ch - base) + b) % 26) + base;
        } else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void affineDecrypt(char* ciphertext, char* plaintext, int a, int b) {
    int a_inverse = modularInverse(a, 26);
    if (a_inverse == -1) {
        printf("Error: 'a' has no modular inverse, decryption is impossible.\n");
        return;
    }
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            plaintext[i] = (a_inverse * ((ch - base - b + 26) % 26) % 26) + base;
        } else {
            plaintext[i] = ch;
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main() {
    char plaintext[100], ciphertext[100], decryptedText[100];
    int a, b;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1) {
        printf("Error: 'a' must be coprime with 26.\n");
        return 1;
    }
    affineEncrypt(plaintext, ciphertext, a, b);
    printf("Encrypted text: %s\n", ciphertext);
    affineDecrypt(ciphertext, decryptedText, a, b);
    printf("Decrypted text: %s\n", decryptedText);
    return 0;
}
