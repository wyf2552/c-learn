#include <stdio.h>

/* 甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，
如果告诉你a day in the life,真的会是tomorrow never knows?
相信学了计概之后这个不会是难题，现在就来实现吧。

读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。
可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

输入

输入仅一行，格式为yyyy-mm-dd的日期。

输出

输出也仅一行，格式为yyyy-mm-dd的日期

样例输入

2010-07-05

样例输出

2010-07-06

提示

闰年的标准：

(1)普通年能被4整除且不能被100整除的为闰年。（如2004年就是闰年,1901年不是闰年）

(2)世纪年能被400整除的是闰年。(如2000年是闰年，1100年不是闰年)

可以利用一个字符变量吃掉输入的短横线（减号），输出时请活用setfill和setw 控制符。 */

int getMonthDays(int y, int m) {
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else if (m == 2) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 31;
    }
}

int main() {
    int y = 0;
    int m = 0;
    int d = 0;

    scanf("%d-%d-%d", &y, &m, &d);

    d += 1;
    if (d > getMonthDays(y, m)) {
        d = 1;
        m += 1;
    }

    if (m > 12) {
        m = 1;
        y += 1;
    }

    printf("%d-%02d-%02d\n", y, m, d);
}