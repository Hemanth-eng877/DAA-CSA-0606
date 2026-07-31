#include <stdio.h>
long long power(int base, int exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}
int main() {
    int base = 2, exp = 10;
    printf("Base: %d, Exponent: %d\n", base, exp);
    printf("Result: %lld\n", power(base, exp));
    return 0;
}
