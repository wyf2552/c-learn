#include <iostream>
#include <time.h>

using namespace std;

class Date {
    private:
        int year,month,day;
        void SetSystemDate(); //取得系统日期
    public:
        void init(int, int, int); //设置年月日数据
        void print_ymd(); //显示年月日
        void print_mdy(); // 显示月日年
        int get_year() {return year;} //得到年份值
        int get_month() {return month;} // 得到月份值
        int get_day() {return day;}   //得到日值
        bool IsLeapYear(); //判断是否为闰年
};

void Date::SetSystemDate() { //取得系统日期
    tm * gm; //tm是时间（含年月日时分秒）结构体
    time_t t = time(NULL); // time_t是长整型，t表示（总秒数）
    gm = gmtime(&t);
    year = 1900 + gm->tm_year;
    month = gm->tm_mon + 1;
    day = gm->tm_mday;
}

void Date::init (int yy, int mm, int dd) {
    if (yy >= 1900 && yy <= 9999)
        year = yy;
    else {
        SetSystemDate();
        return;
    }

    if (mm >= 1 && mm <= 12)
        month = mm;
    else {
        SetSystemDate();
        return;
    }

    if (dd >= 1 && dd <= 31)
        day = dd;
    else {
        SetSystemDate();
        return;
    }
}

void Date::print_ymd() {
    cout << year << "-" << month << "-" << day << endl;
}

void Date::print_mdy() {
    cout << month << "-" << day << "-" << year << endl;
}

bool Date::IsLeapYear() {
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    } else {
        return false;
    }
}

int main () {
    Date date1;
    date1.print_ymd();
    system("pause");
    date1.init(2008, 3, 28);
    date1.print_ymd();
    system("pause");
    Date date2;
    date2.init(2006, 13, 28);
    date2.print_mdy();
    system("pause");
    if (date1.IsLeapYear())
        cout << date1.get_year() << "是闰年" << endl;
    else
        cout << date1.get_year() << "不是闰年" << endl;

    return 0;
}