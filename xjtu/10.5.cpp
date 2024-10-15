#include <iostream>
using namespace std;

class MyTime{
private:
    int hour;
    int minute;
    int second;
public:
    MyTime() : hour(0), minute(0), second(0) {}

    MyTime(int _hour, int _minute, int _second)
    : hour(_hour), minute(_minute), second(_second) {}
};