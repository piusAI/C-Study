#include <iostream>
#include <string>

using namespace std;

class Time {
    int hour, minute, seconds;
public:
    Time(int h=0, int m=0, int s=0):hour(h), minute(m), seconds(s){}

    bool operator==(const Time &t) {
        return (hour == t.hour && minute == t.minute && seconds == t.seconds);
    }
    bool operator!=(const Time &t) {
        return !(*this==t); //instance의 값이랑 t랑 바로 연산 확인
    }
};

int main() {
    Time t1(20,22,1), t2(2,4,5), te(20,22,1);

    cout<<boolalpha<<(t1!=t2)<<endl;
    cout<<boolalpha<<(t1==te)<<endl;

    return 0;
}
