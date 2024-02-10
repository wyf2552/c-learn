#include <stdio.h>

/* */

int main ()
{
    int money;
    int dem[6] = { 100, 50, 20, 10, 5, 1};
    int count[6] = { 0 };

    scanf("%d", &money);

    for (int i = 0; i < 6; ++i) {
        count[i] = money / dem [i];
        money %= dem[i];
    }
    
    for (int i = 0; i < 6; ++i) {
        printf("%d\n", count[i]);
    }
}