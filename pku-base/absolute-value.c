#include <stdio.h>

int main() {
    int nums[6];

    // 读取输入的6个正整数
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &nums[i]);
    }

    // 初始化最大的奇数为0，最小的偶数为100
    int max_odd = 0;
    int min_even = 100;

    // 找出最大的奇数和最小的偶数
    for (int i = 0; i < 6; ++i) {
        if (nums[i] % 2 == 1 && nums[i] > max_odd) {
            max_odd = nums[i];
        } else if (nums[i] % 2 == 0 && nums[i] < min_even) {
            min_even = nums[i];
        }
    }

    // 输出最大的奇数与最小的偶数之差的绝对值
    printf("%d\n", max_odd - min_even > 0 ? max_odd - min_even : min_even - max_odd);

    return 0;
}
