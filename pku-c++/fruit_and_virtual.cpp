#include <iostream>
using namespace std;
class Fruit {
    public:
        virtual void print() {
            cout << "水果" << endl;
        }
};

class Banana:public Fruit {
    public:
        void print() {
            cout << "香蕉" << endl;
        }
};

class Apple:public Fruit {
    public:
        void print() {
            cout << "苹果" << endl;
        }
};

class Pear:public Fruit {
    public:
        void print() {
            cout << "梨子" << endl;
        }
};

class Peach:public Fruit {
    public:
        void pirnt() {
            cout << "桃子" << endl;
        }
};

int main() {
    Fruit * pFruit[] = {
        new Fruit(),
        new Banana(), new Apple(), new Pear(), new Peach()
    };
    for (int i = 0; i < 5; i++) {
        (*pFruit[i]).print();
    }
}