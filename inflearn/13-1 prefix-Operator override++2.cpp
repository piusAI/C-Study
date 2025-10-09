#include <iostream>

using namespace std;


class Counter {
private:
    int value;
public:
    Counter() : value(0){}
    ~Counter(){}
    int getValue() const {return value;} //읽기 전용으로 들어가니까 const로의 안정성 더하기
    void setValue(int x) { value=x;}
    Counter& operator++() {
        ++value;
        return *this;
    }
};

int main() {
    Counter c;

    cout<< "counter : " << c.getValue()<<endl;
    ++c;
    cout<< "counter : " << c.getValue()<<endl;
    return 0;
}
