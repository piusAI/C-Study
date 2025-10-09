#include <iostream>
using namespace std;

class Box {
private:
    double length, width, height;

public:
    Box(double l=0.0, double w=0.0, double h =0.0):length(l), width(w), height(h){}
    void display() {
        cout<<"("<<length<<", "<<width<<", "<<height<<")"<<endl;
    }
    Box& operator=(const Box& b2) {
        this->length = b2.length;
        this->width = b2.width;
        this->height = b2.height;
        return *this;
    }
};

//참조자 없는 기본 복사 생성시 인자복사

int main() {

    Box b1(20,4,5);
    Box b0(b1);
    b0.display();
    return 0;
}
