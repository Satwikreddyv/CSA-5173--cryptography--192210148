#include <stdio.h>
#include <string.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void decryptAffine(const char *ciphertext, int a, int b, char *plaintext) {
    int a_inverse = modInverse(a, 26);
    if (a_inverse == -1) {
        printf("Error: 'a' has no modular inverse under 26.\n");
        return;
    }

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int C = ciphertext[i] - 'A';
            int P = (a_inverse * (C - b + 26)) % 26;
            plaintext[i] = P + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[] = "YOUR_CIPHERTEXT_HERE"; 
    char plaintext[256];
    int a, b;

    char cipherMostFreq = 'B';
    char cipherSecondFreq = 'U';
    char plainMostFreq = 'E';
    char plainSecondFreq = 'T'; 

    int c1 = cipherMostFreq - 'A';
    int p1 = plainMostFreq - 'A';
    int c2 = cipherSecondFreq - 'A';
    int p2 = plainSecondFreq - 'A';

    int deltaP = (p1 - p2 + 26) % 26; 
    int deltaC = (c1 - c2 + 26) % 26; 

    a = (deltaC * modInverse(deltaP, 26)) % 26;
    if (a < 0) a += 26;

    b = (c1 - a * p1 + 26) % 26;
    if (b < 0) b += 26;

    printf("Decryption key: a = %d, b = %d\n", a, b);

    decryptAffine(ciphertext, a, b, plaintext);

    printf("Decrypted Plaintext: %s\n", plaintext);

    return 0;
}
