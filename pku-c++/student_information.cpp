#include <iostream>
#include <cstring>

using namespace std;

class Info {    //info类定义
        int Id;
        char Name[20];
        int Programming;
        int Network;
        int Database;
        int Total;
    public:
        void Set_info(int id, char * name, int programming, int network, int database);
        int Get_Pro();
        int Get_Net();
        int Get_Dat();
        int Get_Tol();
        void Show();
};

void Info::Set_info(int id, char * name, int programming, int network, int database) {
    Id = id;
    strcpy(Name, name);
    Programming = programming;
    Network = network;
    Database = database;
    Total = programming + network + database;
}

int Info::Get_Pro() {
    return Programming;
}

int Info::Get_Net() {
    return Network;
}

int Info::Get_Dat() {
    return Database;
}

int Info::Get_Tol() {
    return Total;
}

void Info:: Show() {
    cout << Id << "\t";
    cout << Name << "\t";
    cout << Programming << "\t";
    cout << Network << "\t";
    cout << Database << "\t";
    cout << Total << endl;
}

int main() {
    const int COUNT = 5;
    int i = 0, j = 0;
    int id;
    int name[20];
    int programming;
    int network;
    int database;
    Info student[COUNT], tmp;
    cout << "请输入学生的成绩信息" << endl;
    cout << "学号 姓名 程序设计 计算机网络 数据库" << endl;
    for (i = 0; i < COUNT; i++) {
        cin >> id >> name >> programming >> network >> database;
        student[i].Set_info(id, name, programming, network, database);
    }
    cout << "学号 姓名 程序设计 计算机网络 数据库 总分" << endl;
    for (i =  0; i < COUNT; i++)
        student[i].Show();
}