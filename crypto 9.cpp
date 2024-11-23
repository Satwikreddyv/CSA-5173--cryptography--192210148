#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareMatrix(const char *keyword, char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    used['J' - 'A'] = 1;
    int row = 0, col = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char c = toupper(keyword[i]);
        if (!used[c - 'A']) {
            matrix[row][col++] = c;
            used[c - 'A'] = 1;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            matrix[row][col++] = c;
            used[c - 'A'] = 1;
            if (col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
}
void findPosition(char c, char matrix[SIZE][SIZE], int *row, int *col) {
    if (c == 'J') c = 'I';
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

void decryptPair(char a, char b, char matrix[SIZE][SIZE], char *decryptedPair) {
    int row1, col1, row2, col2;
    findPosition(a, matrix, &row1, &col1);
    findPosition(b, matrix, &row2, &col2);

    if (row1 == row2) {
        decryptedPair[0] = matrix[row1][(col1 + SIZE - 1) % SIZE];
        decryptedPair[1] = matrix[row2][(col2 + SIZE - 1) % SIZE];
    } else if (col1 == col2) {
        decryptedPair[0] = matrix[(row1 + SIZE - 1) % SIZE][col1];
        decryptedPair[1] = matrix[(row2 + SIZE - 1) % SIZE][col2];
    } else {
        decryptedPair[0] = matrix[row1][col2];
        decryptedPair[1] = matrix[row2][col1];
    }
}

void decryptPlayfair(const char *ciphertext, char *plaintext, char matrix[SIZE][SIZE]) {
    int len = strlen(ciphertext);
    char decryptedPair[2];
    int plainIndex = 0;

    for (int i = 0; i < len; i += 2) {
        decryptPair(ciphertext[i], ciphertext[i + 1], matrix, decryptedPair);
        plaintext[plainIndex++] = decryptedPair[0];
        plaintext[plainIndex++] = decryptedPair[1];
    }
    plaintext[plainIndex] = '\0';
}

int main() {
    char keyword[] = "PLAYFAIR";
    char matrix[SIZE][SIZE];
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWITTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char plaintext[256];
    prepareMatrix(keyword, matrix);
    printf("Playfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    decryptPlayfair(ciphertext, plaintext, matrix);
    printf("\nCiphertext: %s\n", ciphertext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}
