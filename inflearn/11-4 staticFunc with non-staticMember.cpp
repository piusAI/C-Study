#include <iostream>
#include <string>
using namespace std;

class PersonError
{
    int money;
public:
    static int getMoney() {return money;} // non-static member 접근 불가!

    void setMoney(int money){ this->money = money;} //정상 코드
    
};

int main(){

    int n = PersonError::getMoney(); // static Member는 프로그램 시작하자마자 생성 

    PersonError errorJoon; // Object, instance는 여기서 생성
    errorJoon.setMoney(100);

    return 0;
}
