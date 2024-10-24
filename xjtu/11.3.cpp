#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string _name;
    int _age;

public:
    Person(const string& name, int age)
    : _name(name), _age(age) {
        cout << "constructor of person " << _name << endl;
    }
    virtual ~Person() {
        cout << "deconstructor of person " << _name << endl;
    }
};

class Student : public Person {
private:
    string _classname;
    Person _monitor;

public:
    Student(const string& name, int age, const string& classname, const string name1, int age1)
    : Person(name, age), _classname(classname), _monitor(name1, age1) {
        cout << "constructor of Student" << endl;
    }
    virtual ~Student() {
        cout << "destructor of Student"<< endl;
    }
};

int main() {
    string name1, name2;
    int age1, age2;
    string classname;
    cin >> name1 >> age1 >> classname >> name2 >> age2;
    Student student(name1, age1, classname, name2, age2);

    return 0;
}