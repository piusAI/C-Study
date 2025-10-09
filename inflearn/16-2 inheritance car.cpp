#include <iostream>
#include <string>

using namespace std;

class Car {
    int speed;
public:
    void setSpeed(int s){ speed =s;}
    int getSpeed(){ return speed; }
};

class SportCar:public Car{
    bool turbo;

public:
    void setTurbo(bool newValue){ turbo = newValue;}
    bool getTurbo(){return turbo;}

};

int main()
{
    SportCar c;
    c.setSpeed(60);                 // base class
    c.setTurbo(true);         // derive class
    c.setSpeed(100);
    c.setTurbo(false);
    return 0;
}
