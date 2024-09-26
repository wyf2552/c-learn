#include <iostream>
#include <string>
using namespace std;

class Dog {
private:
    string _name;
    int _age;
    char _sex;
    float _weight;

public:
    void setdata(string& name, int age, char sex, float weight) {
        _name = name;
        _age = age;
        _sex = sex;
        _weight = weight;
    }

    string getName() const {
        return _name;
    }

    int getAge() const {
        return _age;
    }

    char getSex() const {
        return _sex;
    }

    float getWeight() const {
        return _weight;
    }

    void getInfo() {
        cout << "It is my dog." << endl;
        cout << "Its name is " << getName() << '.' << endl;
        cout << "It is " << getAge() << " years old." << endl;
        cout << "It is " << getSex() << '.' << endl;
        cout << "It is " << getWeight() << " kg." << endl;
    }
};

int main() {
    string name;
    int age;
    char sex;
    float weight;

    cin >> name >> age >> sex >> weight;

    Dog dog;
    dog.setdata(name, age, sex, weight);
    dog.getInfo();
    return 0;
}



