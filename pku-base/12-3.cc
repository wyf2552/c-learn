#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

/* 描述

给定一组点(x,y)，求距离最远的两个点之间的距离。

输入

第一行是点数n（n大于等于2）

接着每一行代表一个点，由两个浮点数x y组成。

输出

输出一行是最远两点之间的距离。

使用cout << fixed << setprecision(4) << dis << endl;输出距离值并精确到小数点后4位。

fixed和setprecision是在<iomanip>头文件里定义的格式控制操作符，需要#include <iomanip>.

样例输入

6
34.0 23.0
28.1 21.6
14.7 17.1
17.0 27.2
34.7 67.1
29.3 65.1

样例输出

53.8516

提示

注意在内部计算时最好使用double类型，float精准度不能满足本题测试数据要求。 */

using namespace std;

int main() {
    int n;
    double len = 0;

    scanf("%d", &n);

    double s[n][2];

    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &s[i][0], &s[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double a = s[i][0] - s[j][0];
            double b = s[i][1] - s[j][1];
            double c = sqrt(a * a + b * b);
            if (c > len) {
                len = c;
            }
        }
    }

    cout << fixed << setprecision(4) << len << endl;
}