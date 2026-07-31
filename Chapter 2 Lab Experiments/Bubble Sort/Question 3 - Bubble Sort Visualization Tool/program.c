#include <stdio.h>
int main() {
    int arr[] = {4, 3, 2, 1};
    int n = 4, passes = 0;
    printf("Initial State: 4 3 2 1\n");
    for (int i = 0; i < n - 1; i++) {
        passes++;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("State after Pass %d: ", passes);
        for(int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
    return 0;
}
