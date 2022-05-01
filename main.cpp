#include <iostream>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Fruit.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake kigyo({WIDTH/2, HEIGHT/2}, 1);
Fruit alma;

int score;

void Map()
{
    COORD sPos = kigyo.getPosition();
    COORD fPos = alma.getPosition();

    vector<COORD> sTest = kigyo.getBody();

    cout << "Score: " << score << "\n\n";

    for(int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for(int j = 0; j < WIDTH - 2; j++)
        {
            if(i == 0 || i == HEIGHT - 1)
                cout << "#";
            else if(i == sPos.Y && j + 1 == sPos.X)
                cout << "0";
            else if(i == fPos.Y && j + 1 == fPos.X)
                cout << "@";
            else
            {
                bool isBodyPart = false;
                for(int k = 0; k < sTest.size()-1; k++)
                {
                    if(i == sTest[k].Y && j+1 == sTest[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if(!isBodyPart)
                    cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main()
{
    score = 0;

    srand(time(NULL));
    alma.makeFruit();

    bool gameOver = false;
    while(!gameOver)
    {
        Map();
        if(kbhit())
        {
            switch(getch())
            {
                case 'w': kigyo.changeDirection('u'); break;
                case 'a': kigyo.changeDirection('l'); break;
                case 's': kigyo.changeDirection('d'); break;
                case 'd': kigyo.changeDirection('r'); break;
            }
        }
        if(kigyo.halott())
            gameOver = true;


        if(kigyo.megette(alma.getPosition()))
        {
            alma.makeFruit();
            kigyo.novekedik();
            score += 10;
        }

        kigyo.moveSnake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    }
}
