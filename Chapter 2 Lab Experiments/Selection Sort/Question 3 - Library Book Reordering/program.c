#include <stdio.h>
struct Book { int isbn; };
int main() {
    struct Book books[] = {{104}, {101}, {105}, {102}, {103}};
    int n = 5, comps = 0, swaps = 0;
    printf("Unordered ISBNs: 104 101 105 102 103\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comps++;
            if (books[j].isbn < books[min_idx].isbn) min_idx = j;
        }
        if (min_idx != i) {
            struct Book temp = books[min_idx];
            books[min_idx] = books[i];
            books[i] = temp;
            swaps++;
        }
    }
    printf("Ordered ISBNs: ");
    for (int i = 0; i < n; i++) printf("%d ", books[i].isbn);
    printf("\nComparisons: %d, Swaps: %d\n", comps, swaps);
    return 0;
}
