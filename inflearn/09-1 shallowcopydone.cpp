#include <iostream>
#include <cstring>

using namespace std;

class Person {

private :
    int id; char *name;

public:
    Person(int id, const char *name);
    Person(const Person &p);
    ~Person();


    void ChangeName(const char *newname);
    void Print(){cout<<name<<" "<<id<<endl;}
};

Person ::Person(const Person &p) {
    id = p.id;

    int len = strlen(p.name);
    this->name = new char [len+1];
    strcpy(this->name, p.name);
}

Person::Person(int id, const char *name) {
    this->id = id;
    int len=strlen(name);

    this->name =new char[len+1];
    strcpy(this->name, name);

}
Person::~Person() {
    if (name) {
        delete []name;
    }
}

void Person::ChangeName(const char *newname) {
    delete[] this->name;
    int len=strlen(newname);
    this->name = new char[len+1];
    strcpy(this->name, newname);
}

void f(Person person) {
    person.ChangeName("dummy");
    // 복사로써 별개이기에 이름이 바뀌지 않겠다.
}

Person g() {
    Person mother(2, "jane");
    return mother;
}

int main() {
    Person father(1, "hyun");
    Person son(father);

    f(father); // 이름안바뀜
    father.Print();
    g().Print();

    return 0;
}
