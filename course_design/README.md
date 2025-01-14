#include <iostream> //输入输出流
#include <fstream>  //文件流
#include <sstream>  //字符串流
#include <vector>   //向量容器
#include <string>   //字符串
#include <algorithm>    //算法库
#include <iomanip>  //输入输出格式控制
#include <cstdlib>  //标准库
#include <map>  //map容器
#include <functional>   //函数对象
#include <ctime>    //时间

using namespace std;

// 定义学生信息结构体，包含姓名、学号和各科成绩
struct Student {
    string name;          // 姓名
    string id;           // 学号
    double dataStructure; // 数据结构
    double dsProject;     // 数据结构课设
    double cpp;          // C++
    double c;            // C语言
    double math1;        // 高数1
    double english1;     // 大学英语1
    double linearAlg;    // 线性代数
    double intro;        // 专业导论
    double average;      // 平均分
};

// 成绩分析系统
class GradeAnalyzer {
private:
    vector<Student>& students;  //学号向量引用

    //根据分数获取等级
    string getGradeLevel(double score) {
        if (score >= 90) return "优秀";
        if (score >= 80) return "良好";
        if (score >= 70) return "中等";
        if (score >= 60) return "及格";
        return "不及格";
    }

public:
    //构造函数，传入学生向量引用
    GradeAnalyzer(vector<Student>& studs) : students(studs) {}

    //显示课程分数分布
    void showCourseDistribution(const string& courseName,
        const vector<double>& scores) {
        //使用map统计各等级人数
        map<string, int> distribution;
        distribution["优秀"] = 0;
        distribution["良好"] = 0;
        distribution["中等"] = 0;
        distribution["及格"] = 0;
        distribution["不及格"] = 0;

        //统计每个分数的等级
        for (double score : scores) {
            distribution[getGradeLevel(score)]++;
        }

        //输出分布情况
        cout << "\n" << courseName << "成绩分布:" << endl;
        cout << "优秀(90-100):" << distribution["优秀"] << "人 ("
             << fixed << setprecision(2) << (100.0 * distribution["优秀"] / scores.size()) << "%)" << endl;
        cout << "良好(80-89):" << distribution["良好"] << "人 ("
             << (100.0 * distribution["良好"] / scores.size()) << "%)" << endl;
        cout << "中等(70-79):" << distribution["中等"] << "人 ("
             << (100.0 * distribution["中等"] / scores.size()) << "%)" << endl;
        cout << "及格(60-69):" << distribution["及格"] << "人 ("
             << (100.0 * distribution["及格"] / scores.size()) << "%)" << endl;
        cout << "不及格(0-59):" << distribution["不及格"] << "人 ("
             << (100.0 * distribution["不及格"] / scores.size()) << "%)" << endl;
    }

    //分析所有课程
    void analyzeAllCourses() {
        vector<pair<string, vector<double>>> coursesData = {
            {"数据结构", {}},
            {"数据结构课设", {}},
            {"C++", {}},
            {"C语言", {}},
            {"高数1", {}},
            {"大学英语1", {}},
            {"线性代数", {}},
            {"专业导论", {}}
        };

        //收集每门课程的成绩
        for (const auto& student : students) {
            coursesData[0].second.push_back(student.dataStructure);
            coursesData[1].second.push_back(student.dsProject);
            coursesData[2].second.push_back(student.cpp);
            coursesData[3].second.push_back(student.c);
            coursesData[4].second.push_back(student.math1);
            coursesData[5].second.push_back(student.english1);
            coursesData[6].second.push_back(student.linearAlg);
            coursesData[7].second.push_back(student.intro);
        }

        //分析每门课程
        for (const auto& course : coursesData) {
            showCourseDistribution(course.first, course.second);
        }
    }
};

// 成绩修改系统
class GradeModifier {
private:
    vector<Student>& students;

    //显示修改菜单
    void showModifyMenu() {
        cout << "\n请选择要修改的科目:" << endl;
        cout << "1. 数据结构" << endl;
        cout << "2. 数据结构课设" << endl;
        cout << "3. C++" << endl;
        cout << "4. C语言" << endl;
        cout << "5. 高数1" << endl;
        cout << "6. 大学英语1" << endl;
        cout << "7. 线性代数" << endl;
        cout << "8. 专业导论" << endl;
        cout << "0. 返回上级菜单" << endl;
    }

    //判断成绩是否有效
    bool isValidGrade(double grade) {
        return grade >= 0 && grade <= 100;
    }

public:
    GradeModifier(vector<Student>& studs) : students(studs) {}

    //修改学生成绩
    void modifyStudentGrade(const string& studentId) {
        //查找学生
        auto it = find_if(students.begin(), students.end(),
            [&studentId](const Student& s) { return s.id == studentId; });

        if (it == students.end()) {
            cout << "未找到该学生!" << endl;
            return;
        }

        //修改成绩循环
        while (true) {
            showModifyMenu();

            int choice;
            cout << "请输入选项(0-8): ";
            cin >> choice;

            if (choice == 0) break;

            double newGrade;
            cout << "请输入新成绩(0-100): ";
            cin >> newGrade;

            if (!isValidGrade(newGrade)) {
                cout << "成绩无效!请输入0-100之间的数值." << endl;
                continue;
            }

            switch(choice) {
                case 1: it->dataStructure = newGrade; break;
                case 2: it->dsProject = newGrade; break;
                case 3: it->cpp = newGrade; break;
                case 4: it->c = newGrade; break;
                case 5: it->math1 = newGrade; break;
                case 6: it->english1 = newGrade; break;
                case 7: it->linearAlg = newGrade; break;
                case 8: it->intro = newGrade; break;
                default: cout << "无效的选择!" << endl; continue;
            }

            it->average = (it->dataStructure + it->dsProject + it->cpp +
                          it->c + it->math1 + it->english1 +
                          it->linearAlg + it->intro) / 8.0;

            cout << "成绩修改成功!" << endl;
            cout << "\n更新后的成绩:" << endl;
            cout << "数据结构: " << it->dataStructure << endl;
            cout << "数据结构课设: " << it->dsProject << endl;
            cout << "C++: " << it->cpp << endl;
            cout << "C语言: " << it->c << endl;
            cout << "高数1: " << it->math1 << endl;
            cout << "大学英语1: " << it->english1 << endl;
            cout << "线性代数: " << it->linearAlg << endl;
            cout << "专业导论: " << it->intro << endl;
            cout << "最新平均分: " << fixed << setprecision(2) << it->average << endl;
        }
    }
};

// 成绩排序系统
class GradeSorter {
private:
    vector<Student>& students;

    // 1. 快速排序算法
    void quickSort(vector<Student>& arr, int low, int high,
                  function<double(const Student&)> getScore) {
        if (low < high) {
            double pivot = getScore(arr[high]);
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (getScore(arr[j]) >= pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);

            int pi = i + 1;
            quickSort(arr, low, pi - 1, getScore);
            quickSort(arr, pi + 1, high, getScore);
        }
    }

    // 2. 新增：希尔排序算法
    void shellSort(vector<Student>& arr, function<double(const Student&)> getScore) {
        int n = arr.size();
        for (int gap = n/2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Student temp = arr[i];
                int j;
                for (j = i; j >= gap && getScore(arr[j - gap]) <
                    getScore(temp); j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    // 3. 新增：归并排序的合并函数
    void merge(vector<Student>& arr, int left, int mid, int right,
              function<double(const Student&)> getScore) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Student> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (getScore(L[i]) >= getScore(R[j])) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // 4. 新增：归并排序的递归函数
    void mergeSortHelper(vector<Student>& arr, int left, int right,
                        function<double(const Student&)> getScore) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortHelper(arr, left, mid, getScore);
            mergeSortHelper(arr, mid + 1, right, getScore);
            merge(arr, left, mid, right, getScore);
        }
    }

public:
    GradeSorter(vector<Student>& studs) : students(studs) {}

    // 5. 修改后的排序方法
    void sortByCourse(int courseChoice) {
        vector<Student> sortedStudents = students;
        function<double(const Student&)> scoreSelector;
        string courseName;

        switch(courseChoice) {
            case 1:
                scoreSelector = [](const Student& s) {
                    return s.dataStructure;
                };
                courseName = "数据结构";
                break;
            case 2:
                scoreSelector = [](const Student& s) {
                    return s.dsProject;
                };
                courseName = "数据结构课设";
                break;
            case 3:
                scoreSelector = [](const Student& s) {
                    return s.cpp;
                };
                courseName = "C++";
                break;
            case 4:
                scoreSelector = [](const Student& s) {
                    return s.c;
                };
                courseName = "C语言";
                break;
            case 5:
                scoreSelector = [](const Student& s) {
                    return s.math1;
                };
                courseName = "高数1";
                break;
            case 6:
                scoreSelector = [](const Student& s) {
                    return s.english1;
                };
                courseName = "大学英语1";
                break;
            case 7:
                scoreSelector = [](const Student& s) {
                    return s.linearAlg;
                };
                courseName = "线性代数";
                break;
            case 8:
                scoreSelector = [](const Student& s) {
                    return s.intro;
                };
                courseName = "专业导论";
                break;
            default:
                cout << "无效的选择!" << endl;
                return;
        }

        // 6. 新增：排序算法选择菜单
        cout << "\n请选择排序算法:" << endl;
        cout << "1. 快速排序" << endl;
        cout << "2. 希尔排序" << endl;
        cout << "3. 归并排序" << endl;
        int sortChoice;
        cout << "请选择(1-3): ";
        cin >> sortChoice;

        // 7. 根据选择执行相应的排序算法
        switch(sortChoice) {
            case 1:
                quickSort(sortedStudents, 0, sortedStudents.size() - 1, scoreSelector);
                break;
            case 2:
                shellSort(sortedStudents, scoreSelector);
                break;
            case 3:
                mergeSortHelper(sortedStudents, 0, sortedStudents.size() - 1, scoreSelector);
                break;
            default:
                cout << "无效的选择，默认使用快速排序" << endl;
                quickSort(sortedStudents, 0, sortedStudents.size() - 1, scoreSelector);
        }

        // 8. 显示排序结果
        cout << "\n" << courseName << "成绩排名（使用";
        switch(sortChoice) {
            case 1: cout << "快速排序"; break;
            case 2: cout << "希尔排序"; break;
            case 3: cout << "归并排序"; break;
            default: cout << "快速排序";
        }
        cout << "):" << endl;

        cout << setw(4) << "排名" << setw(8) << "学生姓名"
             << setw(12) << "学号" << setw(8) << "成绩" << endl;
        cout << string(32, '-') << endl;

        for (size_t i = 0; i < sortedStudents.size(); i++) {
            cout << setw(4) << i + 1
                 << setw(8) << sortedStudents[i].name
                 << setw(12) << sortedStudents[i].id
                 << setw(8) << fixed << setprecision(1)
                 << scoreSelector(sortedStudents[i]) << endl;
        }
    }

    // 9. 保持原有的显示菜单函数不变
    void showSortMenu() {
        cout << "\n请选择要排序的课程:" << endl;
        cout << "1. 数据结构" << endl;
        cout << "2. 数据结构课设" << endl;
        cout << "3. C++" << endl;
        cout << "4. C语言" << endl;
        cout << "5. 高数1" << endl;
        cout << "6. 大学英语1" << endl;
        cout << "7. 线性代数" << endl;
        cout << "8. 专业导论" << endl;
        cout << "0. 返回上级菜单" << endl;
        cout << "请选择(0-8): ";
    }
};

// 学生管理系统主类
class StudentManager {
private:
    vector<Student> students;
    GradeAnalyzer analyzer;
    GradeModifier modifier;
    GradeSorter sorter;

    //计算平均分
    void calculateAverage(Student& student) {
        student.average = (student.dataStructure + student.dsProject + student.cpp +
                         student.c + student.math1 + student.english1 +
                         student.linearAlg + student.intro) / 8.0;
    }

    //二分查找学生
    int binarySearch(const string& id) {
        int left = 0, right = students.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (students[mid].id == id) return mid;
            if (students[mid].id < id) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

public:
    StudentManager() : analyzer(students), modifier(students), sorter(students) {}

    //从文件加载数据
    bool loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "无法打开文件!" << endl;
            return false;
        }

        students.clear();
        string line;
        getline(file, line); // 跳过表头

        while (getline(file, line)) {
            stringstream ss(line);
            Student student;
            string temp;

            getline(ss, student.name, ',');
            getline(ss, student.id, ',');

            getline(ss, temp, ',');
            student.dataStructure = stod(temp);

            getline(ss, temp, ',');
            student.dsProject = stod(temp);

            getline(ss, temp, ',');
            student.cpp = stod(temp);

            getline(ss, temp, ',');
            student.c = stod(temp);

            getline(ss, temp, ',');
            student.math1 = stod(temp);

            getline(ss, temp, ',');
            student.english1 = stod(temp);

            getline(ss, temp, ',');
            student.linearAlg = stod(temp);

            getline(ss, temp, ',');
            student.intro = stod(temp);

            calculateAverage(student);
            students.push_back(student);
        }

        file.close();
        return true;
    }

    //查找学生
    void searchStudent() {
        string id;
        cout << "请输入要查找的学生学号: ";
        cin >> id;

        int index = binarySearch(id);
        if (index != -1) {
            displayStudent(students[index]);
        } else {
            cout << "未找到该学生!" << endl;
        }
    }

    //显示学生信息
    void displayStudent(const Student& student) {
        cout << "\n学生信息:" << endl;
        cout << "姓名: " << student.name << "\t学号: " << student.id << endl;
        cout << "数据结构: " << student.dataStructure << endl;
        cout << "数据结构课设: " << student.dsProject << endl;
        cout << "C++: " << student.cpp << endl;
        cout << "C语言: " << student.c << endl;
        cout << "高数1: " << student.math1 << endl;
        cout << "大学英语1: " << student.english1 << endl;
        cout << "线性代数: " << student.linearAlg << endl;
        cout << "专业导论: " << student.intro << endl;
        cout << "平均分: " << student.average << endl;
    }

    // StudentManager类的剩余方法
    void sortByAverage() {
        vector<Student> sortedStudents = students;
        sort(sortedStudents.begin(), sortedStudents.end(),
             [](const Student& a, const Student& b) { return a.average > b.average; });

        cout << "\n按平均成绩降序排列:" << endl;
        cout << left
            << setw(10) << "姓名"
            << setw(12) << "学号"
            << setw(8) << "平均分" << endl;
        cout << string(30, '-') << endl;

        for (const auto& student : sortedStudents) {
            cout << left
                << setw(10) << student.name
                << setw(12) << student.id
                << fixed << setprecision(2) << student.average << endl;
        }
    }

    void searchFailedStudents() {
        bool hasFailedStudents = false;
        cout << "\n不及格学生名单:" << endl;

        for (const auto& student : students) {
            bool studentHasFailed = false;
            vector<pair<string, double>> failedCourses;

            if (student.dataStructure < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"数据结构", student.dataStructure});
            }
            if (student.dsProject < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"数据结构课设", student.dsProject});
            }
            if (student.cpp < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"C++", student.cpp});
            }
            if (student.c < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"C语言", student.c});
            }
            if (student.math1 < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"高数1", student.math1});
            }
            if (student.english1 < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"大学英语1", student.english1});
            }
            if (student.linearAlg < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"线性代数", student.linearAlg});
            }
            if (student.intro < 60) {
                studentHasFailed = true;
                failedCourses.push_back({"专业导论", student.intro});
            }

            if (studentHasFailed) {
                hasFailedStudents = true;
                cout << student.name << "(" << student.id << ") 不及格课程：" << endl;
                for (const auto& course : failedCourses) {
                    cout << "  " << course.first << ": " << course.second << "分" << endl;
                }
                cout << "------------------------" << endl;
            }
        }

        if (!hasFailedStudents) {
            cout << "没有不及格的学生!" << endl;
        }
    }

    void calculateCourseAverages() {
        double sumDS = 0, sumDSP = 0, sumCpp = 0, sumC = 0;
        double sumMath = 0, sumEng = 0, sumLA = 0, sumIntro = 0;

        for (const auto& student : students) {
            sumDS += student.dataStructure;
            sumDSP += student.dsProject;
            sumCpp += student.cpp;
            sumC += student.c;
            sumMath += student.math1;
            sumEng += student.english1;
            sumLA += student.linearAlg;
            sumIntro += student.intro;
        }

        int count = students.size();
        cout << "\n课程平均分:" << endl;
        cout << fixed << setprecision(2);
        cout << "数据结构: " << sumDS/count << endl;
        cout << "数据结构课设: " << sumDSP/count << endl;
        cout << "C++: " << sumCpp/count << endl;
        cout << "C语言: " << sumC/count << endl;
        cout << "高数1: " << sumMath/count << endl;
        cout << "大学英语1: " << sumEng/count << endl;
        cout << "线性代数: " << sumLA/count << endl;
        cout << "专业导论: " << sumIntro/count << endl;
    }

    void insertStudent() {
        Student newStudent;
        cout << "请输入学生信息:" << endl;
        cout << "姓名: "; cin >> newStudent.name;
        cout << "学号: "; cin >> newStudent.id;
        cout << "数据结构成绩: "; cin >> newStudent.dataStructure;
        cout << "数据结构课设成绩: "; cin >> newStudent.dsProject;
        cout << "C++成绩: "; cin >> newStudent.cpp;
        cout << "C语言成绩: "; cin >> newStudent.c;
        cout << "高数1成绩: "; cin >> newStudent.math1;
        cout << "大学英语1成绩: "; cin >> newStudent.english1;
        cout << "线性代数成绩: "; cin >> newStudent.linearAlg;
        cout << "专业导论成绩: "; cin >> newStudent.intro;

        calculateAverage(newStudent);
        students.push_back(newStudent);
        cout << "学生信息添加成功!" << endl;
    }

    void deleteStudent() {
        string id;
        cout << "请输入要删除的学生学号: ";
        cin >> id;

        int index = binarySearch(id);
        if (index != -1) {
            students.erase(students.begin() + index);
            cout << "学生信息删除成功!" << endl;
        } else {
            cout << "未找到该学生!" << endl;
        }
    }

    void analyzeGrades() {
        analyzer.analyzeAllCourses();
    }

    void modifyGrades() {
        string id;
        cout << "请输入要修改成绩的学生学号: ";
        cin >> id;
        modifier.modifyStudentGrade(id);
    }

    void sortCourseGrades() {
        sorter.showSortMenu();
        int choice;
        cin >> choice;
        if (choice != 0) {
            sorter.sortByCourse(choice);
        }
    }

    void showMenu() {
        cout << "\n学生成绩管理系统" << endl;
        cout << "1. 查找学生成绩" << endl;
        cout << "2. 按平均成绩排序" << endl;
        cout << "3. 查询不及格学生" << endl;
        cout << "4. 查询课程平均分" << endl;
        cout << "5. 课程成绩排序" << endl;
        cout << "6. 插入学生记录" << endl;
        cout << "7. 删除学生记录" << endl;
        cout << "8. 成绩分析统计" << endl;
        cout << "9. 修改学生成绩" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择功能(0-9): ";
    }
};

int main() {
    StudentManager manager;
    string filename = "/Users/wyf/Documents/作业/数据结构/数据结构课设/课设名字.csv"; // 更新为正确的文件路径
    if (!manager.loadFromFile(filename)) {
        cout << "加载数据失败!" << endl;
        return 1;
    }

    //主循环
    while (true) {
        manager.showMenu();
        int choice;
        cin >> choice;

        //根据选择执行相应的功能
        switch (choice) {
            case 0:
                cout << "感谢使用!" << endl;
                return 0;
            case 1:
                manager.searchStudent();
                break;
            case 2:
                manager.sortByAverage();
                break;
            case 3:
                manager.searchFailedStudents();
                break;
            case 4:
                manager.calculateCourseAverages();
                break;
            case 5:
                manager.sortCourseGrades();
                break;
            case 6:
                manager.insertStudent();
                break;
            case 7:
                manager.deleteStudent();
                break;
            case 8:
                manager.analyzeGrades();
                break;
            case 9:
                manager.modifyGrades();
                break;
            default:
                cout << "无效的选择!" << endl;
        }
    }

    return 0;
}