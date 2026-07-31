#include <stdio.h>
#include <time.h>
int main() {
    int severity[] = {8, 2, 10, 4, 7};
    int n = 5, swaps = 0;
    clock_t start = clock();
    printf("Alert Severity: 8 2 10 4 7\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (severity[j] < severity[j+1]) { // Sort descending for highest severity first
                int temp = severity[j];
                severity[j] = severity[j+1];
                severity[j+1] = temp;
                swaps++;
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Alerts (Desc): ");
    for (int i = 0; i < n; i++) printf("%d ", severity[i]);
    printf("\nTotal Swaps: %d, Time: %f s\n", swaps, time_spent);
    return 0;
}
