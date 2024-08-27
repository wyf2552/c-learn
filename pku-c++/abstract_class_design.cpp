#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.1415926
class Shape {
    public:
        virtual double area() = 0;
        virtual double circumference() = 0;
};

class Rectangle:public Shape {
        int x, y;
        int width, hight;
    public:
        Rectangle(int x, int y, int w, int h) {
            this->x = x; this->y = y;
            width = w; hight = h;
        }
        virtual double area() {
            return width * hight;
        }
        virtual double circumference() {
            return 2.0 * (width + hight);
        }
};

class Circle:public Shape {
        int x, y;
        int r;
    public:
        Circle(int x, int y, int r) {
            this->x = x; this->y = y; this->r = r;
        }
        virtual double area() {
            return PI * r * r;
        }
        virtual double circumference() {
            return 2.0 * PI * r;
        }
};

int main() {
    Rectangle r1(10, 10, 10, 5);
    Circle c1(1, 2, 1);
    Shape * p1 = &r1, &p2 = c1;
    cout << "长方形面积："  << p1->area() << endl;
    cout << "长方形周长：" << p1->circumference() << endl;
    cout << "圆面积：" << p2.area() << endl;
    cout << "圆周长：" << p2.circumference() << endl;
}