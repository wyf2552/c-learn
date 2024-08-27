#include <iostream>
using namespace std;
class Base {
    public:
        int x;
        virtual void f() {
            cout << "base class\n";
        };
        virtual void show() {
            cout << "x=" << x << endl;
        };
        virtual ~Base() {
            cout << "destructor base class\n";
        };
};

class Derived:public Base {
    public:
        int y;
        virtual void f() {
            cin >> y;
            cout << "Derived class\n";
        }
        virtual void show() {
            Base::show();
            cout << "y=" << y << endl;
        }
        ~Derived() {
            cout << "destructor derived class\n";
        }
};

int main() {
    Base * p;
    p = new Derived;
    cin >> p->x;
    p->f();
    p->show();
    delete p;
    return 0;
}