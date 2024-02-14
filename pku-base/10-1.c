#include <stdio.h>

/* 描述

在一个字符串中找出元音字母a,e,i,o,u出现的次数。

输入

输入一行字符串（字符串中可能有空格，请用cin.getline(s,counts)
方法把一行字符串输入到字符数组s中，其中counts是s的最大长度，这道题里面可以直接写80。），
字符串长度小于80个字符。

输出

输出一行，依次输出a,e,i,o,u在输入字符串中出现的次数，整数之间用空格分隔。

样例输入

If so, you already have a Google Account. You can sign in on the right.

样例输出

5 4 3 7 3 */

int main() {
    char str[80] = {0};
    int sum[5] = {0};

    gets(str);

    for (int i = 0; i < 80; ++i) {
        switch (str[i]){
            case 'a':
                sum[0]++;
                break;
            case 'e':
                sum[1]++;
                break;
            case 'i':
                sum[2]++;
                break;
            case 'o':
                sum[3]++;
                break;
            case 'u':
                sum[4]++;
                break;
        }
    }

    printf("%d %d %d %d %d\n", sum[0], sum[1], sum[2], sum[3], sum[4]);

}
