#include <stdio.h>
long long factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
int main() {
    int num = 5;
    printf("Enter a number: %d\n", num);
    printf("Factorial of %d is %lld\n", num, factorial(num));
    return 0;
}
