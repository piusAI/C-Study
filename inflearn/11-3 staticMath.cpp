#include <iostream>
#include <string>
using namespace std;

class Math
{
public:
    static int abs(int a) {return a>0? a : -a;}
    static int max(int a, int b) {return a>b? a : b;}
    static int min(int a, int b) {return a<b? a : b;}
    
};

int main()
{
    cout<< Math::max(5,6)<<endl;
    cout<<Math::max(55,2)<<endl;
    cout<< Math::min(5,6)<<endl;
    cout<< Math::abs(-5)<<endl;
}
