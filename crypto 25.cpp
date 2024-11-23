#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int e, int phi) {
    int t = 0, newT = 1;
    int r = phi, newR = e;

    while (newR != 0) {
        int quotient = r / newR;
        int temp = t;
        t = newT;
        newT = temp - quotient * newT;

        temp = r;
        r = newR;
        newR = temp - quotient * newR;
    }

    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int n, e, plaintext;

    printf("Enter RSA modulus (n): ");
    scanf("%d", &n);

    printf("Enter public key exponent (e): ");
    scanf("%d", &e);

    printf("Enter a plaintext block: ");
    scanf("%d", &plaintext);

    int factor = gcd(plaintext, n);
    if (factor > 1) {
        printf("Common factor found: %d\n", factor);

        int p = factor;
        int q = n / factor;
        printf("Factorization of n: p = %d, q = %d\n", p, q);

        int phi = (p - 1) * (q - 1);
        printf("Euler's Totient (f): %d\n", phi);

        int d = modInverse(e, phi);
        if (d == -1) {
            printf("Failed to calculate modular inverse. No private key found.\n");
            return 1;
        }
        printf("Private key (d): %d\n", d);

        int message;
        printf("Enter a message to encrypt: ");
        scanf("%d", &message);

        int encrypted = modExp(message, e, n);
        printf("Encrypted message: %d\n", encrypted);

        int decrypted = modExp(encrypted, d, n);
        printf("Decrypted message: %d\n", decrypted);
    } else {
        printf("No common factor found between the plaintext block and n.\n");
    }

    return 0;
}
