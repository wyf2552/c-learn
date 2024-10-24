#include <iostream>
using namespace std;

class Person{
private:
    char Sex;
    int Age;
    char Name[20];
public:
    void Register(char * name, int age, char sex) {
        strcpy(this->Name, name);
        this->Age = age;
        this->Sex = sex;
    }
    void ShowMe() {
        cout << Name << ' ' << Age << ' ' << Sex << endl;
    }
};

class Student : public Person {
private:
    int Number;
    char ClassName[10];
public:
    void RegisterStu(char * classname, int number, char * name, int age, char sex) {
        Register(name, age, sex);
        strcpy(this->ClassName, classname);
        this->Number = number;
    }

    void ShowMe() {
        cout << Number << " " << ClassName << ' ';
        Person::ShowMe();
    }
};

int main() {
    Student a;
    char ClassName[20], Name[20];
    int number, age;
    char sex;
    cin >> ClassName >> number >> Name >> age >> sex;
    a.RegisterStu(ClassName, number, Name, age, sex);
    a.ShowMe();
    a.Person::ShowMe();
    return 0;
}

