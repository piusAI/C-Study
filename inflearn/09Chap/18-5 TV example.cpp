#include <iostream>
#include <string>
using namespace std;

class TV {
    int size;
public:
    TV(){size = 20;} //TV(int size=20){}을 한다면 기본 생성자가 생성되지 않음!
    TV(int size) {
        this->size = size;  //Wide TV는 이 호출이들어옴 인자가 들어가서
    }
    int getSize(){return size;}
};

class WideTV:public TV{
    bool videoln;
public:
    // WideTV(int size, bool videoln):TV(size),videoln(videoln) {}      // constructor차이 없이 한번만에 초기화
    WideTV(int size, bool videoln):TV(size){this-> videoln = videoln;}  // 객체 생성후 멤버 변수 값 할당
    bool getVideoln(){return videoln;}

};

class SmartTV:public WideTV { // 상속 두번
    string ipAddr;
public:
    SmartTV(string ipAddr, int size):WideTV(size, true) {
        this->ipAddr=ipAddr;
    }
    string getIP(){ return ipAddr;}
};

int main() {
    WideTV tv(32, true);
    cout<<"Size : "<<tv.getSize()<<endl; // base class func : get size
    cout<<"Videoln : "<<tv.getVideoln()<<endl; // derive class func

    SmartTV smartv("192.0.0", 32);
    cout<<"size : "<<smartv.getSize()<<endl;
    cout <<"Videoln : "<<smartv.getVideoln()<<endl;
    cout<<"ip : "<<smartv.getIP();
    return 0;
}
