#include <stdio.h>
#include <time.h>
int main() {
    int hand[] = {7, 3, 5, 2, 8, 4};
    int n = 6, shifts = 0;
    clock_t start = clock();
    printf("Dealt Hand: 7 3 5 2 8 4\n");
    for (int i = 1; i < n; i++) {
        int key = hand[i];
        int j = i - 1;
        while (j >= 0 && hand[j] > key) {
            hand[j + 1] = hand[j];
            shifts++;
            j = j - 1;
        }
        hand[j + 1] = key;
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Hand: ");
    for (int i = 0; i < n; i++) printf("%d ", hand[i]);
    printf("\nTotal Shifts: %d, Time: %f s\n", shifts, time_spent);
    return 0;
}
