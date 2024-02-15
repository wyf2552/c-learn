#include <stdio.h>
#include <string.h>

int main() {
    char str[14] = {0};
    char substr[4] = {0};

    while (scanf("%s %s", &str, &substr) != EOF) {
        int pos = 0;
        int len = strlen(str);
        for (int i = 1; i < len; ++i) {
            if (str[i] > str[pos]) {
                pos = i;
            }
        }
        for (int i = len - 1; i > pos; i--) {
            str[i + 3] = str[i];
        }
        for (int i = 0; i < 3; ++i) {
            str[++pos] = substr[i];
        }
        printf("%s\n", str);
        
        memset(&str, 0, sizeof(str));
        memset(&substr, 0, sizeof(substr));
    }

}