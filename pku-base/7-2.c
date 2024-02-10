#include <stdio.h>

/* 描述

输入一个0--100的分数，判断分数代表什么等级。

95<=分数<=100, 输出1

90<=分数<95,输出2

85<=分数<90,输出3

80<=分数<85,输出4

70<=分数<80,输出5

60<=分数<70输出6

分数 < 60;输出7.

输入

n

输出

m

样例输入

1
87

样例输出

1
3 */

int main()
{
    int n ;
    int ret;

    scanf("%d", &n);

    switch (n) {
        case 95 ... 100:
            ret = 1;
            break;
        case 90 ... 94:
            ret = 2;
            break;
        case 85 ... 89:
            ret = 3;
            break;
        case 80 ... 84:
            ret = 4;
            break;
        case 70 ... 79:
            ret = 5;
            break;
        case 60 ... 69:
            ret = 6;
            break;
        default :
            ret = 7;
    }

    printf ("%d\n", ret);
    
}

