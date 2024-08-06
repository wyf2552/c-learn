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

/*
运算符重载实例：可变长整型数组

#include <iostream>
using namespace std;

class CArray {
    int size;
    int * ptr;
public:
    CArray(int s = 0);
    CArray(CArray & a);
    ~CArray();
    void push_back(int v);
    CArray & operator = (const CArray & a);
    int length() {return size;}
    int & CArray::operator[](int i){
        return ptr[i];
    }
};

CArray::CArray(int s):size(s) {
    if(s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}
CArray::CArray(CArray & a) {
    if(!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int)* a.size);
    size = a.size;
}
CArray::~CArray() {
    if(ptr) delete[]ptr;
}
CArray & CArray::operator = (const CArray & a) {
    if(ptr == a.ptr)
        return * this;
    if(a.ptr == NULL) {
        if(ptr) delete[] ptr;
        ptr = NULL;
        size = 0;
        return * this;
    }
    if (size < a.size) {
        if(ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return * this;
}

void CArray::push_back(int v) {
    if (ptr) {
        int * tmpPtr = new int[size + 1];
        memcpy(tmpPtr,ptr,sizeof(int) * size);
        delete[] ptr;
        ptr = tmpPtr;
    }
    else
        ptr = new int[1];
    ptr[size++] = v;
}

int main () {
    CArray a;
    for(int i = 0; i < 5; ++i)
        a.push_back(i);
    CArray a2, a3;
    a2 = a;
    for(int i = 0; i < a.length(); ++i)
        cout << a2[i] << " ";
    a2 = a;
    for(int i = 0; i < a2.length(); ++i)
        cout << a2[i] << " ";
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for(int i = 0; i < a4.length(); ++i)
        cout << a4[i] << " ";
    return 0;

}
*/

/*
假定c是Complex复数类的对象，现在希望写"cout << c;"，就能以"a + bi"的形式数输出c的值，写"cin >> c;",就能从键盘接受" a + bi"形式的输入，并且是使得c.real = a, c.imag = b.

#include <iostream>
#include <string>
#include <cstdlib>
using namespce std;

class Complex {
    double real, image;
public:
    Complex(double r = 0,double i = 0):real(r),image(i){};
    friend ostream & operator<<(ostream & os, const Complex & c);
    friend istream & operator>>(istream & is,Complex & c)
};
ostream & operator<<(ostream & os,const Complex & c) {
    os << c.real << "+" << c.image << "i";
    return os;
}
istream & operator>>(istream & is,Complex & c) {
    string s;
    is >> s;
    int pos = s.find("+", 0);
    string sTmp = s.substr(0,pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos + 1, s.length()-pos-2);
    c.imag = atof(sTmp.c_str());
    return is;
    }
int main() {
    Complex c;
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    return 0;
}
*/

/*
#include <iostream>
using namespce std;

class CDemo {
    private:
        int n;
    public:
        CDemo(int i = 0):n(i) {}
        CDemo operator++();
        CDemo operator++(int);
        operator int () {return n;}
        friend CDemo operator--(CDemo &);
        friend CDemo operator--(CDemo &, int);
};
CDemo CDemo::operator++() {
    n++;
    return * this;
}
CDemo CDemo::operator++(int K) {
    CDemo tmp(*this);
    n++;
    return tmp;
}
CDemo operator--(CDemo & d) {
    d.n--;
    return d;
}
CDemo operator--(CDemo & d, int) {
    CDemo tmp(d);
    d.n --;
    return tmp;
}
operator int() {return n;}

int main() {
    CDemo d(5);
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    cout << (d--) << ",";
    cout << d << ",";
    cout << (--d) << ",";
    cout << d << endl;
    return 0;
}
*/

/*
继承实例程序：学籍管理
#include <iostream>
#include <string>
using namespace std;
class CStudent {
    private:
        string name;
        string id;
        char gender;
        int age;
    public:
        void Printfo();
        void Sentlnfo(const string & name_, const string & id_, int age_, char gender_);
        string GetName() {return name;}

};
class CUndergraduateStudent:public CStudent {
    private:
        string department;
    public:
        void QualifiedForBaoyan() {
            cout << "qualified for baoyan" << endl;
        }
        void Printlnfo() {
            CStudent:Printlnfo();
            cout << "Department:" << department << endl;
        }
        void Setlnfo(const string & name_,const string & id_, int age_, char gender_, const string & department_) {
            CStudent::Setlnfo(name_, id_, age_, gender_);
            department = department_;
        }
};
int main() {
    CUndergraduateStudent s2;
    s2,Setlnfo("Harry Potter", "118829212", 19, "M", "Computer Science");
    cout << s2.GetName() << " ";
    s2.QualifiedForBaoyan();
    s2.Printlnfo();
    return 0;

}
*/

/*写一个小区养狗管理程序，需要写一个“业主类”，还需要写一个“狗”类。狗是有主人的，主人是业主，但是一个业主可以有最多10条狗
#include <iostream>
using namespace std;
class CDog;
class CMaster {
    CDog dogs[10];
};
class CDog{
    CMaster m;
};
*/

/*
为“狗”类设一个“业主”类的成员对象；为“业主”类设一个“狗”类的对象指针数组。
#include <iostream>
using namespace std;
class CDog;
class CMaster {
    CDog * dogs[10];
};
class CDog {
    CMaster m;
};
*/

/*
派生类的构造函数
#include <iostream>
using namespace std;
class Bug {
    private:
        int nLegs; int nColor;
    public:
        int nType;
        Bug(int legs, int color);
        void PrintBug() { };
};
class FlyBug:public Bug{
        int nWings;
    public:
        FlyBug(int legs, int color, int wings);
};
Bug::Bug(int legs, int color) {
    nLegs = legs;
    nColor = color;
}
FlyBug::FlyBug(int legs, int color, int wings) {
    nLegs = legs;
    nColor = color;
    nType = 1;
    nWings = wings;
}
FlyBug::FlyBug(int legs, int color, int wings):Bug(legs, color) {
    nWings = wings;
}
int main() {
    FlyBug fb (2,3,4);
    fb.PrintBug();
    fb.nType = 1;
    fb.nLegs = 2;
    return 0;
}
*/

/*
#include <iostream>
using namespace std;
class Base{
    public:
    int n;
    Base(int i):n(i) {
        cout << "Base" << n << "constructed" << endl;
    }
};
class Derived:public Base {
    public:
        Derived(int):Base(i) {
            cout << "Derived constructed" << endl;
        }
        ~Derived() {
            cout << "Derived destructed" << endl;
        }
};
int main() {
    Derived Obj(3);
    return 0;
}
*/

/*
包含成员对象的派生类的构造函数
#include <iostream>
using namespce std;
class Skill {
    public:
        Skill(int n) {    }
};
class FlyBug:public Bug {
        int nWings;
        Skill sk1, sk2;
    public:
        FlyBug(int legs, int color, int wings);
};
FlyBug::FlyBug(int legs, int color, int wings):
    Bug(legs, color), sk1(5), sk2(color) {
        nWings = wings;
}
*/

/*
多层派生
#include <iostream>
using namespace std;
class Base {
    public:
        int n;
        Base(int i):n(i) {
            cout << "Base" << n << "constructed" << endl;
        }
        ~Base() {
            cout << "Base" << n << "destructed" << endl;
        }
};
class Derived:public Base {
    public:
        Derived(int i):Base(i) {
            cout << "Derived constructed" << endl;
        }
        ~Derived() {
            cout << "Derived destructed" << endl;
        }
};
class MoreDerived:public Derived {
    public:
        MoreDerived():Derived(4) {
            cout << "More Derived destructed" << endl;
        }
        ~MoreDerived() {
            cout << "More Derived destructed" << endl;
        }
};
int main() {
    MoreDerived Obj;
    return 0;
}
*/

/* 多态的表现形式一
#include <iostream>
using namespace std;
class CBase {
    public:
    virtual void SomeVirtualFunction() {}
};
class CDerived:public CBase {
    public:
    virtual void SomeVirtualFunction() {}
};
int main() {
    CDerived ODerived;
    CBase * p = & ODerived;
    p->SomeVirtualFunction();
    return  0;
}
*/

/* 多态的表现形式二
#include <iostream>
using namespace std;
class CBase {
    public:
    virtual void SomeVirtualFunction() {}
};
class CDerived:public CBase {
    public:
    virtual void SomeVirtualFunction() {}
};
int main() {
    CDerived ODerived;
    CBase & r = ODerived;
    r.SomeVirtualFunction();
    return 0;
}
*/

/* 多态的简单示例
#include <iostream>
using namespace std;
class A {
    public:
    virtual void Print() {
        cout << "A::Print" << endl;
    }
};
class B:public A {
    public:
    virtual void Print() {
        cout << "B::Print" << endl;
    }
};
class D:public A {
    public:
    virtual void Print() {
        cout << "D::Print" << endl;
    }
};
class E:public B {
    virtual void Print() {
        cout << "E::Print" << endl;
    }
};
int main() {
    A a; B b; E e; d d;
    A * pa = &a; B * pb = &b;
    D * pd = &d; E * pe = &e;
    pa->Print();
    pa = pb;
    pa -> Print();
    pa = pd;
    pa -> Print();
    pa = pe;
    pa -> Print();
    return 0;
}
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
class CShape {
    public:
        virtual double Area() = 0;
        virtual void PrintInfo() = 0;
};
class CRectangle:public CShape {
    public:
        int w, h;
        virtual double Area();
        virtual void PrintInfo();
};
class CCircle:public CShape {
    public:
        int r;
        virtual double Area();
        virtual void PrintInfo();
};
class CTriangle:public CShape {
    public:
        int a, b, c;
        virtual double Area();
        virtual void PrintInfo();
};
double CRectangle::Area() {
    return w * h;
}
void CRectangle::PrintInfo() {
    cout << "Rentangle:" << Area() << endl;
}
double CCircle::Area() {
    return 3.14 * r * r;
}
void CCircle::PrintInfo() {
    cout << "Circle:" << Area() << endl;
}
double CTriangle::Area() {
    double p = (a + b + c)/2.0;
    return sqrt(p * (p - a)*(p - b)*(p - c));
}
void CTriangle::PrintInfo() {
    cout << "Triangle:" << Area() << endl;
}
CShape * pShapes[100];
int MyCompare(const void * s1, const void * s2);

int main() {
    int i; int n;
    CRectangle * pr; CCircle * pc; CTriangle * pt;
    cin >> n;
    for (i = 0; i < n; i++) {
        char c;
        cin >> c;
        switch(c) {
            case'R':
                pr = new CRectangle();
                cin >> pr->w >> pr->h;
                pShapes[i] = pr;
                break;
            case'C':
                pc = new CCircle();
                cin >> pc->r;
                pShapes[i] = pc;
                break;
            case'T':
                pt = new CTriangle();
                cin >> pt->a >> pt->b >> pt->c;
                pShapes[i] = pt;
                break;
        }
    }
    qsort(pShapes, n, sizeof(CShape *), MyCompare);
    for (i = 0; i < n; i++)
        pShapes[i]->PrintInfo();
    return 0;
}
int MyCompare(const void * s1, const void * s2) {
    double a1, a2;
    CShape * * p1;
    CShape * * p2;
    p1 = (CShape * *)s1;
    p2 = (CShape * *)s2;
    a1 = (*p1)->Area();
    a2 = (*p2)->Area();
    if(a1 < a2)
        return -1;
    else if (a2 < a1)
        return 1;
    else
        return 0;
}