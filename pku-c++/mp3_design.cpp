#include <iostream>
using namespace std;
class UDISK {
    private:
        char * crow[100];
        int nrow;
    public:
        UDISK(void) {nrow = 0;}
        void read(void);
        void write(char * pstr);
        ~UDISK() {cout << "撤销U盘对象" << endl;}
};
void UDISK::read(void) {
    for (int i = 0; i < nrow; i++) cout << crow[i] << endl;
}

void UDISK::write(char * pstr) {
    crow[nrow] = pstr;
    nrow++;
}
class MP3:public UDISK {
    public:
        MP3():UDISK() {};
        void play(char  * pstr);
        ~MP3() {cout << "撤销MP3对象" << endl;}
};

void mciSendStringA(char* ptr, void* a, int b, void* c) { }

void MP3::play(char * pstr) {
    char str[100] = "play";
    strcat(str, pstr);
    cout << str;
    mciSendStringA(str, NULL, 0, NULL);
}

int main() {
    UDISK U1;
    cout << "--模拟U盘写--" << endl;
    U1.write("劝学");
    U1.write("三更灯火五更鸣，");
    U1.write("正是男儿读书时。");
    U1.write("黑发不知勤学早，");
    U1.write("白首方悔读书迟。");
    cout << "--模拟U盘读书迟--" << endl;
    U1.read();
    MP3 M1;
    cout << "--模拟MP3播放--" << endl;
    M1.play("c:\\邓丽君_甜蜜蜜.mp3");
    char a;
    cin >> a;
    return 0;
}