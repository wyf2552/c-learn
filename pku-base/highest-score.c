#include <stdio.h>

int main() {
    int n;
    
    // 读取参加考试的人数
    scanf("%d", &n);

    // 定义变量保存最高成绩，初始化为一个较小的值
    int highest = -1; // 这里假设成绩不会是负数，因此用 -1 来作为初始值
    
    // 逐个读取成绩并找出最高分数
    for (int i = 0; i < n; ++i) {
        int score;
        scanf("%d", &score);
        
        // 更新最高分数
        if (score > highest) {
            highest = score;
        }
    }

    // 输出最高分数
    printf("%d\n", highest);

    return 0;
}