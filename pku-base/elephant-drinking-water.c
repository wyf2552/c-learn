#include <stdio.h>

int main() {
    int h, r;
    const double PI = 3.14159265358979323846; // 定义圆周率 PI

    // 读取输入
    scanf("%d %d", &h, &r);

    // 计算小圆桶的容积
    double volume = PI * r * r * h;

    // 计算大象至少需要多少桶水
    int buckets = 20000 / volume;
    if (20000 % (int)volume != 0) {
        buckets++; // 如果水量不是整数桶的倍数，需要多喝一桶
    }

    // 输出结果
    printf("%d\n", buckets);

    return 0;
}
