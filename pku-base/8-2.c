#include <stdio.h>

int main() {
    int n;
    float t = 0;
    float p = 0;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0;i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        t = (arr[i] / 3.0) + 50;
        p = arr[i] / 1.2; 
        if (t < p) {
            printf("Bike\n");
        } else if (t > p) {
            printf("Walk\n");
        } else {
            printf("All\n");
        }
    }
}