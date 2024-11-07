#include <iostream>
using namespace std;

class Pet {
public:
    virtual void speak() const {
        cout << "How does a pet speak?" << endl;
    }
};

class Cat : public Pet {
public:
    virtual void speak() const override {
        cout << "miao! miao!" << endl;
    }
};

class Dog : public Pet {
public:
    virtual void speak() const override {
        cout << "wang! wang!" << endl;
    }
};

int _main() {
    Pet* pet = new Pet();
    Cat* cat = new Cat();
    Dog* dog = new Dog();

    pet->speak();
    cat->speak();
    dog->speak();

    delete pet;
    delete cat;
    delete dog;
}

int main() {
    Pet pet;
    Cat cat;
    Dog dog;

    Pet& pt = pet;
    Cat& ct = cat;
    Dog& dg = dog;

    pt.speak();
    ct.speak();
    dg.speak();

    return 0;
}