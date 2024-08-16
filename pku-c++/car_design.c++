#include <iostream>

using namespace std;

class automobile {
    private:
        char type[20]; // 汽车型号
        char color[20]; //汽车颜色
        float price;    //价格
        int carry_weight;   //载重量
        int carry_customer; //载客量
    public:
        void set_date(char * t, char * c, float pri, int cw, int cc);   //初始化或修改数据成员
        void movecar(int l, int k); //汽车水平运动K步
        void horming(int num);  // 汽车鸣笛
        void downcar(int l);    //汽车垂直向下运动
        void play_mp3(char * ps);   //播放歌曲
        char * show_type() {return type;}   //取出汽车型号
};

void automobile::set_date(char * t, char * c, float pri, int cw, int cc) {
    strcpy(type, t);
    strcpy(color, c);
    price = pri;
    carry_weight = cw;
    carry_customer = cc;
}

void automobile::movecar(int l, int k) {
    cout << "\n" << type << "水平直线运动：" << endl;
    for (int i = 0; i < l; i++) {
        cout << ' ' << "o_o";
        Sleep(1000/k);
        cout << "\b\b\b";
    }
}

void automobile::downcar(int l) {  //垂直下降运动
    cout << "\n" << type << "垂直下降运动：" << endl;
    for (int i = 0; i < l; i++) {
        cout << "o_o";
        Sleep(500);
        cout << "\b\b\b" << " ";
        cout << endl;
    }
}

void automobile::horming(int num) {
    for (int i = 0; i < num; i++) {
        cout << type;
        cout << '\007' << "di..." << endl;
        Sleep(1000);
    }
}

void automobile::play_mp3(char * ps) {
    char str[100] = "play ";    //play后面有空格
    strcat(str, ps);
    cout << str;
    mciSendString(str, NULL, 0, NULL);
    //在dec-c++环境中还要进行设置：
    //工具\编译器选项\编译器\在连接命令加入以下命令\-lwinmm
    //mciSendStringA(str, NULL, 0, NULL);   //在vc2008调用此函数
    //mciSendString(str, NULL, 0, NULL);    //在vc6.0调用此函数
    char a;
    cin >> a;   //输入任何字符结束播放
}

int main() {
    automobile nison;
    char tp[] = "yyida";
    char ys[] = "white";
    nison.set_date(tp, ys, 200000, 5, 3);   //测试设置初始数据函数
    nison.horming(5);   //测试鸣笛函数
    nison.movecar(10, 3);   //测试水平直线运动
    nison.downcar(8);   //测试垂直下降运动
    char mp[] = "c:\\邓丽君_甜蜜蜜.mp3";    //路径
    nison.play_mp3(mp); //测试播放mp3歌曲函数
    return 0;
}