#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string _name;
    string _sex;
    int _age;
public:
    Person() = default;
    
    Person(const string& name, int age, const string& sex)
    : _name(name), _age(age), _sex(sex)
    {}

    void showMe() {
        cout << "name " << _name << endl;
        cout << "sex " << _sex << endl;
        cout << "age " << _age << endl;
    }
};

class Teacher : virtual public Person{
private:
    int _salary;
    string _dep;
public:
    Teacher(const string& name, int age, const string& sex, const string& dep, int salary)
    : Person(name, age, sex), _salary(salary), _dep(dep)
    {}

    Teacher(const string& dep, int salary)
    : _salary(salary), _dep(dep) {}

    void show() {
        cout << "dep " << _dep << endl;
        cout << "salary " << _salary << endl;
    }

};

class Student : virtual public Person {
private:
    string _id;
    string _class;
public:
    Student(const string& name, int age, const string& sex, const string& id, const string& class1)
    : Person(name, age, sex), _id(id), _class(class1)
    {}

    Student(const string& id, const string& class1)
    : _id(id), _class(class1) {}

    void show() {
        cout << "class " << _class << endl;
        cout << "id " << _id << endl;
    }

};

class Graduate : public Teacher, public Student {
public:
    Graduate(const string& name, int age, const string& sex, const string& dep, int salary, const string& id, const string& classid)
    : Person(name, age, sex), Teacher(dep, salary), Student(id, classid) {}

    void showMe() {
        Student::show();
        Person::showMe();
        Teacher::show();
    }
};

int main() {
    string name;
    int age;
    string sex;
    string dep;
    int salary;
    string id;
    string classid;

    cin >> name >> age >> sex >> dep >> salary >> id >> classid;

    Graduate graduate(name, age, sex, dep, salary, id, classid);
    graduate.showMe();
}