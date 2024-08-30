#include <iostream>
#include <cstring>
using namespace std;

class Info { // info类定义
    int Id;
    char Name[20];
    int Programming;
    int Network;
    int Database;
    int Total;
public:
    void Set_info(int id, const char* name, int programming, int network, int database);
    int Get_Pro() const;
    int Get_Net() const;
    int Get_Dat() const;
    int Get_Tol() const;
    void Show() const;
};

void Info::Set_info(int id, const char* name, int programming, int network, int database) {
    Id = id;
    strncpy(Name, name, sizeof(Name) - 1);
    Name[sizeof(Name) - 1] = '\0';
    Programming = programming;
    Network = network;
    Database = database;
    Total = programming + network + database;
}

int Info::Get_Pro() const {
    return Programming;
}

int Info::Get_Net() const {
    return Network;
}

int Info::Get_Dat() const {
    return Database;
}

int Info::Get_Tol() const {
    return Total;
}

void Info::Show() const {
    cout << Id << "\t" << Name << "\t" << Programming << "\t"
         << Network << "\t" << Database << "\t" << Total << endl;
}

int main() {
    const int COUNT = 5;
    Info student[COUNT];
    int id;
    char name[20];
    int programming;
    int network;
    int database;

    cout << "请输入学生的成绩信息" << endl;
    cout << "学号 姓名 程序设计 计算机网络 数据库" << endl;
    for (int i = 0; i < COUNT; i++) {
        cin >> id >> name >> programming >> network >> database;
        student[i].Set_info(id, name, programming, network, database);
    }

    cout << "学号 姓名 程序设计 计算机网络 数据库 总分" << endl;
    for (int i = 0; i < COUNT; i++)
        student[i].Show();

    return 0;
}