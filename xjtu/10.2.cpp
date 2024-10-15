#include <iostream>
using namespace std;

class Person{
private:
    char name[100] = {'XXX'};
    int age = 0;
    char sex = 's';
public:
    Person() = default;
    ~Person() {
        cout << "Now destroying the instance of Person" << endl;
    }

    void Register(char* _name, int _age, char _sex) {
        strcpy(this->name, _name);
        age = _age;
        sex = _sex;
    }

    void showme() {
        cout << name << ' ' <<  age << ' ' << sex << endl;
    }
};

int main() {
    Person* p1 = new Person();
    Person* p2 = new Person();
    Person* p3;
    p1->showme();
    p2->showme();

    char name[100] = {0};
    int age;
    char sex;
    cin >> name >> age >> sex;
    p1->Register(name, age, sex);
    p3 = p2;
    p2 = p1;
    p1->showme();
    p2->showme();
    delete p1;
    delete p3;

    return 0;
}
