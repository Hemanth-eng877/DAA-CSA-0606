#include <stdio.h>
int mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int left[100], right[100];
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l, swaps = 0;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else { arr[k++] = right[j++]; swaps += (n1 - i); }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    return swaps;
}
int mergeSortAndCount(int arr[], int l, int r) {
    int count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += mergeSortAndCount(arr, l, m);
        count += mergeSortAndCount(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}
int main() {
    int arr[] = {1, 20, 6, 4, 5};
    printf("Array: 1 20 6 4 5\n");
    printf("Number of inversions are %d \n", mergeSortAndCount(arr, 0, 4));
    return 0;
}
