#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// 定义歌手信息结构体
struct Singer {
    string number;      // 歌手编号
    string name;        // 姓名
    string songName;    // 比赛曲目
    int publicVotes;    // 大众评委投票数
    int scores[5];      // 5个专业评委打分
    double totalScore;  // 总分
};

// 全局变量
const int MAX_SINGERS = 100;  // 最多存储100个歌手
Singer singers[MAX_SINGERS];  // 歌手数组
int singerCount = 0;          // 当前歌手数量
const string FILENAME = "singers.txt";  // 文件名

// 函数声明
void inputSinger();           // 输入歌手信息
void outputAllSingers();      // 输出所有歌手信息
void sortByScore();           // 成绩排序
void saveToFile();            // 保存到文件
void loadFromFile();          // 从文件加载
void querySinger();           // 查询歌手信息
void deleteSinger();          // 删除歌手信息
void displayMenu();           // 显示菜单
double calculateTotal(Singer& s); // 计算总分

// 主函数
int main() {
    loadFromFile();  // 程序启动时加载数据
    while (true) {
        displayMenu();
        int choice;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputSinger();
                break;
            case 2:
                outputAllSingers();
                break;
            case 3:
                sortByScore();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                querySinger();
                break;
            case 6:
                deleteSinger();
                break;
            case 0:
                saveToFile();  // 退出前保存数据
                cout << "感谢使用，再见！" << endl;
                return 0;
            default:
                cout << "无效的选择，请重试！" << endl;
        }
    }
    return 0;
}

// 显示菜单
void displayMenu() {
    cout << "\n=== 我是歌手比赛打分系统 ===" << endl;
    cout << "1. 输入歌手信息" << endl;
    cout << "2. 输出所有歌手信息" << endl;
    cout << "3. 成绩排序" << endl;
    cout << "4. 保存歌手信息" << endl;
    cout << "5. 查询歌手信息" << endl;
    cout << "6. 删除歌手信息" << endl;
    cout << "0. 退出系统" << endl;
}

// 计算总分
double calculateTotal(Singer& s) {
    double sum = s.publicVotes;
    for (int i = 0; i < 5; i++) {
        sum += s.scores[i];
    }
    return sum / 6.0;
}

// 输入歌手信息
void inputSinger() {
    if (singerCount >= MAX_SINGERS) {
        cout << "歌手数量已达到上限！" << endl;
        return;
    }

    Singer newSinger;
    cout << "请输入歌手编号：";
    cin >> newSinger.number;

    // 检查编号是否重复
    for (int i = 0; i < singerCount; i++) {
        if (singers[i].number == newSinger.number) {
            cout << "该编号已存在！" << endl;
            return;
        }
    }

    cout << "请输入歌手姓名：";
    cin >> newSinger.name;
    cout << "请输入比赛曲目：";
    cin.ignore();
    getline(cin, newSinger.songName);

    do {
        cout << "请输入大众评委投票数(0-100):";
        cin >> newSinger.publicVotes;
    } while (newSinger.publicVotes < 0 || newSinger.publicVotes > 100);

    cout << "请输入5个专业评委的打分(0-100):" << endl;
    for (int i = 0; i < 5; i++) {
        do {
            cout << "评委" << (i+1) << "的打分：";
            cin >> newSinger.scores[i];
        } while (newSinger.scores[i] < 0 || newSinger.scores[i] > 100);
    }

    newSinger.totalScore = calculateTotal(newSinger);
    singers[singerCount++] = newSinger;
    cout << "歌手信息添加成功！" << endl;
}

// 显示单个歌手信息
void displaySinger(const Singer& s) {
    cout << "\n歌手信息:" << endl;
    cout << "编号：" << s.number << endl;
    cout << "姓名：" << s.name << endl;
    cout << "比赛曲目：" << s.songName << endl;
    cout << "大众评委投票：" << s.publicVotes << endl;
    cout << "专业评委打分：";
    for (int i = 0; i < 5; i++) {
        cout << s.scores[i] << " ";
    }
    cout << "\n总分:" << fixed << setprecision(2) << s.totalScore << endl;
}

// 输出所有歌手信息
void outputAllSingers() {
    if (singerCount == 0) {
        cout << "暂无歌手信息！" << endl;
        return;
    }

    for (int i = 0; i < singerCount; i++) {
        displaySinger(singers[i]);
    }
}

// 成绩排序（使用冒泡排序）
void sortByScore() {
    if (singerCount == 0) {
        cout << "暂无歌手信息！" << endl;
        return;
    }

    // 冒泡排序
    for (int i = 0; i < singerCount - 1; i++) {
        for (int j = 0; j < singerCount - 1 - i; j++) {
            if (singers[j].totalScore < singers[j + 1].totalScore) {
                Singer temp = singers[j];
                singers[j] = singers[j + 1];
                singers[j + 1] = temp;
            }
        }
    }

    cout << "\n排序后的歌手排名:" << endl;
    cout << "  排名    编号         姓名         比赛曲目      总分" << endl;

    for (int i = 0; i < singerCount; i++) {
        cout << "   " << (i+1)           // 排名
             << "      " << singers[i].number    // 编号
             << "         " << singers[i].name   // 姓名
             << "         " << singers[i].songName  // 比赛曲目
             << "         " << fixed << setprecision(2) << singers[i].totalScore << endl;  // 总分
    }
}

// 保存到文件
void saveToFile() {
    ofstream file(FILENAME);
    if (file.is_open()) {
        file << singerCount << endl;
        for (int i = 0; i < singerCount; i++) {
            file << singers[i].number << endl;
            file << singers[i].name << endl;
            file << singers[i].songName << endl;
            file << singers[i].publicVotes << endl;
            for (int j = 0; j < 5; j++) {
                file << singers[i].scores[j] << " ";
            }
            file << endl;
            file << singers[i].totalScore << endl;
        }
        file.close();
        cout << "数据保存成功！" << endl;
    } else {
        cout << "无法打开文件进行保存！" << endl;
    }
}

// 从文件加载
void loadFromFile() {
    ifstream file(FILENAME);
    if (file.is_open()) {
        file >> singerCount;
        file.ignore(); // 忽略换行符

        for (int i = 0; i < singerCount; i++) {
            getline(file, singers[i].number);
            getline(file, singers[i].name);
            getline(file, singers[i].songName);
            file >> singers[i].publicVotes;
            for (int j = 0; j < 5; j++) {
                file >> singers[i].scores[j];
            }
            file >> singers[i].totalScore;
            file.ignore(); // 忽略换行符
        }
        file.close();
        cout << "数据加载成功！" << endl;
    }
}

// 查询歌手信息
void querySinger() {
    string number;
    cout << "请输入要查询的歌手编号：";
    cin >> number;

    for (int i = 0; i < singerCount; i++) {
        if (singers[i].number == number) {
            displaySinger(singers[i]);
            return;
        }
    }
    cout << "未找到该编号的歌手！" << endl;
}

// 删除歌手信息
void deleteSinger() {
    string number;
    cout << "请输入要删除的歌手编号：";
    cin >> number;

    for (int i = 0; i < singerCount; i++) {
        if (singers[i].number == number) {
            // 将后面的歌手信息前移
            for (int j = i; j < singerCount - 1; j++) {
                singers[j] = singers[j + 1];
            }
            singerCount--;
            cout << "歌手删除成功！" << endl;
            return;
        }
    }
    cout << "未找到该编号的歌手！" << endl;
}