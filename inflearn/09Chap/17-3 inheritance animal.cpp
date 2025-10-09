#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
    void speak() {
        cout<<"bark!"<<endl;
    }
};

class Dog: public Animal {
public:
    void speak() {
        cout<<" wall wall! "<<endl;
    }
};
int main() {
    Dog obj;
    obj.speak();

}
