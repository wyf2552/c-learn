#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string _name;
    char _sex;
    int _age;

public:
    void Register(const string& name, int age, char sex) {
        _name = name;
        _sex = sex;
        _age = age;
    }

    virtual void showMe() const {
        cout << "name " << _name << endl
        << "sex " << _sex << endl
        << "age " << _age << endl;
    }
};

class Teacher : public Person {
private:
    string _dept;
    int _salary;

public:
    Teacher (const string& name, int age, char sex, const string& dept, int salary) {
        Register(name, sex, age);
        _dept = dept;
        _salary = salary;
    }

    virtual void showMe() const override {
        Person::showMe() ;
        cout << "department " << _dept << endl
        << "salary " << _salary << endl;
    }
};

class Student : public Person {
private:
    string _id;
    string _class;

public:
    Student (const string& name, int age, char sex, const string& id, const string& classid) {
        Register(name, age, sex);
        _id = id;
        _class = classid;
    }

    virtual void showMe() const override {
        cout << "id " << _id << endl;
        Person::showMe();
        cout << "class " << _class << endl;
    }
};

int main() {
    string name;
    char  sex;
    int age;
    string dept;
    int salary;
    string id;
    string classid;

    cin >> name >> age >> sex >> dept >> salary;
    Teacher teacher(name, sex, age, dept, salary);

    cin >> name >> age >> sex >> id >> classid;
    Student student(name, age, sex, id, classid);

    teacher.showMe();
    student.showMe();

    return 0;
}


