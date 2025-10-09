#include <iostream>
using namespace std;

class MyVector{
private :
    double x, y;
public:
    MyVector(double xvalue=0.0, double yvalue=0.0): x(xvalue), y(yvalue){}
    friend ostream& operator<<(ostream& os, const MyVector& v) {
        os<< "("<<v.x<<","<<v.y<<")"<<endl;
        return os;
    }
};


int main() {
    MyVector v(1.0, 2.0), v2(2,4);

    cout<<v<<v2<<endl;
    return 0;
}
