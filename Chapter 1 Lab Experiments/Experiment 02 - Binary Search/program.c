#include <stdio.h>
int main() {
    int arr[] = {11, 22, 33, 44, 55, 66};
    int n = 6, key = 44;
    int low = 0, high = n-1, mid;
    printf("Sorted Array: 11 22 33 44 55 66\nTarget: 44\n");
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Found at index: %d\n", mid);
            return 0;
        } else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    printf("Not found.\n");
    return 0;
}
