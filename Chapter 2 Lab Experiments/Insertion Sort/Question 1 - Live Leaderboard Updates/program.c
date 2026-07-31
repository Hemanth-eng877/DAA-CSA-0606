#include <stdio.h>
int main() {
    int leaderboard[10] = {95, 88, 75, 60, 50}; // Already sorted in desc
    int n = 5;
    int new_score = 80;
    int shifts = 0, j = n - 1;
    printf("Current Leaderboard: 95 88 75 60 50\nNew Score: %d\n", new_score);
    while (j >= 0 && leaderboard[j] < new_score) {
        leaderboard[j + 1] = leaderboard[j];
        shifts++;
        j--;
    }
    leaderboard[j + 1] = new_score;
    n++;
    printf("Updated Leaderboard: ");
    for (int i = 0; i < n; i++) printf("%d ", leaderboard[i]);
    printf("\nShifts: %d\n", shifts);
    return 0;
}
