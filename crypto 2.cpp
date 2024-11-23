#include <stdio.h>
#include <string.h>
#include <ctype.h>
void substitutionCipher(char* plaintext, char* key, char* ciphertext) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isupper(ch)) {
            int index = ch - 'A';
            ciphertext[i] = key[index];
        }
        else if (islower(ch)) {
            int index = ch - 'a';
            ciphertext[i] = tolower(key[index]);
        }
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() {
    char plaintext[100];
    char key[27];
    char ciphertext[100];
    printf("Enter the text to be encrypted: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }
    printf("Enter the substitution key (26 unique uppercase letters): ");
    scanf("%s", key);
    if (strlen(key) != 26) {
        printf("Error: Key must contain exactly 26 letters.\n");
        return 1;
    }
    int letterCount[26] = {0};
    for (int i = 0; i < 26; i++) {
        if (!isupper(key[i])) {
            printf("Error: Key must contain only uppercase letters.\n");
            return 1;
        }
        int index = key[i] - 'A';
        letterCount[index]++;
        if (letterCount[index] > 1) {
            printf("Error: Key must contain unique letters.\n");
            return 1;
        }
    }
    substitutionCipher(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    return 0;
}
