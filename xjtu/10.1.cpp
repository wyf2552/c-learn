#include <iostream>
using namespace std;
class Date{
private:
    int year = 1900;
    int month = 1;
    int day = 1;
public:
    Date() = default;

    Date(int _year, int _month, int _day) {
        year = _year;
        month = _month;
        day = _day;
    }

    Date(int _year, int _month, int _day)
    : year(_year), month(_month), day(_day)
    {}

    void printDate() {
        cout << year << "-" << month << "-" << day << endl;
    }

    void init(int _year, int _month, int _day) {
        year = _year;
        month = _month;
        day = _day;
    }
};

int main() {
    Date d1;
    d1.printDate();
    Date d2(2100, 12, 12);
    d2.printDate();
    int y, m, d;
    cin >> y >> m >> d;
    d1.init(y, m, d);
    d1.printDate();
    return 0;
}