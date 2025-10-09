#include <iostream>
using namespace std;


class PassengerCar
{
public:
    int seats; // 인수, 정원
    void set_seats(int n){seats = n;}
};

class Truck
{
public:
    int payload; //적재 하중
    void set_payload(int load) {payload = load;}
};

class Pickup: public PassengerCar, public Truck
{
public:
    int tow_capability; // 견인 능력
    void set_tow(int capa){tow_capability = capa;}
};

int main()
{

    Pickup my_car;
    my_car.set_seats(4);            // base class : PassengerCar
    my_car.set_payload(10000);    // base class : Truck
    my_car.set_tow(30000);        // derived class
    return 0;
}
