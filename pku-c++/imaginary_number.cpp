#include <iostream>
using namespace std;
class Complex {
    private:
        double real, imag;
    public:
        Complex(double r = 0, double i = 0): real(r), imag(i) {}
        double Real() {return real;}
        double Imag() {return imag;}
        Complex operator + (Complex&);
        Complex operator + (double);
        bool operator == (Complex);
        ~Complex() {};
};

Complex Complex::operator + (Complex &c) {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator + (double d) {
    Complex temp;
    temp.real = real + d;
    temp.imag = imag;
    return temp;
}

bool Complex::operator == (Complex c) {
    if(real == c.real && imag == c.imag)
        return true;
    else
        return false;
}

int main() {
    Complex c1(3, 4), c2(5, 6), c3;
    cout << "C1 =" << c1.Real() << "+j" << c1.Imag() << endl;
    cout << "C2 =" << c2.Real() << "+j" << c2.Imag() << endl;
    c3 = c1 + c2;
    cout << "C3 =" << c3.Real() << "+j" << c3.Imag() << endl;
    c3 = c3 + 6.5;
    cout << "C3 + 6.5 =" << c3.Real() << "+j" << c3.Imag() << endl;
    if (c1 == c2)
        cout << "两个复数相等";
    else
        cout << "两个复数不相等";
    return 0;

}