#include <stdio.h>
int main() {
    int marks[] = {55, 92, 45, 87, 60};
    int n = 5;
    printf("Initial Marks: 55 92 45 87 60\n");
    for (int i = 0; i < n - 1; i++) {
        int swaps_this_pass = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j+1]) {
                int temp = marks[j];
                marks[j] = marks[j+1];
                marks[j+1] = temp;
                swaps_this_pass++;
            }
        }
        printf("Pass %d: Swaps = %d\n", i+1, swaps_this_pass);
    }
    printf("Corrected Marks: ");
    for (int i = 0; i < n; i++) printf("%d ", marks[i]);
    printf("\n");
    return 0;
}
