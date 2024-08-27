#include <iostream>
using namespace std;
class Point {
        int x, y;   //点的x和y坐标
    public:
        Point(int = 0; int = 0);    //构造函数
        void SetPoint(int, int);    //设置坐标
        int GetX() {return x;}  //取x坐标
        int GetY() {return y;}  //取y坐标
        void Print();   //输出点的坐标
};

Point::Point(int a, int b) {SetPoint(a, b);}
void Point::SetPoint(int a, int b) {
    x = a;
    y = b;
}
void Point::Print() {cout << '[' << x << "," << y <<']';}

class Circle:public Point {
        double radius;
    public:
        Circle(int x = 0, int y = 0, double r = 0.0);
        void SetRadius(double);
        double GetRadius();
        double Area();
        void Print();
};

Circle::Circle(int a, int b, double r):Point(a, b) {SetRadius(r);}
void Circle::SetRadius(double r) {radius = (r >= 0 ? r : 0);}
double Circle::GetRadius() {return radius;}
double Circle::Area() {return 3,14159 * radius * radius;}
void Circle::Print() {
    cout << "Center=";
    Point::Print();
    cout << ";Radius =" << radius << endl;
}

class Cylinder:public Circle {
        double high;
    public:
        Cylinder(int x, int y, double r, double h);
        void Set_data(int x, int y, double r, double h);
        double Area();
        double Volume();
        void Print();
};
Cylinder::Cylinder(int x, int y, double r, double h):Circle(x, y, r) {high = h;}
void Cylinder::Set_data(int x, int y, double r, double h) {
    SetPoint(x, y);
    SetRadius(r);
    high = h;
}
double Cylinder::Volume() {
    return Circle::Area() * high;
}
double Cylinder::Area() {
    double r = GetRadius();
    return 2 * 3.14159 * r * r + 2 * 3.1415 * r * high;
}

int main() {
    cout << "测试点类" << endl;
    point p(30, 50);
    p.Print();
    cout << endl;
    system("pause");
    cout << endl << endl << "测试圆类" << endl;
    Circle c(120, 80, 10.0);
    cout << "圆心：";
    c.Point::Print();
    cout << "\n圆面积：" << c.Area() << endl;
    system("pause");
    cout << endl << "测试圆柱体类" << endl;
    Cylinder cy(240, 160, 10.0, 10.0);
    cout << "圆柱体中心点：";
    cy.Point::Print();
    cout << "\n圆柱体圆面积：" << cy.Circle::Area() << endl;
    cout << "圆柱体表面积：" << cy.Area() << endl;
    cout << "圆柱体体积：" << cy.Volume() << endl;
    return 0;
}