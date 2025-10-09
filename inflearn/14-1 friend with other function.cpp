#include <iostream>
using namespace std;

class Rect; //Rect Class 선언되기전에 먼저 참조되버리는 컴파일 오류 막기위한
// 선언문임 !!

bool equals(Rect r, Rect s);

class Rect {
    int width, height;
public:
    Rect(int width, int height) {this->width = width; this->height = height;}
    friend bool equals(Rect r, Rect s); // equals()함수를 frend로 선언
};

bool equals(Rect r, Rect s) {
    if (r.width ==s.width && r.height ==s.height) return true;
    else return false;
}

int main() {
    Rect a(3,4), b(4,5);
    if (equals(a, b)) cout<< "equal"<<endl;
    else cout<<"not equal"<<endl;
}

