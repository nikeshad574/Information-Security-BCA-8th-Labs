#include <stdio.h>

// Function to compute (base^exp) % mod
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
    long long n;
    long long e, d;
    long long M, C;

    printf("RSA Key Exchange and Operations\n");
    printf("----------------------------------\n");
    printf("Enter the public key modulus n: ");
    scanf("%lld", &n);
    printf("Enter the public encryption exponent e: ");
    scanf("%lld", &e);
    printf("Enter the private decryption exponent d: ");
    scanf("%lld", &d);

    printf("\nPublic Key (e, n): (%lld, %lld)\n", e, n);
    printf("Private Key (d, n): (%lld, %lld)\n", d, n);

    printf("\nRSA Encryption\n");
    printf("----------------------------------\n");
    printf("Enter a numeric plaintext M: ");
    scanf("%lld", &M);
    
    C = power(M, e, n);
    printf("Ciphertext C = M^e mod n = %lld\n", C);

    printf("\nRSA Decryption\n");
    printf("----------------------------------\n");
    M = power(C, d, n);
    printf("Decrypted plaintext M = C^d mod n = %lld\n", M);

    return 0;
}
