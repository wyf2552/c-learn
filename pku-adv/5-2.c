#include <stdio.h>

/* 给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按从左上到右下的对角线顺序遍历整个数组。
输入

输入的第一行上有两个整数，依次为row和col。

余下有row行，每行包含col个整数，构成一个二维整数数组。

（注：输入的row和col保证0 < row < 100, 0 < col < 100）

输出

按遍历顺序输出每个整数。每个整数占一行。

样例输入

3 4
1 2 4 7
3 5 8 10
6 9 11 12 */

void solution_2(void) {
    int row;
    int col;

    scanf("%d %d", &row, &col);
    int arry[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arry[i][j]);
        }
    }
    for (int k = 0; k < col; ++k) {
        for (int i = 0, j = k; i < row && j >= 0; ++i, --j) {
            printf("%d\n", arry[i][j]);
        }
    }
    for (int k = 1; k < row; ++k) {
        for (int i = k, j = col - 1; i < row; ++i, --j) {
            printf("%d\n", arry[i][j]);
        }
    }
}

void solution_1(void) {
    int row;
    int col;

    scanf("%d %d", &row, &col);
    int arry[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arry[i][j]);
        }
    }

    for (int sum = 0; sum < row + col - 1; sum++) {
        for (int i = 0;i <= sum; i++) {
            if (i < row && sum - i < col) {
                printf("%d\n", arry[i][sum - i]);
            }
        }
    }
}

int main() {
    solution_2();
    // solution_1();
}