#ifndef FRUIT_H
#define FRUIT_H

#include <windows.h>
#include <cstdlib>

#define WIDTH 50
#define HEIGHT 25

class Fruit
{
private:
    COORD position;
public:
    COORD getPosition(){return position;};

    void makeFruit();
};

void Fruit::makeFruit()
{
    position.X = (rand() % WIDTH - 3) + 1;
    position.Y = (rand() % HEIGHT - 3) + 1;
}

#endif // FRUIT_H
