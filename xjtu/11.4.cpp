#include <iostream>
using namespace std;

class Point{
private:
    int _x, _y;

public:

    int getX() { return _x; }

    int getY() { return _y; }

    Point(int a, int b) {
        setPoint(a, b);
    }

    void setPoint(int a, int b) {
        _x = a;
        _y = b;
    }

    void Print() const {
        cout << "[" << _x << "," << _y << "]";
    }
};

class Circle : public Point {
private:
    double _radius;

public:
    void setRadius(double r) {
        _radius = r;
    }

    Circle(int x = 0, int y = 0,double r = 0.0)
    : Point(x, y) {
        setRadius(r);
    }

    double getRadius() const {
        return _radius;
    }

    double area() const {
        return _radius * _radius * 3.14;
    }

    void Print() const {
        cout << "Circle c Center=";
        Point::Print();
        cout << endl;

        cout << "Radius=" << _radius << endl;

        cout << "The centre of circle c ";
        Point::Print();
        cout << endl;

        cout << "The area of circle c " << area() << endl;
    }
};

int main() {
    int x, y;
    double radius;

    cin >> x >> y;
    Point p(x, y);

    cin >> x >> y >> radius;
    Circle circle(x, y, radius);

    cout << "Point p ";
    p.Print();
    cout << endl;

    circle.Print();
}