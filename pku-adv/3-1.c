#include <stdio.h>

int main() {
    char str[502] = {0};
    int beg = 0, end = 0;
    char tmp = 0;

    fgets((char*)&str,sizeof(str),stdin);

    while (1) {
        /* find the end position of a word */
        while (str[end] != ' ' && str[end] != '\0' && str[end] != '\n') {
            ++end;
        }

        /* swap the word */
        for (int i = beg, j = end - 1; i < j; ++i, --j){
            tmp = str[j] ;
            str[j] = str[i];
            str[i] = tmp;
        }

        /* reach the end of the string */
        if (str[end] == '\0' || str[end] == '\n') {
            break;
        }

        /* skip white space between two words */
        while (str[end] == ' ') {
            ++end;
        }

        /* find the begin position of a word */
        beg = end;
    }

    printf("%s\n", str);
}