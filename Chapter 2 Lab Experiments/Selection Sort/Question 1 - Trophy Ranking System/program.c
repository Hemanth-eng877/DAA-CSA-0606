#include <stdio.h>
int main() {
    int scores[] = {85, 92, 78, 95, 88};
    int n = 5, comps = 0, swaps = 0;
    printf("Initial scores: 85 92 78 95 88\n");
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            comps++;
            if (scores[j] > scores[max_idx]) max_idx = j;
        }
        if (max_idx != i) {
            int temp = scores[max_idx];
            scores[max_idx] = scores[i];
            scores[i] = temp;
            swaps++;
        }
    }
    printf("Sorted for Trophies (Desc): ");
    for (int i = 0; i < n; i++) printf("%d ", scores[i]);
    printf("\nComparisons: %d, Swaps: %d\n", comps, swaps);
    return 0;
}
