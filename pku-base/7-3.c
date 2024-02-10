#include <stdio.h>

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
