#include <stdio.h>
int main() {
    int data[] = {45, 12, 78, 34, 23};
    int n = 5, swaps = 0;
    printf("Embedded Data: 45 12 78 34 23\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            data[min_idx] ^= data[i];
            data[i] ^= data[min_idx];
            data[min_idx] ^= data[i];
            swaps++;
        }
    }
    printf("Sorted In-Place: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\nSwaps: %d\n", swaps);
    return 0;
}
