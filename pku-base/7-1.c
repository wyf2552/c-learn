#include <stdio.h>
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