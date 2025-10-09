// 상속 시, 자식 클래스는 부모 클래스의 생성자를 호출해야 함.
// SmartTV는 WideTV의 특정 생성자(WideTV(int, bool))를 호출해
// size와 videoln을 설정.

#include <iostream>
#include <string>

using namespace std;

class TV {
    int size;
public:
    TV(){size = 20;}
    TV(int size){this->size = size;}
    int getSize(){return size;}

};

class WideTV:public TV {
    bool videoln;
public:
    WideTV(int size, bool videoln):TV(size) {
        this->videoln = videoln;
    }
    bool getVideoln() {return videoln;}
};

class SmartTV:public WideTV {
    string ipAddr;
public:
    SmartTV(string ipAddr, int size):WideTV(size, true ) {  // WideTv에 있는 size, videoln 생성자 불러와줌!
        this->ipAddr=ipAddr;
    }
    string getIpAddr(){ return ipAddr;}
};

int main() {

    SmartTV htv("192.0.1", 32);
    cout<<"size = "<< htv.getSize() <<endl;
    cout<< "videoln = "<<boolalpha<<htv.getVideoln() << endl;
    cout<< "IP = "<<htv.getIpAddr() << endl;
    return 0;
}
