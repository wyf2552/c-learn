#include <stdio.h>
#include <stdbool.h>

struct coordinate {
    int x;
    int y;
};

int main() {
    int n;
    scanf("%d", &n);

    struct coordinate data[n];
    struct coordinate maxVec[n];
    int maxIdx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &data[i].x, &data[i].y);
    }

    for (int i = 0; i < n; i++) {
        bool isMax = true;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (data[i].x <= data[j].x && data[i].y <= data[j].y) {
                    isMax = false;
                    break;
                }
            }
        }

        if (isMax) {
            maxVec[maxIdx] = data[i];
            maxIdx++;
        }
    }

    for (int i = 0; i < maxIdx; ++i) {
        int min = i;

        for (int j = i + 1; j < maxIdx; ++j) {
            if (maxVec[min].x > maxVec[j].x) {
                min = j;
            }
        }

        if (min != i) {
            struct coordinate tmp = maxVec[i];
            maxVec[i] = maxVec[min];
            maxVec[min] = tmp;
        }
    }

    for (int i = 0; i < maxIdx - 1; i++) {
        printf("(%d,%d),", maxVec[i].x, maxVec[i].y);
    }

    if (maxIdx - 1 >= 0) {
        printf("(%d,%d)\n", maxVec[maxIdx - 1].x, maxVec[maxIdx - 1].y);
    }
}

