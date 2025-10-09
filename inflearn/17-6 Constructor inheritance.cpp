#include <iostream>
using namespace std;

class Sprite
{
    int x,y;
    string image;

public:
    Sprite(int x, int y, string image):x(x), y(y), image(image){}
    void draw(){}
    void move(){}
    
};

class Alien:public Sprite
{
    int speed;
public:
    Alien(int x, int y, string image):Sprite(x, y, image){}
    void move(){}
};

class Player:public Sprite
{
    string name;
public:
    Player(int x, int y, string image):Sprite(x, y, image){}
    void move(){}
    
};

int main()
{
    Alien a(0,100, "image 1.jpg");
    Player p(0,100, "image1.jpg");
    return 0;
}
