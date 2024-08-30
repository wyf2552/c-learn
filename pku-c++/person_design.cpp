#include <iostream>
using namespace std;

class person {
        char Name[9];
        char Sex;
        int Age;
    public:
        person() {
            strcpy(Name, "XXX");
            Age = 0;
            Sex = 0;
        }
        ~person() {
            cout << "Now destroying Person" << endl;
        }
        void Register(char * name, int age, char sex);
        void ShowMe();
};

void person::Register(char * name, int age, char sex) {
    strcpy(Name, name);
    Age = age;
    Sex = sex;
}

void person::ShowMe() {
    cout << Name << '\t' << Age << '\t' << Sex << endl;
}

int main() {
    person person1, person2;
    cout << "person1:\t";
    person1.ShowMe();
    person1.Register("Zhang3", 19, 'm');
    cout << "person1:\t";
    person1.ShowMe();
    cout << "person2:\t";
    person2.ShowMe();
    person2 = person1;
    cout << "person2:\t";
    person2.ShowMe();
    return 0;
}