#include <stdio.h>

typedef struct chr_info {
    int cnt;
    int idx;
} chrinfo_t;

char to_lower(char chr) {
    if (chr >= 'A' && chr <= 'Z' ) {
        chr = chr - 'A' + 'a';
    } else if (chr >= 'a' && chr <= 'z'){

    } else {
        chr = -1;
    }

    return chr;
}

int main() {
    char str[502];
    chrinfo_t chrinfo_vec[255] = { 0 };

    fgets((char*)&str[0], 502, stdin);


    for (int i = 0; i < 255; ++i) {
        chrinfo_vec[i].idx = -1;
    }

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i) {
        char chr = to_lower(str[i]);

        if (chr > 0) {
            ++chrinfo_vec[chr].cnt;

            if (chrinfo_vec[chr].idx == -1) {
                chrinfo_vec[chr].idx = i;
            }
        }
    }

    int chr_1st = 0;
    int chr_2nd = 0;

    for (int chr = 'a'; chr <= 'z'; ++chr) {
        int cnt = chrinfo_vec[chr].cnt;
        int idx = chrinfo_vec[chr].idx;

        if (cnt > chrinfo_vec[chr_1st].cnt) {
            chr_2nd = chr_1st;
            chr_1st = chr;
        } else if (cnt == chrinfo_vec[chr_1st].cnt) {
            if (idx < chrinfo_vec[chr_1st].idx) {
                chr_1st = chr;
            }
        } else if (cnt > chrinfo_vec[chr_2nd].cnt) {
            chr_2nd = chr;
        } else if (cnt == chrinfo_vec[chr_2nd].cnt) {
            if (idx < chrinfo_vec[chr_2nd].idx) {
               chr_2nd = chr;
            }
        }
    }
    printf("%c+%c:%d\n", chr_2nd - 'a' + 'A', chr_2nd,
        chrinfo_vec[chr_2nd].cnt);
}