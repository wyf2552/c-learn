#include <iostream>

using namespace std;

class Shape {
public:
    virtual void printName() = 0;
    virtual double printArea() = 0;
};

class Circle : public Shape {
private:
    double r;

public:
    Circle(double _r) : r(_r) {}

    virtual void printName() override {
        cout << "yuan:banjing=" << r << ",";
    }

    virtual double printArea() override {
        double pi = 3.14159;
        cout << "mianji:" << pi * r * r << endl;
        return pi * r * r;
    }
};

class Square : public Shape {
private:
    double d;

public:
    Square(double _d) : d(_d) {}

    virtual void printName() override {
        cout << "bianchang=" << d << ",";
    }

    virtual double printArea() override {
        cout << "mianji:" << d * d << endl;
        return d * d;
    }
};

class Rectangle : public Shape {
private:
    double d, l;

public:
    Rectangle(double _d, double _l) : d(_d), l(_l) {}

    virtual void printName() override {
        cout << "chang:chang=" << d << ",kuan=" << l << ",";
    }

    virtual double printArea() override {
        cout << "mianji:" << d * l << endl;
        return d * l;
    }
};

class Trapezoid : public Shape {
private:
    double d, l, h;

public:
    Trapezoid(double _d, double _l, double _h)
    : d(_d), l(_l), h(_h) {}

    virtual void printName() override {
        cout << "tixin:shang=" << d << ",xiadi=" << l << ",gao=" << h << ",";
    }

    virtual double printArea() override {
        cout << "mianji:" << (d + l) * h / 2 << endl;
        return (d + l) * h / 2;
    }
};

class Triangle : public Shape {
private:
    double d, h;

public:
    Triangle(double _d, double _h) : d(_d), h(_h) {}

    virtual void printName() override {
        cout << "sanjiaoxing:dibian=" << d << ",gao=" << h << ",";
    }

    virtual double printArea() override {
        cout << "mianji:" << d * h /2 << endl;
        return d * h / 2;
    }
};

int main() {
    Shape* s[5];

    double r;
    cin >> r;
    s[0] = new Circle(r);

    double d;
    cin >> d;
    s[1] = new Square(d);

    double l;
    cin >> d >> l;
    s[2] = new Rectangle(d, l);

    double h;
    cin >> d >> l >> h;
    s[3] = new Trapezoid(d, l, h);

    cin >> d >> h;
    s[4] = new Triangle(d, h);

    double totalArea = 0;
    for(int i = 0; i < 5; i++) {
        s[i]->printName();
        totalArea += s[i]->printArea();
        delete s[i];
    }
    cout << "zong:" << totalArea << endl;
    return 0;
}