# C++ Upcasting and Downcasting

이 문서는 C++에서 상속 구조에서 사용되는 **Upcasting**과 **Downcasting**의 개념, 사용 이유, 예제, 그리고 주의사항을 설명합니다. 객체지향 프로그래밍에서 다형성과 자식 고유 기능 접근을 위해 필수적인 기술입니다.

## 1. Upcasting (위로 캐스팅)
- **정의**: 자식 클래스 객체(또는 포인터/참조)를 부모 클래스 타입으로 변환.
- **특징**:
  - **암묵적**: 캐스팅 연산자 없이 자동 변환.
  - **안전**: 자식 객체는 부모 멤버 포함, 항상 성공.
  - **접근**: 부모의 public/protected 멤버만 접근 가능.
- **사용 이유**:
  - **다형성**: 부모 타입으로 다양한 자식 객체 통합 관리 (예: `Point*`로 `ColorPoint` 관리).
  - **코드 단순화**: 부모 인터페이스로 "가볍게" 처리, 자식 고유 멤버 무시.
  - **재사용성**: 공통 메서드 호출로 코드 효율성 증가.
- **예시**:
  ```cpp
  ColorPoint cp(3, 4, "Blue");
  Point* pBase = &cp; // Upcasting
  pBase->set(10, 20);
  pBase->showPoint(); // Point: (10, 20)
  ```

## 2. Downcasting (아래로 캐스팅)
- **정의**: 부모 클래스 타입의 포인터/참조를 자식 클래스 타입으로 변환.
- **특징**:
  - **명시적**: `dynamic_cast`, `static_cast`, 또는 C 스타일 캐스팅 필요.
  - **안전성**: 잘못된 타입 변환 시 런타임 오류 가능 (`dynamic_cast` 권장).
  - **접근**: 자식의 고유 멤버(예: `setColor`) 접근 가능.
- **사용 이유**:
  - **자식 고유 기능**: 부모 타입으로 저장된 객체의 자식 고유 메서드/멤버 사용.
  - **구체적 타입 복구**: 다형성 처리 후 원래 타입 복원.
  - **런타임 유연성**: `dynamic_cast`로 타입 체크.
- **예시**:
  ```cpp
  ColorPoint* pDer = dynamic_cast<ColorPoint*>(pBase); // Downcasting
  if (pDer) {
      pDer->setColor("Red");
      pDer->showColorPoint(); // ColorPoint: (10, 20, Red)
  }
  ```

## 3. 예제 코드
```cpp
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void set(int x, int y) { this->x = x; this->y = y; }
    void showPoint() { cout << "Point: (" << x << ", " << y << ")" << endl; }
    virtual ~Point() {} // dynamic_cast 지원
};

class ColorPoint : public Point {
private:
    string color;
public:
    ColorPoint(int x = 0, int y = 0, string c = "Black") : Point(x, y), color(c) {}
    void setColor(string c) { color = c; }
    void showColorPoint() { cout << "ColorPoint: (" << x << ", " << y << ", " << color << ")" << endl; }
    virtual ~ColorPoint() {}
};

int main() {
    ColorPoint cp(3, 4, "Blue");
    Point* pBase = &cp; // Upcasting
    pBase->set(10, 20);
    pBase->showPoint(); //