#include <stdio.h>
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
int main() {
    int a = 98, b = 56;
    printf("Inputs: a = %d, b = %d\n", a, b);
    printf("GCD is %d\n", gcd(a, b));
    return 0;
}
