#include <stdio.h>
int main() {
    int stream[] = {100, 105, 98, 110};
    int sorted_stream[4];
    int n = 4, comps = 0, shifts = 0;
    printf("Stock Stream: 100 105 98 110\n");
    for (int i = 0; i < n; i++) {
        int key = stream[i];
        int j = i - 1;
        while (j >= 0) {
            comps++;
            if (sorted_stream[j] > key) {
                sorted_stream[j + 1] = sorted_stream[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }
        sorted_stream[j + 1] = key;
        printf("Inserted %d -> ", key);
        for(int k = 0; k <= i; k++) printf("%d ", sorted_stream[k]);
        printf("\n");
    }
    printf("Total Comparisons: %d, Total Shifts: %d\n", comps, shifts);
    return 0;
}
