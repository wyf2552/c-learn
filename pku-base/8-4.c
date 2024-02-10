#include <stdio.h>
#include <stdbool.h>

/* 描述

在一个长度为n(n < 1000)的整数序列中，判断是否存在某两个元素之和为k。

输入

第一行输入序列的长度n和k，用空格分开。

第二行输入序列中的n个整数，用空格分开。

输出

如果存在某两个元素的和为k，则输出yes，否则输出no。

样例输入

9 10
1 2 3 4 5 6 7 8 9

样例输出

yes */

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