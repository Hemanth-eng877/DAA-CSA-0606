#include <stdio.h>
int main() {
    int priorities[] = {3, 1, 2, 5, 4};
    int n = 5, comps = 0;
    printf("Traffic Priorities: 3 1 2 5 4\n");
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comps++;
            if (priorities[j] > priorities[j+1]) {
                int temp = priorities[j];
                priorities[j] = priorities[j+1];
                priorities[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break; // early exit
    }
    printf("Sorted Priorities: ");
    for (int i = 0; i < n; i++) printf("%d ", priorities[i]);
    printf("\nTotal Comparisons: %d\n", comps);
    return 0;
}
