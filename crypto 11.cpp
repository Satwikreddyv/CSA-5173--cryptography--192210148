#include <stdio.h>

#define MOD 26

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num_positions;

    printf("Enter the number of positions in the Playfair cipher matrix (usually 25): ");
    scanf("%d", &num_positions);
    long long total_keys = factorial(num_positions);
    printf("Total possible keys: %lld\n", total_keys);

    long long unique_keys = total_keys / 2;
    printf("Approximately unique keys: %lld\n", unique_keys);

    return 0;
}
