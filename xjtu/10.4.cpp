#include <iostream>
using namespace std;

class Ellipse{
private:
    int x, y;
    double a, b, s;
public:
    Ellipse (int _x, int _y, double _a, double _b)
    : x(_x), y(_y), a(_a), b(_b) {}

    double Area() {
        s = 3.14 * a * b;
        return s;
    }
};

int main() {
    int x1, y1;
    double a1, b1, s1;
    cin >> x1 >> y1 >> a1 >> b1;
    Ellipse e(x1, y1, a1, b1);
    cout << e.Area() << endl;
    return 0;
}