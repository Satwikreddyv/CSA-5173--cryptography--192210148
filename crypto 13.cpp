#include <stdio.h>
#include <string.h>

#define MOD 26
void matrixMultiplication(int matrix[2][2], int vector[2], int result[2]) {
    result[0] = (matrix[0][0] * vector[0] + matrix[0][1] * vector[1]) % MOD;
    result[1] = (matrix[1][0] * vector[0] + matrix[1][1] * vector[1]) % MOD;
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}
void inverseMatrix(int matrix[2][2], int invMatrix[2][2]) {
    int det = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % MOD;
    int invDet = modInverse(det, MOD);

    if (invDet == -1) {
        printf("Matrix is not invertible\n");
        return;
    }

    invMatrix[0][0] = (matrix[1][1] * invDet) % MOD;
    invMatrix[0][1] = (-matrix[0][1] * invDet + MOD) % MOD;
    invMatrix[1][0] = (-matrix[1][0] * invDet + MOD) % MOD;
    invMatrix[1][1] = (matrix[0][0] * invDet) % MOD;
}

void decryptHillCipher(char *ciphertext, int invMatrix[2][2]) {
    int length = strlen(ciphertext);
    int vector[2], result[2];
    
    printf("Decrypted Plaintext: ");
    for (int i = 0; i < length; i += 2) {
        vector[0] = ciphertext[i] - 'a';
        vector[1] = ciphertext[i + 1] - 'a';
        matrixMultiplication(invMatrix, vector, result);
        printf("%c%c", result[0] + 'a', result[1] + 'a');
    }
    printf("\n");
}

int main() {
    char plaintext[100], ciphertext[100];
    
    printf("Enter the plaintext (even length): ");
    scanf("%s", plaintext);
    
    printf("Enter the ciphertext (even length): ");
    scanf("%s", ciphertext);
    
    int matrix[2][2];
    printf("Enter the 2x2 key matrix (as integers, 4 values):\n");
    scanf("%d %d %d %d", &matrix[0][0], &matrix[0][1], &matrix[1][0], &matrix[1][1]);
    
    int invMatrix[2][2];
    inverseMatrix(matrix, invMatrix);
    
    decryptHillCipher(ciphertext, invMatrix);
    
    return 0;
}
