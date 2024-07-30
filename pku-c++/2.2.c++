#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
/*
描述

在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。

（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，
请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

输入

姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

输出

一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。

各部分内容之间均用单个英文逗号","隔开，无多余空格。 */
class Student
    {
    private:
        char name[20];
        int age;
        int id;
        int score[4];
        double average;
        char c;         //用一个字符c来读取分隔符“,”
    public:
        void input()
        {
            cin.getline(name,20,',');
    //cin.getline(字符指针(char*),字符个数N(int),结束符(char));
    //一次读取多个字符(包括空白字符），直到读满N-1个，或者遇到指定的结束符为止(默认的是以'\n'结束)
            cin>>age>>c>>id;
            for(int i=0; i<4; i++)
                cin>>c>>score[i];
        }

        void calculate()
        {
            int sum=0;
            for(int i=0; i<4; i++)
            {
                sum=sum+score[i];
            }
            average=sum/4;
        }
        void output()
        {
            cout<<name<<','<<age<<','<<id<<','<<average<<endl;
        }
    };

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}

