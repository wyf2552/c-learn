#include <iostream>
#include <array>
using namespace std;
class Array {
    private:
        string name;
        int count;
        int * data;
    public:
        Array();
        Array(string name, const int * data, int count);
        ~Array();
        void print();
        void order();
        Array add(const Array & array);
};

Array::~Array() {
    if (data != NULL) {
        delete[] data;
        count = 0;
    }
}

void Array::print() {
    cout << name << ":";
    for (int i = 0; i < count; i++) {
        cout << data[i] << "";
    }
    cout << endl;
}

void Array::order() {
    for(int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

Array Array::add(const Array & array) {
    Array temp;
    int max = (count > array.count? count:array.count);
    int min = (count < array.count? count:array.count);
    temp.name = this->name + "+" + array.name;
    temp.count = max;
    temp.data = new int[temp.count];
    int i = 0;
    for (i = 0; i < min; i++) {
        temp.data[i] = data[i] + array.data[i];
    }
    for (; i < count; i++) {
        temp.data[i] = data[i];
    }
    for (; i < array.count; i++) {
        temp.data[i] = array.data[i];
    }
    return temp;
}

int main() {
    int data1[] = {9,8,7,6,5,4,3,2,1,0};
    Array array1("array1", data1, 10);
    array1.print();
    int data2[] = {1,3,5,7,8,6,4,2};
    Array array2("array2", data2, 8);
    array2.print();
    (array1.add(array2)).print();
    array1.order();
    cout << "排序后，";
    array1.print();
    array2.order();
    cout << "排序后，";
    array2.print();
    return 0;
}