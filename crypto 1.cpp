#include <stdio.h>
#include <string.h>
#include <ctype.h>
void caesarCipher(char* text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            text[i] = ((ch - 'A' + key) % 26) + 'A';
        }
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + key) % 26) + 'a';
        }
    }
}
int main() {
    char text[100];
    int key;
    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    do {
        printf("Enter the key (1-25): ");
        scanf("%d", &key);
    } while (key < 1 || key > 25);
    caesarCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}
