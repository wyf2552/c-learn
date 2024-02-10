#include <stdio.h>

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    int eaten = y / x; // 计算虫子能吃掉的苹果数
    int remaining = n - eaten; // 剩余的苹果数

    // 考虑y小时不足以吃完一个苹果的情况
    if (y % x != 0) {
        remaining -= 1;
    }

    // 输出剩余的苹果数
    printf("%d\n", remaining > 0 ? remaining : 0);

    return 0;
}

