#include <iostream>
using namespace std;

class Trapezium {
private:
    int _x1, _y1, _x2, _y2;
    int  _x3, _y3,_x4, _y4;
public:
    void intial(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        _x1 = x1;
        _y1 = y1;
        _x2 = x2;
        _y2 = y2;
        _x3 = x3;
        _y3 = y3;
        _x4 = x4;
        _y4 = y4;
    }
    void GetPosition(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4) {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        x3 = _x3;
        y3 = _y3;
        x4 = _x4;
        y4 = _y4;
    }
    double Area() {
       double a = (_x2 - _x1 + _x4 - _x3) * (_y1 - _y3)/2;
       return a;
    }

};

int main() {
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    Trapezium t;
    t.intial(a, b, c, d, e, f, g, h);
    cout << t.Area() << endl;
    return 0;
}