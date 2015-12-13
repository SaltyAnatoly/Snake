#ifndef SNAKE_H
#define SNAKE_H

#include "field.h"
//#include <ncurses.h>
#include <conio.h>
#include <vector>
#include <iostream>
#include "windows.h"

class snake
{
public:
    struct snakeNode
    {
        int iCurrentPosition;
        int jCurrentPosition;
    };

    std::vector <snakeNode> _snake;

    int snakeLength;

    bool isSnakeEatTheFood = 0;

    int waitTime = 100;

    int points = 0;

    snake();

    bool snakeMoving(int keyButton, field myField);

    ~snake();

private:

    const int moveUp = 119, moveDown = 115, moveRight = 100, moveLeft = 97;

    int currentDirection = DOWN;

    void snakeMove();
};

#endif // SNAKE_H
