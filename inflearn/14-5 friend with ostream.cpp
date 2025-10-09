#include <iostream>
using namespace std;

class MyVector{
private :
    double x, y;
public:
    MyVector(double xvalue=0.0, double yvalue=0.0): x(xvalue), y(yvalue){}
    friend ostream& operator<<(ostream& os, const MyVector& v) {
        os<< "("<<v.x<<","<<v.y<<")"<<endl;
        return os;
    }

    // ostream은 사용자 수정 불가하기때문에
    // my vector안에서 friend ostream& operator<<를 선언해 os<<v 수정 지원

    // friend ostream& operator<< : MyVector 출력, private x, y 접근
    // 연쇄 출력( cout<< v<< v2)를 위해 stream& 반환

    // ostream& os를 매개변수로 받는 이유?
    // cout << v => operator<<(cout, v)로 해석 가능
    // ostream& os : cout
    // Myvector &v : v
};


int main() {
    MyVector v(1.0, 2.0), v2(2,4);

    cout<<v<<v2<<endl;
    return 0;
}
