#include <iostream>
using namespace std;

class MyTime {
private:
    int hour;
    int min;
    int sed;
public:
    void SetTime(int h, int m, int s) {
        hour = h;
        min = m;
        sed = s;
    }
    void print_12() {
        if (hour < 12) {
            cout << hour << ':' << min << ":" << sed << " " << "AM" << endl;
        }
        else {
            cout << hour % 12 << ":" << min << ":" << sed << " " << "PM" << endl;
        }
    }
    void print_24() {
        cout << hour << ":" << min << ":" << sed << endl;
    }
};

int main() {
    int h, m, s;
    cin >> h >> m >> s;
    MyTime time;
    time.SetTime(h, m, s);
    time.print_12();
    time.print_24();
    return 0;
}