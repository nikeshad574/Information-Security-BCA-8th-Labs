#include <stdio.h>
#include <string.h>

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    long long n, e, d;
    char msg[100];
    
    printf("Enter n: ");
    scanf("%lld", &n);
    printf("Enter e: ");
    scanf("%lld", &e);
    printf("Enter d: ");
    scanf("%lld", &d);

    printf("\nEnter message (text): ");
    scanf("%s", msg);

    int len = strlen(msg);
    long long encrypted[100];
    char decrypted[100];

    for (int i = 0; i < len; i++) {
        encrypted[i] = power((long long)msg[i], e, n);
    }

    printf("\nEncrypted message: ");
    for (int i = 0; i < len; i++) {
        printf("%lld ", encrypted[i]);
    }

    for (int i = 0; i < len; i++) {
        decrypted[i] = (char)power(encrypted[i], d, n);
    }
    decrypted[len] = '\0';

    printf("\nDecrypted message: %s\n", decrypted);

    return 0;
}
