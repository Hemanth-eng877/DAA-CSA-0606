#include <stdio.h>
int main() {
    // Timestamps where higher is more recent
    int playlist[] = {1001, 1005, 1003, 1009, 1002};
    int n = 5, shifts = 0;
    printf("Playlist Timestamps: 1001 1005 1003 1009 1002\n");
    for (int i = 1; i < n; i++) {
        int key = playlist[i];
        int j = i - 1;
        // Sort descending (recently added first)
        while (j >= 0 && playlist[j] < key) {
            playlist[j + 1] = playlist[j];
            shifts++;
            j = j - 1;
        }
        playlist[j + 1] = key;
    }
    printf("Reordered Playlist: ");
    for (int i = 0; i < n; i++) printf("%d ", playlist[i]);
    printf("\nShifts: %d\n", shifts);
    return 0;
}
