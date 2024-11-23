#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void frequency_analysis(const char *ciphertext, int frequency[]) {
    for (int i = 0; i < 26; i++) frequency[i] = 0;
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            frequency[toupper(ciphertext[i]) - 'A']++;
        }
    }
}

void print_top_plaintexts(const char *ciphertext, const char *key) {
    printf("Possible plaintexts:\n");
    for (int shift = 0; shift < 10; shift++) {
        printf("%2d: ", shift);
        for (int i = 0; ciphertext[i] != '\0'; i++) {
            if (isalpha(ciphertext[i])) {
                char offset = isupper(ciphertext[i]) ? 'A' : 'a';
                printf("%c", (ciphertext[i] - offset - shift + 10) % 10 + offset);
            } else {
                printf("%c", ciphertext[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char ciphertext[MAX_LEN];
    printf("Enter ciphertext: ");
    fgets(ciphertext, MAX_LEN, stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';

    int frequency[26];
    frequency_analysis(ciphertext, frequency);

    printf("Letter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, frequency[i]);
    }

    print_top_plaintexts(ciphertext, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return 0;
}