#include <iostream>
#include <string>
using namespace std;

class BaseID {
public:
    int mode;
};

class In : virtual public BaseID {
public:
    int readPos;
};

class Out : virtual public BaseID {
public:
    int writePos;
};

class InOut:public In, public Out {
public:
    bool safe;
};

int main() {
    InOut ioObj;
    ioObj.readPos = 10;
    ioObj.writePos = 20;
    ioObj.safe = true;
    ioObj.mode = 5;         //virtual없다면 오류뜸!
}
