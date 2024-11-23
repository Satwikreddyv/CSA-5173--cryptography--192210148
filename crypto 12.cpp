#include <stdio.h>
#include <string.h>

#define MOD 26

void matrixMultiplication(int key[2][2], int message[2], int result[2]) {
    result[0] = (key[0][0] * message[0] + key[0][1] * message[1]) % MOD;
    result[1] = (key[1][0] * message[0] + key[1][1] * message[1]) % MOD;
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

void hillCipher(char *plaintext, int key[2][2]) {
    int length = strlen(plaintext);
    int message[2], result[2];
    
    printf("Ciphertext: ");
    for (int i = 0; i < length; i += 2) {
        message[0] = plaintext[i] - 'a';
        message[1] = plaintext[i + 1] - 'a';
        matrixMultiplication(key, message, result);
        printf("%c%c", result[0] + 'a', result[1] + 'a');
    }
    printf("\n");
}

int main() {
    char plaintext[] = "meetmeattheusualplaceattenratherthaneight";
    int key[2][2] = {{9, 4}, {5, 7}};
    
    hillCipher(plaintext, key);
    return 0;
}
