#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d,%d,%d", &a, &b, &c);

    if (c == a + b) {
        printf("+\n");
    } else if (c == a - b) {
        printf("-\n");
    } else if (c == a * b) {
        printf("*\n");
    } else if (c == a / b) {
        printf("/\n");
    } else if (c == a % b) {
        printf("%%\n");
    } else {
        printf("error\n");
    }
    
    return 0;
}

