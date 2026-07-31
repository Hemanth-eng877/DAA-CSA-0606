#include <stdio.h>
#include <time.h>
int main() {
    int scores[] = {50, 70, 90, 60, 80};
    int n = 5, passes = 0;
    clock_t start = clock();
    printf("Contestant Scores: 50 70 90 60 80\n");
    for (int i = 0; i < n - 1; i++) {
        passes++;
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (scores[j] > scores[max_idx]) max_idx = j;
        }
        if (max_idx != i) {
            int temp = scores[max_idx];
            scores[max_idx] = scores[i];
            scores[i] = temp;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Top Scores: ");
    for (int i = 0; i < n; i++) printf("%d ", scores[i]);
    printf("\nPasses: %d, Execution Time: %f s\n", passes, time_spent);
    return 0;
}
