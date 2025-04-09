#include <stdio.h>
#include <math.h>

int main() {
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++) {
        int x, y, dist, square;
        scanf("%d%d", &x, &y);
        dist = y - x;
        square = sqrt(dist);

        if (square * square == dist) { // 정확히 제곱근일 시
            printf("%d\n", 2 * square - 1);
        } else if (square * square + square < dist) { // 중간값 초과
            printf("%d\n", 2 * square + 1);
        } else { // 그 외(중간값 이하)
            printf("%d\n", 2 * square);
        }
    }
    return 0;
}