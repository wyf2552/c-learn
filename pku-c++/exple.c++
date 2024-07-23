/* 例题1 函数指针

#include <stdio.h>

void PrintMin(int a, int b) {
    if (a < b) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }
}

int main() {
    void (*pf)(int,int);
    int x = 4, y = 5;
    pf = PrintMin;
    pf(x,y);
    return 0;
}
*/

/* 例题2 调用qsort函数，进行比较

#include <stdio.h>
#include <stdlib.h>

int MyCompare(const void * elem1, const void * elem2) {
    unsigned int * p1, * p2;
    p1 = (unsigned int *) elem1; //"*elem1" 非法
    p2 = (unsigned int *) elem2; //"*elem2" 非法
    return (*p1 % 10) - (*p2 % 10);
}

#define NUM 5
int main() {
    unsigned int an[NUM] = {8,123,11,10,4};
    qsort(an,NUM,sizeof(unsigned int),MyCompare);
    for(int i = 0; i < NUM; i++){
        printf("%d ",an[i]);
    }

    return 0;
} */

/* 位运算

#include <stdio.h>

int main() {
    int n1 = 15;
    short n2 = -15;
    unsigned short n3 = 0xffe0;
    char c = 15;
    n1 = n1 >> 2;
    n2 >>= 3;
    n3 >>= 4;
    c >>= 3;
    printf("n1=%d,n2=%x,n3=%x,c=%x",n1, n2, n3, c);

}

*/


/* 引用

#include <iostream>
using namespace std;
int main() {
    int n = 7;
    int & r = n;
    r = 4;
    cout << r;
    cout << n;
    n = 5;
    cout << r;
}
*/

/* 引用

#include <iostream>
using namespace std;
int main() {
    double a = 4, b = 5;
    double & r1 = a;
    double &r2 = r1;
    r2 = 10;
    cout << a << endl;
    r1 = b;
    cout << a << endl;
    return 0;
}
*/

/*
引用作为函数的返回值
#include <iostream>
using namespace std;

int n = 4;
int & SetValue() {return n;}
int main() {
    SetValue() = 40;
    cout << n;
    return 0;

}
*/

//动态分配数组示例
#include <iostream>
using namespace std;

int main() {
    int * pn;
    int i = 5;
    pn = new int[i * 20];
    pn[0] = 20;
    pn[100] = 30; //编译没问题，运行时导致数组越界，100-99
}

