#include <stdio.h>
#include <string.h>

void padPlaintext(char *plaintext, int blockSize) {
    int len = strlen(plaintext);
    int paddingNeeded = blockSize - (len % blockSize);

    for (int i = 0; i < paddingNeeded; i++) {
        plaintext[len + i] = (i == 0) ? '1' : '0';
    }
    plaintext[len + paddingNeeded] = '\0'; 
}

int main() {
    char plaintext[128];
    int blockSize;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter block size: ");
    scanf("%d", &blockSize);

    padPlaintext(plaintext, blockSize);
    printf("Padded plaintext: %s\n", plaintext);

    return 0;
}
