#include <stdio.h>
#include <time.h>
int main() {
    int logs[] = {1, 2, 3, 5, 4, 6}; // Only 5 and 4 are out of order
    int n = 6, shifts = 0;
    clock_t start = clock();
    printf("Nearly Sorted Logs: 1 2 3 5 4 6\n");
    for (int i = 1; i < n; i++) {
        int key = logs[i];
        int j = i - 1;
        while (j >= 0 && logs[j] > key) {
            logs[j + 1] = logs[j];
            shifts++;
            j = j - 1;
        }
        logs[j + 1] = key;
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Corrected Logs: ");
    for (int i = 0; i < n; i++) printf("%d ", logs[i]);
    printf("\nShifts: %d (O(N) best case), Time: %f s\n", shifts, time_spent);
    return 0;
}
