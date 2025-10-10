#include <iostream>
using namespace std;

class Calculator
{
    void input()
    {
        cout<< "input your int number of 2: ";
        cin >> a>> b;
    }
protected:
    int a, b;
    virtual int calc(int a, int b) =0; // 두 정수 계산
public:
    void run()
    {
        input();
        cout<< " value of calc : "<< calc(a,b)<<endl;
    }
};

class Adder:public Calculator
{
protected:
    int calc(int a, int b)
    {
        return a+b;
    }
};

class Subtractor:public Calculator
{
protected:
    int calc(int a, int b) // pure virtual func implement
    {
        return a-b;
    }
};

int main()
{
    Adder adder;
    Subtractor subtractor;
    
    adder.run();
    subtractor.run();

    return 0;
}
