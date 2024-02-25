#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*  描述

有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，
也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，
（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

输入

第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，
’@’表示第一天该房间住着得流感的人。

接下来的一行是一个整数m，m不超过100.

输出

输出第m天，得流感的人数


样例输入

5
....#
.#.@.
.#@..
#....
.....
4

样例输出

16 */

char toChar(int n) {
    return '0' + n;
}

void solution_1() {
    int n;
    int m;
    int count = 0;

    scanf("%d", &n);
    getchar(); /* read '\n' */

    char s[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = getchar();
        }
        getchar(); /* read '\n' */
    }

    scanf("%d", &m);

    for (int k = 1; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == '@' || (s[i][j] < toChar(k) && s[i][j] >= toChar(1))) {
                    if (i - 1 >= 0 && s[i - 1][j] == '.') {
                        s[i - 1][j] = toChar(k);
                    }
                    if (i + 1 < n && s[i + 1][j] == '.') {
                        s[i + 1][j] = toChar(k);
                    }
                    if (j - 1 >= 0 && s[i][j - 1] == '.') {
                        s[i][j - 1] = toChar(k);
                    }
                    if (j + 1 < n && s[i][j + 1] == '.') {
                        s[i][j + 1] = toChar(k);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '@' || (s[i][j] < toChar(m) && s[i][j] >= toChar(1))) {
                ++count;
            }
        }
    }

    printf("%d\n", count);
}

void solution_2() {
    int n;
    int m;
    int count = 0;

    scanf("%d", &n);
    getchar(); /* read '\n' */

    char s[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = getchar();
        }
        getchar(); /* read '\n' */
    }

    scanf("%d", &m);

    for (int k = 1; k < m; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '@') {
                    if ((i - 1) >= 0 && s[i - 1][j] == '.') {
                        s[i - 1][j] = '!';
                    }
                    if ((i + 1) < n && s[i + 1][j] == '.') {
                        s[i + 1][j] = '!';
                    }
                    if ((j - 1) >= 0 && s[i][j - 1] == '.') {
                        s[i][j - 1] = '!';
                    }
                    if ((j + 1) < n && s[i][j + 1] == '.') {
                        s[i][j + 1] = '!';
                    }
                }

            }
        }

        for (int i = 0;  i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '!') {
                    s[i][j] = '@';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '@') {
                ++count;
            }
        }
    }

    printf("%d\n", count);
}

void solution_3() {
    int n;
    int m;
    int count = 0;

    scanf("%d", &n);
    getchar(); /* read '\n' */

    int s[n][n];
    memset(&s, 0, sizeof(s));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            switch (getchar()) {
                case '@':
                    s[i][j] = 1;
                    break;
                case '.':
                    s[i][j] = -1;
            }
        }
        getchar(); /* read '\n' */
    }

    scanf("%d", &m);

    for (int k = 1; k < m; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == k) {
                    if (i - 1 >= 0 && s[i - 1][j] == -1) {
                        s[i - 1][j] = k + 1;
                    }
                    if (i + 1 < n && s[i + 1][j] == -1) {
                        s[i + 1][j] = k + 1;
                    }
                    if (j - 1 >= 0 && s[i][j - 1] == -1) {
                        s[i][j - 1] = k + 1;
                    }
                    if (j + 1 < n && s[i][j + 1] == -1) {
                        s[i][j + 1] = k + 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] > 0) {
                ++count;
            }
        }
    }

    printf("%d\n", count);
}


int main() {
    // solution_1();
    //solution_2();
    solution_3();

}
