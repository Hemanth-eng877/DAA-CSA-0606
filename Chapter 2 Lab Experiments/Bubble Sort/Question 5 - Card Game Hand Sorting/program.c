#include <stdio.h>
int main() {
    int cards[] = {13, 2, 11, 5, 14}; // values 2-14
    int n = 5, passes = 0, swaps = 0, shifts = 0;
    printf("Unsorted Hand: 13 2 11 5 14\n");
    for (int i = 0; i < n - 1; i++) {
        passes++;
        for (int j = 0; j < n - i - 1; j++) {
            if (cards[j] > cards[j+1]) {
                int temp = cards[j];
                cards[j] = cards[j+1];
                cards[j+1] = temp;
                swaps++;
                shifts += 2; // Each swap involves 2 shifts/moves conceptually
            }
        }
    }
    printf("Sorted Hand: ");
    for (int i = 0; i < n; i++) printf("%d ", cards[i]);
    printf("\nPasses: %d, Swaps: %d, Shifts: %d\n", passes, swaps, shifts);
    return 0;
}
