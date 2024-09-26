#include <iostream>
#include <string.h>
using namespace std;

class Person {
private:
    char name[100];
    int age;
    char sex;
public:
    void Register(char* _name, int _age, char _sex) {
        this->age = _age;
        this->sex = _sex;
        strcpy(this->name, _name);
    };
    void ShowMe() {
        cout << this->name << " " << this->age << " " << this->sex << endl;
    };
};

int main() {
    Person person1, person2;
    char name[100] = {0};
    int age;
    char sex;
    cin >> name >> age >> sex;
    person1.Register(name, age, sex);
    person2.Register("Zhangsan", 19, 'm');
    person1.ShowMe();
    person2.ShowMe();
    return 0;
}

