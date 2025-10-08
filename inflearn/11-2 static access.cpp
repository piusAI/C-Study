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
int Person::sharedMoney=10;

int main()
{
    Person han;
    han.money=100;
    han.sharedMoney = 200;

    Person lee;
    lee.money = 150;
    lee.addMoney(200);
    lee.addShared(200);

    cout<< han.money<< ' '<< lee.money<< endl;
    cout<< han.sharedMoney<< ' '<< lee.sharedMoney<< endl;

    return 0;
}
