#include <iostream>
#include <string>
using namespace std;

class Adder {
protected:
    int add(int a, int b) {
        return a+b;
    }
};

class Subtractor {
protected:
    int minus(int a, int b){ return a-b;}
};

class Multiplication {
protected:
    int multiply(int a, int b){ return a*b;}
};

class Calculator : public Adder,public Subtractor, public Multiplication {
public:
    int calc(char op, int a, int b);
};



int Calculator::calc(char op, int a, int b) {
    int res=0;
    switch (op) {
        case '+' :res = add(a,b); break;
        case '-' : res = minus(a,b); break;
        case '*' : res = multiply(a,b); break;
    }
    return res;

}

int main() {
    Calculator handCal;
    cout<< "2 + 4 = "<<handCal.calc('+', 2,4)<<endl;
    cout<<"100 - 8 = "<<handCal.calc('-',100,8)<<endl;
    cout<<"97 * 3 = " << handCal.calc('*',97,3)<<endl;

    return 0;
}
