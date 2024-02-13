#include <stdio.h>

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
