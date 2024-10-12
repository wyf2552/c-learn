#include <iostream>
using namespace std;

class Dog{
private:
    char name[100] = {0};
    int age;
    char sex;
    float weight;
public:
    Dog (char* _name, int _age, char _sex, float _weight)
    : age(_age), sex(_sex), weight(_weight) {
        strcpy(this->name, _name);
    }
    const char* GetName() const {
        return name;
    }

    int GetAge() const {
        return age;
    }

    char GetSex() const {
        return sex;
    }

    float GetWeight() const {
        return weight;
    }

    void speak() {
        cout << "Arf!Arf1" << endl;
    }
};

int main() {
    char n[100] = {0};
    int a;
    char s;
    float w;
    cin >> n >> a >> s >> w;
    Dog dog(n, a, s, w);
    cout << dog.GetName() << endl;
    cout << dog.GetAge() << endl;
    cout << dog.GetSex() << endl;
    cout << dog.GetWeight() << endl;
    dog.speak();
    return 0;

}