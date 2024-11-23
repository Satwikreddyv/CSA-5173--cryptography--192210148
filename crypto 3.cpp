#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void constructMatrix(char key[], char matrix[SIZE][SIZE]);
void findPosition(char matrix[SIZE][SIZE], char ch, int* row, int* col);
void encryptPair(char matrix[SIZE][SIZE], char* first, char* second);
void prepareText(char* text);
void constructMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    used['J' - 'A'] = 1;
    int k = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (!used[ch - 'A'] && isalpha(ch)) {
            matrix[k / SIZE][k % SIZE] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / SIZE][k % SIZE] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}
void findPosition(char matrix[SIZE][SIZE], char ch, int* row, int* col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptPair(char matrix[SIZE][SIZE], char* first, char* second) {
    int r1, c1, r2, c2;
    findPosition(matrix, *first, &r1, &c1);
    findPosition(matrix, *second, &r2, &c2);
    if (r1 == r2) {
        *first = matrix[r1][(c1 + 1) % SIZE];
        *second = matrix[r2][(c2 + 1) % SIZE];
    } else if (c1 == c2) {
        *first = matrix[(r1 + 1) % SIZE][c1];
        *second = matrix[(r2 + 1) % SIZE][c2];
    } else {
        *first = matrix[r1][c2];
        *second = matrix[r2][c1];
    }
}
void prepareText(char* text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        text[i] = toupper(text[i]);
        if (text[i] == 'J') text[i] = 'I'; 
    }
    char prepared[100];
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            prepared[k++] = text[i];
            if (i + 1 < len && text[i] == text[i + 1]) {
                prepared[k++] = 'X';
            }
        }
    }
    if (k % 2 != 0) {
        prepared[k++] = 'X';
    }
    prepared[k] = '\0';
    strcpy(text, prepared);
}
int main() {
    char key[100], plaintext[100];
    char matrix[SIZE][SIZE];
    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    prepareText(plaintext);
    constructMatrix(key, matrix);
    printf("\nPlayfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; plaintext[i] != '\0'; i += 2) {
        encryptPair(matrix, &plaintext[i], &plaintext[i + 1]);
    }
    printf("\nEncrypted text: %s\n", plaintext);
    return 0;
}
