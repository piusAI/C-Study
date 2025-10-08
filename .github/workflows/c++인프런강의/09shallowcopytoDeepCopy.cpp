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

int main() {
    Person father(1, "hyun");
    Person son(father);

    father.Print();
    son.Print();
    son.ChangeName("jooani");

    father.Print();
    son.Print();

    return 0;
}
