#include <iostream>
using namespace std;


class Converter {
protected:
    double ratio;
    virtual double convert(double src)=0;
    virtual string getSourceString() =0;
    virtual string getDestString()=0;
public:
    Converter(double r):ratio(r){}
    void run() {
        double src;
        cout<<getSourceString()<<"->"<<getDestString()<<" !! "<<endl;
        cout<<"input: "<<getSourceString();
        cin>>src;
        cout<<"return : "<<convert(src)<<getDestString()<<endl;
    }
};
class WonToDallor:public Converter {
protected:
    double convert(double src) override { return src/ratio; }
    string getSourceString() override {return "won";}
    string getDestString() override {return "dollar";}

public: //생성자는 항상 public! 객체에서 호출하니까!
    WonToDallor(double r):Converter(r){}
};

class KmtoMile:public Converter {
protected:
    double convert(double src) override { return src/ratio;}
    string getSourceString()override{return "km";}
    string getDestString()override{return "mile";}

public:
    KmtoMile(double r):Converter(r){}


};

int main() {
    WonToDallor wd(1010); //1dolor : 1010won
    KmtoMile km(1.609344); //1mile : 1.609344
        // wd.run();
        // km.run();

    Converter *p = &wd;
    p->run();
    // delete p; => 동적이 아닌데? stack memori임!

    Converter *p1 = new WonToDallor(1010); //이게 동적이네
    p1->run();
    delete p1;

}
