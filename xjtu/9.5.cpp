#include <iostream>
using namespace std;

class Weekday {
private:
    int data;
public:
    void SetDay() {
        cin >> data;
    }
    void IncDay() {
        data++;
        data %= 7;
    }
    void NowDay() {
        switch(data) {
            case 0:
                cout << "星期日" << endl;
                break;
            case 1:
                cout << "星期一" << endl;
                break;
            case 2:
                cout << "星期二" << endl;
                break;
            case 3:
                cout << "星期三" << endl;
                break;
            case 4:
                cout << "星期四" << endl;
                break;
            case 5:
                cout << "星期五" << endl;
                break;
            case 6:
                cout << "星期六" << endl;
                break;
        }
    }
};

int main() {
    Weekday day;
    day.SetDay();
    for (int i = 0; i < 3; i++) {
        day.NowDay();
        day.IncDay();
    }
    return 0;
}