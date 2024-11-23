#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
char matrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'J'},
    {'K', 'U', 'N', 'O', 'P'},
    {'Q', 'Z', 'V', 'W', 'X'},
    {'Y', 'E', 'L', 'A', 'R'},
    {'G', 'D', 'S', 'T', 'B'}
};

void findPosition(char c, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void preprocessPlaintext(const char *input, char *output) {
    int len = strlen(input);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            char c = toupper(input[i]);

            if (j > 0 && c == output[j - 1]) {
                output[j++] = 'X';
            }
            output[j++] = c;
        }
    }

    if (j % 2 != 0) {
        output[j++] = 'X';
    }
    output[j] = '\0';
}

void encryptPair(char a, char b, char *encryptedPair) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);

    if (row1 == row2) {
        encryptedPair[0] = matrix[row1][(col1 + 1) % SIZE];
        encryptedPair[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        encryptedPair[0] = matrix[(row1 + 1) % SIZE][col1];
        encryptedPair[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        encryptedPair[0] = matrix[row1][col2];
        encryptedPair[1] = matrix[row2][col1];
    }
}
void encryptPlayfair(const char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    int index = 0;

    for (int i = 0; i < len; i += 2) {
        char encryptedPair[2];
        encryptPair(plaintext[i], plaintext[i + 1], encryptedPair);
        ciphertext[index++] = encryptedPair[0];
        ciphertext[index++] = encryptedPair[1];
    }
    ciphertext[index] = '\0';
}

int main() {
    char plaintext[256];
    char processedText[256];
    char ciphertext[256];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    preprocessPlaintext(plaintext, processedText);
    encryptPlayfair(processedText, ciphertext);
    printf("\nPlayfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nProcessed Plaintext: %s\n", processedText);
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    return 0;
}
