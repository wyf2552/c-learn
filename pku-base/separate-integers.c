#include <stdio.h>

int main() {
    int number;

    printf("请输入一个任意的三位整数：");
    scanf("%d", &number);

    // 获取百位数
    int hundreds = number / 100;
    printf("%d\n", hundreds);

    // 获取十位数
    int tens = (number / 10) % 10;
    printf("%d\n", tens);

    // 获取个位数
    int ones = number % 10;
    printf("%d\n", ones);

    return 0;
}
