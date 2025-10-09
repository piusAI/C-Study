#include <iostream>
using namespace std;
const int SIZE = 10;

class MyArray {
private:
    int a[SIZE];
public:
    MyArray() {
        for ( int i =0 ; i < SIZE ; i++ )
            a[i]=0;
    }
    int &operator[](int i) {
        if (i>=SIZE) {
            cout << "error index! ";
            return a[0];
        }
        return a[i];
    }
};

int main() {
    MyArray A;
    A[3] = 9;
    A[23] =14;

    cout<<"A[3] : " << A[3]<<endl;
    cout<<"A[23] : " << A[23]<<endl;
    cout<<A[2]<<endl;
    cout<<A[0]<<endl;
}
