#include <stdio.h>

/* 描述

某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。

输入

共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。

输出

每个年龄段（分四段：18以下，19-35，36-60，大于60注意看样例输出的格式）
的患病人数占总患病人数的比例，以百分比的形式输出，精确到小数点后两位（double）。
关于c++的格式化的输入输出，请参考：http://www.cplusplus.com/reference/iomanip。
也可以在网上搜索一下，资料很多的。

样例输入

10
1 11 21 31 41 51 61 71 81 91

样例输出

1-18: 20.00%
19-35: 20.00%
36-60: 20.00%
60-: 40.00%

提示

注意最后一行的输出是“60-: ”，而不是“61-: ”。

每个冒号之后有一个空格。

输出可以用 cout<<fixed<<setprecision(2) << f; 来保留f后面的两位小数。 */

int main()
{ 
    int age;
    int num;
    int n_1_18 = 0;
    int n_19_35 = 0;
    int n_36_60 = 0;
    int n_60 = 0;

    scanf("%d", &num);

    for (int i = 0; i < num; ++i)  {
        scanf("%d", &age);
        switch (age) {
            case 1 ... 18:
                ++n_1_18;
                break;
            case 19 ... 35:
                ++n_19_35;
                break;
            case 36 ... 60:
                ++n_36_60;
                break;
            default: 
                ++n_60;
        }
    }
    double percent_18 = (double)n_1_18 / num * 100;
    double percent_19 = (double)n_19_35 / num * 100;
    double percent_36 = (double)n_36_60 / num * 100;
    double percent_60 = (double)n_60 / num * 100;

    printf("1-18: %.2f%%\n", percent_18);
    printf("19-35: %.2f%%\n", percent_19);
    printf("36-60: %.2f%%\n", percent_36);
    printf("60-: %.2f%%\n", percent_60);
}