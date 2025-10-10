#include <iostream>
using namespace std;

class Animal
{
public:
    void speak() {cout<< "Animal Speak! "<<endl;}
};

class Dog:public Animal
{
public:
    int age;
    void speak(){ cout<< "bark! bark!!"<<endl;}
};

class Cat:public Animal
{
public:
    void speak(){cout<<"mia! mia!"<<endl;}
};

int main()
{
    Animal *a1= new Dog();
    a1->speak();

    Dog *a0 = new Dog();
    a0->speak();            // 자신 객체 pointer!
    
    Animal *a2 = new Cat();
    a2->speak();
    

    return 0;
}
