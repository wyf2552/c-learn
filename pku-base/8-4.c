#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    int k;
    bool isFound = false;

    scanf("%d %d", &n, &k);
    int arr[n]; 
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n && !isFound; ++i) {
        for (int j = i + 1; j < n && !isFound; ++j) {
          if (arr[i] + arr[j] == k) {
            isFound = true;
          } 
        }
    }
    printf("%s\n", isFound ? "yes" : "no");
}