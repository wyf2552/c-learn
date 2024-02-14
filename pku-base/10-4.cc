#include <stdio.h>
#include <iostream>
#include <iomanip>

/* 描述

在main函数中， 生成一个5*5的矩阵，输入矩阵数据，并输入n，m的值。判断n，m是否在数组范围内，如果不在，则输出error；如果在范围内，则将n行和m行交换，输出交换n，m后的新矩阵。

输入

5*5矩阵的数据，以及n和m的值。

输出

如果不可交换，则输出error

如果可交换，则输出新矩阵

样例输入


1 2 2 1 2
5 6 7 8 3
9 3 0 5 3
7 2 1 4 6
3 0 8 2 4
0 4

1 2 2 1 2
5 6 7 8 3
9 3 0 5 3
7 2 1 4 6
3 0 8 2 4
5 1

样例输出

    3   0   8   2   4
    5   6   7   8   3
    9   3   0   5   3
    7   2   1   4   6
    1   2   2   1   2

    error */

using namespace std;

int main() {
    int s[5][5] = {0};
    int n = 0;
    int m = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &s[i][j]);
        }
    }

    scanf("%d %d", &n, &m);

    if (n < 0 || n >= 5 || m < 0 || m >= 5) {
        printf("error\n");
        return 0;
    }

    for (int j = 0; j < 5; ++j) {
        int tmp = s[n][j];
        s[n][j] = s[m][j];
        s[m][j] = tmp;
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << setw(4)<< s[i][j];
        }
        cout<< endl;
    }
}