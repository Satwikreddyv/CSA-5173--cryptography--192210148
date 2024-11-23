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
    int e = 31, n = 3599, p, q, phi, d, message, encrypted, decrypted;

    for (p = 2; p < n; p++) {
        if (n % p == 0) {
            q = n / p;
            break;
        }
    }

    phi = (p - 1) * (q - 1);
    d = modInverse(e, phi);

    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);

    printf("Enter a message (as integer): ");
    scanf("%d", &message);

    // Encrypt and decrypt
    encrypted = modExp(message, e, n);
    decrypted = modExp(encrypted, d, n);

    printf("Encrypted message: %d\n", encrypted);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}
