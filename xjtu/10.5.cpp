#include <iostream>
#include <iomanip>

using namespace std;

class MyTime {
private:
    int _hour = 0;
    int _minute = 0;
    int _seconds = 0;

private:
    void convert(int number) const {
        if (number < 10) {
            // std::cout << std::setw(2) << std::setfill('0') << number;
            printf("%02d", number);
        } else {
            std::cout << number;
        }
    }

public:
    MyTime() = default;

    MyTime(int h, int m, int s)
    : _hour(h), _minute(m), _seconds(s)
    {}

    void set(int h, int m, int s) {
        _hour = ((h >= 0) && (h <= 23) ? h : 0);
        _minute = ((m >= 0) && (m <= 59) ? m : 0);
        _seconds = ((s >= 0) && (s <= 59) ? s : 0);
    }

    void add(int h, int m, int s) {
        _seconds += s;
        _minute += _seconds / 60;
        _seconds %= 60;

        _minute += m;
        _hour += _minute / 60;
        _minute %= 60;

        _hour += h;
    }

    void sub(int h, int m, int s) {
        // 将两个时间都转换为秒
        int seconds1 = h * 3600 + m * 60 + s;
        int seconds2 = _hour * 3600 + _minute * 60 + _seconds;

        // 计算差值
        int secondsDiff = seconds2 - seconds1;

        // 如果差值为负，加上一天的秒数
        if (secondsDiff < 0) {
            secondsDiff += 24 * 3600;
        }

        // 将差值转换回时分秒
        _hour = secondsDiff / 3600;
        secondsDiff %= 3600;
        _minute = secondsDiff / 60;
        _seconds = secondsDiff % 60;
    }

    void show12() const {
        if (_hour < 12) {
            convert(_hour);
            cout << ':';
            convert(_minute);
            cout << ':';
            convert(_seconds);
            cout << " AM" << endl;
        } else {
            convert(_hour % 12 );
            cout << ':';
            convert(_minute);
            cout << ':';
            convert(_seconds);
            cout << " PM" << endl;
        }
    }

    void show24() const {
        convert(_hour);
        cout << ':';
        convert(_minute);
        cout << ':';
        convert(_seconds);
        cout << endl;
    }
};

int main() {
    int t1h, h;
    int t1m, m;
    int t1s, s;
    cin >> t1h >> t1m >> t1s;
    cin >> h >> m >> s;

    MyTime t1, t2(8, 10, 30), t3;
    t1.show12();
    t1.show24();
    t2.show12();
    t2.show24();

    t1.set(t1h, t1m, t1s);
    t1.add(h, m, s);
    t1.show12();
    t1.show24();

    t2.sub(h, m, s);
    t2.show12();
    t2.show24();

    return 0;
}