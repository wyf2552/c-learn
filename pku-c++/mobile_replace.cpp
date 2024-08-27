#include <iostream>
using namespace std;

class mobile {
    public:
        mobile() {}
        char mynumber[11];  //机主的电话号码
        void showinfo() {   //显示制式
            cout << "The phone is mobile" << endl;
        }
};

class mobilegsm:public mobile {
    public:
       mobilegsm() {}
       void showinfo() {    //显示制式
        cout << "The phone is mobliegsm" << endl;
       }
};

class mobilecdma:public mobile {
    public:
        mobilecdma() {}
        void showinfo() {   // 显示制式
            cout << "The phone is mobilecdma" << endl;
        }
};

int main() {
    mobile m, *p1;
    mobilegsm gsm;
    mobilecdma cdma;
    m = gsm;
    m.showinfo();
    m = cdma;
    m.showinfo();
    p1 = &gsm;
    p1->showinfo();
    p1 = &cdma;
    p1->showinfo();
    mobile &p4 = gsm;
    p4.showinfo();
    mobile &p5 = cdma;
    p5.showinfo();
    return 0;
}