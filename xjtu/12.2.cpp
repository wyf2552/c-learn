#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string _name;
    int _age;
    string _colour;
public:
    Pet(const string& name, int age, const string& colour)
    : _name(name), _age(age), _colour(colour) {}

    virtual void speak() const = 0;

    void getInfo() {
        cout << getClassName() << "_name:" << _name << endl;
        cout << getClassName() << "_age:" << _age << endl;
        cout << getClassName() << "_colour:" << _colour << endl;
    }

    virtual ~Pet() = default;

protected:
    virtual string getClassName() const = 0;

};

class Cat : public Pet {
public:
    using Pet::Pet;

    virtual void speak() const override {
        cout << "miao!miao!" << endl;
    }

protected:
    virtual string getClassName() const override {
        return "cat";
    }
};

class Dog : public Pet {
public:
    using Pet::Pet;

    virtual void speak() const override {
        cout << "wang!wang!" << endl;
    }

protected:
    virtual string getClassName() const override {
        return "dog";
    }
};

int main() {
    string name;
    int age;
    string colour;

    cin >> name >> age >> colour;
    Pet* cat = new Cat(name, age, colour);
    
    cin >> name >> age >> colour;
    Pet* dog = new Dog(name, age, colour);

    cat->getInfo();
    cat->speak();


    dog->getInfo();
    dog->speak();

    delete cat;
    delete dog;

    return 0;
}