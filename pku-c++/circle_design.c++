#include <iostream>

using namespace std;
class Point {
        int x, y;
    public:
        void InitPoint(int, int);
        int GetX() {return x;}
        int GetY() {return y;}
        void Print();
};

void Point::InitPoint(int a, int b) {
    x = a;
    y = b;
}

void Point::Print() {
    cout << '[' << x << "," << y << ']';
}

class Circle { //圆类定义
    private:
        double radius;  //定义半径对象（变量）
        Point Center;   //定义圆心对象（变量）
    public:
        void InitCircle(double, Point); //设置圆类的数据
        double GetRadius(); //取半径
        Point GetCenter();  //取圆心
        double Area();  //计算面积a
        void Print();   //输出圆心坐标和半径
};

void Circle::InitCircle(double r, Point p) {
    radius = (r >= 0 ? r : 0);
    Center = p;
}

double Circle::GetRadius() {return radius;}
Point Circle::GetCenter() {return Center;}
double Circle::Area() {return 3.14159 * radius * radius;}
void Circle::Print() {
    cout << "Center =";
    Center.Print();
    cout << "; Radius = " << radius << endl;
}

int main () {
    Point p, center;
    p.InitPoint(30, 50);
    center.InitPoint(120, 80);
    Circle c;
    c.InitCircle(10.0, center);

    cout << "Point p:";
    p.Print();
    cout << endl;
    cout << "Circle c:";
    c.Print();
    cout << "The center of circle c:";
    c.GetCenter().Print();
    cout << "\nThe area of circle c:" << c.Area() << endl;
    return 0;
}