#include <stdio.h>
#include <time.h>
int main() {
    int usage_mins[] = {15, 3, 22, 8, 10};
    int n = 5;
    clock_t start = clock();
    printf("App Usage (mins): 15 3 22 8 10\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (usage_mins[j] < usage_mins[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int temp = usage_mins[min_idx];
            usage_mins[min_idx] = usage_mins[i];
            usage_mins[i] = temp;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Usage: ");
    for (int i = 0; i < n; i++) printf("%d ", usage_mins[i]);
    printf("\nExecution Time: %f s\n", time_spent);
    return 0;
}
