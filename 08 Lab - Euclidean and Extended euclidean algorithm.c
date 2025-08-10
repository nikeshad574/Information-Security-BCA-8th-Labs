#include <stdio.h>

void print_euclidean_steps(int a, int b) {
    printf("Euclidean Algorithm Steps:\n");
    int temp_a = a;
    int temp_b = b;
    while (temp_b != 0) {
        printf("%d = %d * (%d / %d) + %d\n", temp_a, temp_b, temp_a, temp_b, temp_a % temp_b);
        int temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    printf("The GCD is %d\n", temp_a);
}

int extended_euclidean_recursive(int a, int b, int* x, int* y, int* level) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        printf("Step %d: Base case: %d = %d * (0) + %d * (1)\n", (*level)++, a, a, b);
        return b;
    }
    
    int x1, y1;
    int gcd = extended_euclidean_recursive(b % a, a, &x1, &y1, level);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    printf("Step %d: Working backward. Substituting coefficients:\n", (*level)++);
    printf("  GCD(%d, %d) = %d. Old combination: %d = %d * (%d) + %d * (%d)\n", a, b, gcd, gcd, x1, b % a, y1, a);
    printf("  New combination: %d = %d * (%d) + %d * (%d)\n", gcd, *x, a, *y, b);
    
    return gcd;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    print_euclidean_steps(num1, num2);

    int x, y;
    int level = 1;
    int gcd_extended = extended_euclidean_recursive(num1, num2, &x, &y, &level);
    
    printf("\nThe GCD is %d\n", gcd_extended);
    printf("The final linear combination is: %d * (%d) + %d * (%d) = %d\n", num1, x, num2, y, (num1 * x) + (num2 * y));

    printf("\nVerification:\n");
    if ((num1 * x) + (num2 * y) == gcd_extended) {
        printf("Verification successful! The equation holds true.\n");
    } else {
        printf("Verification failed. The equation does not hold true.\n");
    }

    return 0;
}
