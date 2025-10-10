#include <iostream>
#include <cstring>
using namespace std;

class StringBox {
private:
    char *name;
    double length, width, height;
public:

    StringBox(const char*n= "", double l=0.0, double w=0.0, double h=0.0): length(l), width(w), height(h) {
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }

    StringBox(const StringBox& other) {
        length = other.length;
        width = other.width;
        height = other.height;
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
    }

    StringBox& operator=(const StringBox& other) {
        if (this!= &other) {
            delete []name;
            name=new char[strlen(other.name)+1];
            strcpy(name, other.name);
            length =other.length;
            width = other.width;
            height = other.height;
        }
        return *this;
    }
    ~StringBox();
    void display();
    void ChangeName(const char *name);
};

void StringBox::ChangeName(const char *changename) {
    delete[] name;
    int len= strlen(changename);
    name = new char[len+1];
    strcpy(name, changename);
}

// 포인터의 길이를 구해서 name 다시 동적 할당으로 시키기위해서 길이 맞춰서
// 넣어준 changename의 char의 포인터를 하나씩 할당(strcpy)로
// 추가적으로 포인터로 메모리 주소를 불러온것

StringBox::~StringBox() {
    delete[] name;
}

void StringBox::display() {
    cout<< "name : "<< name;
    cout<< ", length : " << length;
    cout<< ", width : " << width;
    cout<< ", height : " << height<<endl;
}


int main() {
    StringBox mystringbox("joon", 2,4,5);
    mystringbox.display();

    StringBox mystringbox2(mystringbox);
    mystringbox2.ChangeName("pius");
    mystringbox2.display();

    return 0;

}
