#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        double house = 200;
        double money = n;
        int m = 1;

        for (; m <= 20; ++m) {
            if (money >= house) {
                break;
            }
            house *= 1 + 0.01 * k;
            money += n;
        }
        if (m <= 20) {
            printf("%d\n", m);
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}