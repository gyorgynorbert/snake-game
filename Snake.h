#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
private:
    COORD position;
    int lenght, velocity;
    char direction;
    vector<COORD> test;
public:
    Snake(COORD position, int velocity);
    COORD getPosition(){return position;};

    void changeDirection(char dir);
    void moveSnake();
    bool megette(COORD fruitPos);
    void novekedik();
    bool halott();
    vector<COORD> getBody(){return test;};
};

Snake::Snake(COORD position, int velocity)
{
    this->position = position;
    this->velocity = velocity;
    lenght = 1;
    direction = 'n';

    test.push_back(position);
}

void Snake::changeDirection(char dir)
{
    this->direction = dir;
}

void Snake::moveSnake()
{
    switch(direction)
    {
        case 'u': position.Y -= velocity; break;
        case 'd': position.Y += velocity; break;
        case 'l': position.X -= velocity; break;
        case 'r': position.X += velocity; break;
    }

    test.push_back(position);
    if(test.size() > lenght)
        test.erase(test.begin());
}

bool Snake::megette(COORD fruitPos)
{
    if(fruitPos.X == position.X && fruitPos.Y == position.Y)
        return true;
    return false;
}

void Snake::novekedik()
{
    lenght++;
}

bool Snake::halott()
{
    if(position.X < 1 || position.X > WIDTH - 2 || position.Y < 1 || position.Y > HEIGHT - 2)
        return true;
    for(int i = 0; i < lenght-1; i++)
    {
        if(position.X == test[i].X && position.Y == test[i].Y)
            return true;
    }
    return false;
}

#endif // SNAKE_H
