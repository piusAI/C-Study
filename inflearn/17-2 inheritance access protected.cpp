#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
protected:
    string address;
};

class Student : Person {
public:
    void setAddress(string add){address = add;}
    string getAddress(){ return address;}

};

int main() {
    Student obj;
    obj.setAddress("John");
    cout << obj.getAddress() << endl;
}
