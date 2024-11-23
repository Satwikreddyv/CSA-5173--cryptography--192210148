#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000

void countFrequency(const char *ciphertext, int freq[256]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isprint(ciphertext[i])) {
            freq[(unsigned char)ciphertext[i]]++;
        }
    }
}

void displayFrequency(const int freq[256]) {
    printf("Character Frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && isprint(i)) {
            printf("'%c': %d\n", i, freq[i]);
        }
    }
}
void decryptMessage(const char *ciphertext, const char substitution[256]) {
    printf("\nDecrypted Message:\n");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        if (isprint(c) && substitution[(unsigned char)c] != '\0') {
            printf("%c", substitution[(unsigned char)c]);
        } else {
            printf("%c", c); // Print unchanged if no substitution
        }
    }
    printf("\n");
}

int main() {
    const char ciphertext[] = "531305))6:4826)41.)41):806*;48+8560))85;;]8*;::8+83 (88)5*4:46(:88*96*7:8)(;485);5*12:*(:4956*2(54)858 4069285);)6+8)41:1(19:480818:811:48+85;4)4851528806*81 (19:48:(88;4(1734:48)41;161;188;12;";
        int freq[256] = {0};
    countFrequency(ciphertext, freq);
    displayFrequency(freq);
    char substitution[256] = {0};
    substitution['5'] = 'e';
    substitution['3'] = 't';
    substitution['1'] = 'h';
    substitution['0'] = 'o';
    substitution['6'] = 'a';
    substitution['4'] = 'r';
    substitution['8'] = 'i';
    substitution[':'] = 'n';
    substitution[')'] = 's';
    substitution['*'] = 'd';
    substitution[';'] = 'l';
    substitution['+'] = 'u';
    decryptMessage(ciphertext, substitution);

    return 0;
}
