#include <stdio.h>

/* 用户输入N和K，然后接着输入N个正整数（无序的），程序在不对N个整数排序的情况下，
找出第K大的数。注意，第K大的数意味着从大到小排在第K位的数。

输入

N

K

a1 a2 a3 a4 ..... aN

输出

b

样例输入

5
2
32 3 12 5 89

样例输出


32




提示  

这是一道很经典的算法问题，是公司面试的常见考题。以后学习递归之后再回头看看这道题，或许有新解. */

// 快速选择算法
int quick_select(int nums[], int low, int high, int k) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (nums[j] >= pivot) {
            // 交换元素
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }

    // 将基准元素放到正确的位置
    int temp = nums[i];
    nums[i] = nums[high];
    nums[high] = temp;

    if (i == k) {
        return nums[i];
    } else if (i < k) {
        return quick_select(nums, i + 1, high, k);
    } else {
        return quick_select(nums, low, i - 1, k);
    }
}

int main() {
    int N, K;

    // 输入N和K
    
    scanf("%d", &N);
    scanf("%d", &K);

    // 输入N个整数
    int numbers[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    // 找出第K大的数
    int result = quick_select(numbers, 0, N - 1, K - 1);

    // 输出结果
    printf("%d\n", result);

    return 0;
}
