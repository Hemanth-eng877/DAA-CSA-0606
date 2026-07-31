#include <stdio.h>
#include <float.h>
#include <math.h>

struct Point { int x, y; };

float dist(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(struct Point P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min) min = dist(P[i], P[j]);
    return min;
}

int main() {
    struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("Points: (2,3) (12,30) (40,50) (5,1) (12,10) (3,4)\n");
    printf("The smallest distance is %f\n", bruteForce(P, n));
    return 0;
}
