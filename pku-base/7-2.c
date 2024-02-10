#include <stdio.h>
int n ;
int ret;
int main()
{
    scanf("%d", &n);
    if (n >= 95 && n <= 100) {
        ret = 1;
    } else if (n >= 90 && n < 95) {
        ret = 2;
    } else if (n >= 85 && n < 90) {
        ret = 3;
    } else if (n >= 80 && n < 85) {
        ret = 4;
    }
    else if ( n >= 70 && n < 80)
    {
        ret = 5;
    }
    else if ( n >= 60 && n <70)
    {
        ret = 6;
    }
    else if ( n < 60)
    {
        ret = 7;
    }
    printf ("%d\n", ret);
    return 0;
}

