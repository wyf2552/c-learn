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

/*
动态分配数组示例
#include <iostream>
using namespace std;

int main() {
    int * pn;
    int i = 5;
    pn = new int[i * 20];
    pn[0] = 20;
    pn[100] = 30; //编译没问题，运行时导致数组越界，100-99
}
*/

/* 例：客观事物-类
 写一个程序输入矩形的宽和高，输出面积和周长
 矩形的属性-宽和高 两个变量，分别代表宽和高
 对矩形的操作 设置宽和高 计算面积 计算周长

#include <iostream>
using namespace std;

class CRectangle {
    public:
        int w, h;
    void init(int w_, int h_) {
        w = w_; h = h_;
    }

    int Area() {
        return w * h;
    }

    int Perimeter() {
        return 2 * (w + h);
    }
};

int main() {
    int w, h;
    CRectangle r;
    cin >> w >> h;
    r.init(w, h);
    cout << r.Area() << endl << r.Perimeter();
    return 0;
}

*/

/*
重载成员函数
#include <iostream>
using namespace std;

class Location {
    private:
        int x, y;
    public:
        void init( int x = 0, int y = 0);
        void valueX(int val) {x = val;}
        int valueX() {return x;}
};

void Location::init(int X, int Y) {
    x = X;
    y = Y;
}

int main() {
    Location A;
    A.init(5);
    A.valueX(5);
    cout << A.valueX();
    return 0;
}
*/

/*
构造函数
#include <iostream>
using namespace std;

class Complex {
    private:
        double real, imag;
    public:
        void Set(double r, double i);
};//编译器自动生成默认构造函数

Complex c1;// 默认构造函数被调用
Complex * pc = new Complex;//默认构造函数被调用
*/

/*
多个构造函数
#include <iostream>
using namespace std;
class complex {
    private:
        double real, image;
    public:
        void Set(double r, double i);
        Complex(double r, double i);
        Complex(double r);
        Complex(Complex c1, Complex c2);
};

Complex::Complex(double r,double i) {
    real = real; imag = i;
}

Complex::Complex(double r) {
    real = r; imag = 0;
}

Complex::Complex(Complex c1, Complex c2); {
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}

Complex c1(3), c2(1,0), c3(c1, c2);
*/

/*构造函数在数组中的使用
#include <iostream>
using namespace std;
class CSample {
    int x;
public:
    CSample() {
        cout << "Constructor 1 Called" << endl;
    }
    CSample(int n) {
        x = n;
        cout << "Constructor 2 Called" << endl;
    }
};

int main() {
    CSample array1[2];
    cout << "step1" << endl;
    CSample array2[2] = {4, 5} ;
    cout << "step2" << endl;
    CSample array3[2] = {3};
    cout << "step3" << endl;
    CSample * array4 = new CSample[2];
    delete []array4;
    return 0;
}
*/

/*
构造函数
#include <iostream>
using namespace std;
class Demo {
        int id;
    public:
        Demo(int i) {
            id = i;
            cout << "id=" << id << "Constructed" << endl;
        }
        ~Demo() {
            cout << "id=" << id << "Destructed" << endl;
        }
};

Demo d1(1);
void Func() {
    static Demo d2(2);
    Demo d3(3);
    cout << "Func" << endl;
}

int main() {
    Demo d4(4);
    d4 = 6;
    cout << "main" << endl;
    { Demo d5(5);}
    Func();
    cout << "main ends" << endl;
    return 0;
}

*/

/* 考虑一个需要随时知道矩形总数和总面积的图形处理程序，可以用全局变量来记录总数和总面积，用静态成员将这两个变量封装进类中，就更容易理解和维护
#include <iostream>
using namespace std;

class CRectangle {
    private:
        int w, h;
        static int nTotalArea;
        static int nTotalNumber;
    public:
        CRectangle(int w_, int h_);
        ~CRectangle();
        static void PrintTotal();
};

CRectangle::CRectangle(int w_, int h_) {
    w = w_;
    h = h_;
    nTotalNumber ++;
    nTotalArea += w * h;

}

CRectangle::~CRectangle() {
    nTotalNumber --;
    nTotalArea -= w * h;
}

void CRectangle::PrintTotal() {
    cout << nTotalNumber << "," << nTotalArea <<endl;
}

int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalArea = 0;

int main() {
    CRectangle r1(3, 3), r2(2, 2);
    CRectangle::PrintTotal();
    r1.PrintTotal();
    return 0;
}
*/

/*
封闭类构造函数
#include <iostream>
using namespace std;
class CTyre{
    public:
        CTyre() {
            cout << "CTyre contructor" << endl;
        }
        ~CTyre() {
            cout << "CTyre destructor" << endl;
        }
};

class CEngine {
    public:
        CEngine() {
            cout << "CEngine contructor" << endl;
        }
        ~CEngine() {
            cout << "CEngine destructor" << endl;
        }
};

class CCar {
    private:
        CEngine engine;
        CTyre tyre;
    public:
        CCar() {
            cout << "CCar contructor" << endl;
        }
        ~CCar() {
            cout << "CCar destructor" << endl;
        }
};

int main() {
    CCar car;
    return 0;
}
*/

/* 常量成员函数
#include <iostream>
using namespace std;
class Sample {
    public:
        int value;
        void GetValue() const;
        void func() {};
        Sample() {}
};
void Sample::GetValue() const {
    value = 0; //wrong
    func(); //wrong
}
int main() {
    const Sample o;
    o.value = 100; //err
    o.func(); //err
    o.GetValue(); //ok
    return 0;
}
*/

/* 编写一个长度可变的字符串类String
   包含一个char*类型的成员变量-指向动态分配的存储空间
   该存储空间用于存放'\0'的结尾的字符串
#include <iostream>
using namespace std;
class String {
    private:
        char * str;
    public:
        String():str(NULL){}
        const char * c_str() {return str;}
        char * operator = (const char * s);
        ~String();
};
char * String::operator = (const char * s){
    if(str) delete[] str;
    if(s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
        str = NULL;
    return str;
}
String::~String() {
    if(str) delete[] str;
};
int main() {
    String s;
    s = "Good Luck,";
    cout << s.c_str() << endl;
    s = "Shenzhou 8!";
    cout << s.c_str() << endl;
    return 0;
}
*/