#include <stdio.h>
#include <math.h>

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
    long long p, g;
    long long a, b;
    long long A, B;
    long long S_alice, S_bob;

    printf("Step 1: Public Parameters\n");
    printf("Enter a large prime number p: ");
    scanf("%lld", &p);
    printf("Enter a primitive root g modulo p: ");
    scanf("%lld", &g);
    
    printf("\nPublicly known values are p = %lld and g = %lld.\n", p, g);

    printf("\nStep 2: Private Key Selection\n");
    printf("Alice, choose a private key a: ");
    scanf("%lld", &a);
    printf("Bob, choose a private key b: ");
    scanf("%lld", &b);
    
    A = power(g, a, p);
    printf("Alice computes her public key A = g^a mod p = %lld^%lld mod %lld = %lld\n", g, a, p, A);
    
    B = power(g, b, p);
    printf("Bob computes his public key B = g^b mod p = %lld^%lld mod %lld = %lld\n", g, b, p, B);

    printf("\nAlice sends A to Bob, and Bob sends B to Alice.\n");

    printf("\nStep 3: Compute Shared Secret\n");
    S_alice = power(B, a, p);
    printf("Alice computes the shared secret S = B^a mod p = %lld^%lld mod %lld = %lld\n", B, a, p, S_alice);

    S_bob = power(A, b, p);
    printf("Bob computes the shared secret S = A^b mod p = %lld^%lld mod %lld = %lld\n", A, b, p, S_bob);

    printf("\nBoth Alice and Bob have successfully computed the same shared secret: S = %lld\n", S_alice);

    return 0;
}
