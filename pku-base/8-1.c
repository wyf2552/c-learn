#include <stdio.h>

int main() {
    int a;
    int data;
    int sum = 0;

    scanf("%d", &a);

    for (int i = 0; i < 5; ++i) {
        scanf("%d", &data);
    
        if (data < a) {
            sum += data;
        }
    }
    printf("%d\n", sum);
}