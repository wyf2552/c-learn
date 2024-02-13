#include <stdio.h>

char tolower(char chr) {
    if (chr >= 'A' && chr <= 'Z') {
        return (chr - 'A' + 'a');
    }

    return chr;
}

int main() {
    int i = 0;
    char s1[80] = {0};
    char s2[80] = {0};
    char ret;

    gets(s1);
    gets(s2);
    
    while (s1[i] != '\0' && s2[i] != '\0'){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        
        if (s1[i] == s2[i]) {
            i++;
        } else {
            break;
        }
    }

    if (s1[i] > s2[i]) {
        ret = '>';
    } else if (s1[i] < s2[i]) {
        ret = '<';
    } else {
        ret = '=';
    }

    printf("%c\n", ret);
}