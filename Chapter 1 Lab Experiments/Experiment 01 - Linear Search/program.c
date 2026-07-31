#include <stdio.h>
int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int n = 6, key = 70, found = 0;
    printf("Array: 10 23 45 70 11 15\nTarget: 70\n");
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            printf("Found at index: %d\n", i);
            found = 1; break;
        }
    }
    if(!found) printf("Not found.\n");
    return 0;
}
