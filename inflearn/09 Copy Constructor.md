# C++ 멤버 변수와 복사 생성자

## 멤버 변수란?
C++ 클래스에서 **멤버 변수**는 클래스의 객체가 가지는 데이터를 저장하는 변수입니다. 클래스 내에서 선언되며, 각 객체가 독립적으로 가지는 데이터(인스턴스 멤버 변수) 또는 클래스 전체가 공유하는 데이터(`static` 멤버 변수)로 나뉩니다.

### 예시:
```cpp
class Person {
private:
    int id;           // 인스턴스 멤버 변수 (각 객체가 독립적으로 가짐)
    char* name;       // 포인터 멤버 변수
    static int count; // static 멤버 변수 (모든 객체가 공유)
};
int Person::count = 0; // static 변수 초기화
```

## 포인터 멤버 변수와 동적 메모리 할당
클래스에 포인터 멤버 변수(예: `char* name`)가 있고, 생성자에서 동적으로 메모리를 할당하는 경우, 복사 생성자를 주의 깊게 다뤄야 합니다.

### 문제: 얕은 복사 (Shallow Copy)
C++의 기본 복사 생성자(default copy constructor)는 멤버 변수를 단순히 복사합니다. 포인터 멤버 변수의 경우, 포인터 값(메모리 주소)만 복사되어 두 객체가 동일한 메모리를 가리키게 됩니다. 이를 **얕은 복사**라고 합니다.

#### 얕은 복사의 문제점:
- 두 객체가 같은 메모리를 공유하므로, 한 객체에서 메모리를 수정하거나 해제하면 다른 객체에도 영향을 미침.
- 소멸자에서 메모리 해제(`delete`) 시 중복 해제(double free)로 프로그램 충돌 가능.

#### 예시 (문제 발생):
```cpp
class Person {
private:
    int id;
    char* name;
public:
    Person(int id, const char* n) : id(id) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name; }
};

int main() {
    Person p1(1, "Alice");
    Person p2 = p1; // 기본 복사 생성자 호출 (얕은 복사)
    // p1, p2가 같은 name 메모리를 가리킴
    // p1 소멸 시 name 해제 → p2의 name은 이미 해제된 메모리 참조 (비정상 종료)
}
```

## 해결: 깊은 복사 (Deep Copy)
포인터 멤버 변수를 가진 클래스는 **복사 생성자**를 직접 정의해 **깊은 복사**를 구현해야 합니다. 깊은 복사는 새로운 메모리를 할당해 데이터를 복사하므로, 각 객체가 독립적인 메모리를 가집니다.

### 깊은 복사 구현 예시:
```cpp
class Person {
private:
    int id;
    char* name;
public:
    Person(int id, const char* n) : id(id) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    // 복사 생성자 (깊은 복사)
    Person(const Person& other) : id(other.id) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    ~Person() { delete[] name; }
};
```

### 동작:
- `Person p2 = p1;` 호출 시, `p2`는 새로운 메모리를 할당받아 `p1.name`의 데이터를 복사.
- `p1`과 `p2`는 독립적인 `name` 메모리를 가짐 → 소멸 시 문제 없음.

## 결론
- 포인터 멤버 변수가 동적 메모리 할당을 포함하면, 기본 복사 생성자는 얕은 복사를 수행해 문제가 발생.
- **복사 생성자**를 직접 정의해 깊은 복사를 구현해야 안전.
- 추가로, **복사 대입 연산자**(`operator=`)도 함께 정의해 대입 시에도 깊은 복사를 보장하는 것이 좋음.
