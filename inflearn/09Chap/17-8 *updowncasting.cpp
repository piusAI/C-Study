#include <iostream>
#include <string>
using namespace std;

class Point { // 부모 클래스
protected:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void set(int x, int y) { this->x = x; this->y = y; }
    void showPoint() { cout << "Point: (" << x << ", " << y << ")" << endl; }
    virtual ~Point() {} // 가상 소멸자 (dynamic_cast 지원)
};

class ColorPoint : public Point { // 자식 클래스
private:
    string color;
public:
    ColorPoint(int x = 0, int y = 0, string c = "Black") : Point(x, y), color(c) {}
    void setColor(string c) { color = c; }
    void showColorPoint() { 
        cout << "ColorPoint: (" << x << ", " << y << ", " << color << ")" << endl; 
    }
    virtual ~ColorPoint() {} // 가상 소멸자
};

int main() {
    ColorPoint cp(3, 4, "Blue"); // 자식 객체 생성
    ColorPoint *pDer = &cp;      // 자식 포인터 (초기화)

    // Upcasting: 자식 → 부모 (암묵적, 안전)
    Point* pBase = pDer;         // Point* pBase = &cp; 와 동일
    pBase->set(10, 20);          // 부모 메서드 호출
    pBase->showPoint();          // Point: (10, 20)

    // Downcasting: 부모 → 자식 (명시적, dynamic_cast 권장)
    ColorPoint* pDer2 = dynamic_cast<ColorPoint*>(pBase); // 런타임 타입 체크
    if (pDer2 != nullptr) {      // 성공 확인
        pDer2->setColor("Red");  // 자식 메서드 호출
        pDer2->showColorPoint(); // ColorPoint: (10, 20, Red)
    } else {
        cout << "Downcasting failed!" << endl;
    }

    // C 스타일 캐스팅 (비추천, 컴파일 성공하지만 안전하지 않음)
    ColorPoint* pDer3 = (ColorPoint*) pBase;
    pDer3->setColor("Green");
    pDer3->showColorPoint();     // ColorPoint: (10, 20, Green)

    return 0;
}
