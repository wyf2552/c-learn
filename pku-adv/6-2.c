#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char str[n][257];
    for (int i = 0; i < n; i++){
        fgets((char *)&str[i], 257, stdin);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; str[i][j] != '\0' && str[i][j] != '\n'; j++) {
            switch (str[i][j]) {
                case 'A':
                    str[i][j] = 'T';
                    break;
                case 'T':
                    str[i][j] = 'A';
                    break;
                case 'C':
                    str[i][j] = 'G';
                    break;
                case 'G':
                    str[i][j] = 'C';
                    break;
            }
        }

        printf("%s", (char *)&str[i]);
    
    }

    return 0;
}