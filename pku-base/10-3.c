#include <stdio.h>

/* 描述

一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式

输入

一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式

输出

该句子中最长的单词。如果多于一个，则输出第一个

样例输入


第一组
I am a student of Peking University.
第二组
Hello world.

样例输出

第一组
University
第二组
Hello */

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