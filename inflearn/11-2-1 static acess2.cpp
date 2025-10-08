#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    int money;
    void addMoney(int money)
    {
        this->money += money;
    }

    static int sharedMoney;                 //공금
    static void addShared(int n)
    {
        sharedMoney +=n;
    }
};

//static 변수 전역공간에 생성
int Person::sharedMoney=10; //공금 10

int main()
{
    Person::addShared(50); // 공금 60
    cout<<Person::sharedMoney<<endl;
    
    Person han;
    han.money=100;
    
    han.sharedMoney = 200; // 공금=200
    Person::sharedMoney = 300; // 공금 300
    Person::addShared(100); //공금 +100 =400

        cout<< han.money<< ' '
    <<Person::sharedMoney<<endl;
    return 0;
}
