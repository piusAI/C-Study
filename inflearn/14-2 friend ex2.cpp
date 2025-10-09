#include <iostream>

using namespace std;
class Box {
    double length, widht, height;

public:
    Box(double l, double w, double h):length(l), widht(w), height(h) {}
    friend void printBox(Box box);
};

void printBox(Box box) {
    cout<< box.length<<", "<<box.widht<<", "<<box.height<<endl;
}

int main() {
    Box box1(20,40,50);
    printBox(box1);

    return 0;
}
