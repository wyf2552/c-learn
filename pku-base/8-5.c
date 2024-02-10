#include <stdio.h>

int main() {
    int n;
    int m = 0;

    scanf("%d", &n);

    for (int i = 10; i <= n; ++i) {
        int a = i;
        m = 0;

        while (a != 0) {
            m += a % 10;
            a /= 10;

        }

        if (i % m == 0) {
            printf("%d\n", i); 
        }
    }    
}


