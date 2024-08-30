#include <iostream>
using namespace std;
class Date {
        int year, month, day;
    public:
        Date(int y = 1900, int m = 1, int d = 1) {
            year = y; month = m; day = d;
        }
        void init(int, int, int);
        void print_ymd();
        void print_mdy();
        bool operator > (Date &dd);
        ~Date() {};
};

bool Date::operator > (Date &dd) {
    if (year > dd.year)
        return true;
    else if (year != dd.year)
        return false;
    else if (month > dd.month)
        return true;
    else if (month != dd.month)
        return false;
    else if (day > dd.day)
        return false;
}

void Date::init(int yy, int mm, int dd) {
    month = (mm >= 1 && mm <= 12) ? mm : 1;
    year = (yy >= 1900 && yy <= 9999) ? yy : 1900;
    day = (dd >= 1 && dd <= 31) ? dd : 1;
};

void Date::print_ymd() {
    cout << year << "-" << month << "-" << day << endl;
}

void Date::print_mdy() {
    cout << month << "-" << day << "-" << year << endl;
}

int main() {
    Date date1(2011, 5, 27);
    Date date2(2013, 11, 26);
    Date date3(2013, 7, 26);
    Date date4(2013, 11, 26);
    if (date1 > date2)
        cout << "date1大于date2" << endl;
    else
        cout << "date1小于等于date2" << endl;
    if (date2 > date3)
        cout << "date2大于date3" << endl;
    else
        cout << "date2小于等于date3" << endl;
    if (date2 > date4)
        cout << "date2大于date4" << endl;
    else
        cout << "date2小于等于date4" << endl;
    return 0;
}