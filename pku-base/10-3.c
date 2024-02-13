#include <stdio.h>

int main() {
    char* ptr = NULL;
    char str[500] = {0};
    int beg = 0;
    int len = 0;
    int i = 0;

    gets(str);

    for (; i < 500; ++i) {
        if (str[i] == ' ' || str[i] == '.') {
            int a = i - beg;
            if (a > len) {
                len = a;
                str[i] = '\0';
                ptr = &str[beg];
            }

            beg = i + 1;
        }
        if (str[i] == '.') {
            break;
        }

    }

    printf("%s\n", ptr);
}