#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int s[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }

    for(int i = 0; i < n; ++i) {
        int min = i;

        for (int j = i + 1; j < n; ++j) {
            if (s[j] < s[min]) {
                min = j;
            }
        }

        if (min != i) {
            int tmp = s[i];
            s[i] = s[min];
            s[min] = tmp;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", s[i]);
    }

    return 0;

}