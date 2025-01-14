#include <iostream>

using namespace std;

class Plural {
private:
    int real, imag;

public:
    Plural(int r = 0, int i = 0) : real(r), imag(i) {}

    Plural operator+(const Plural& other) {
        return Plural(real + other.real, imag + other.imag);
    }

    friend Plural operator+(const Plural& c1, const Plural& c2) {
        return Plural(c1.real + c2.real, c1.imag + c2.imag);
    }

    friend ostream& operator<<(ostream& out, const Plural& c) {
        out << c.real << "+j" << c.imag;
        return out;
    }
};

int main() {
    int r, i;

    cin >> r >> i;
    Plural c1(r, i);

    cin >> r >> i;
    Plural c2(r, i);

    Plural c3 = c1 + c2 + c1;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
}