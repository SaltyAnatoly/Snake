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

    int waitTime = 100;

    const int moveUp = 119, moveDown = 115, moveRight = 100, moveLeft = 97;

    int currentDirection = DOWN;

    int points = 0;

    snake();

    void snakeMove();

    //void snakeControls();

    void gameOverScreen(snake mySnake);

    bool snakeMoving(int keyButton, field &myField);

    ~snake();
};

#endif // SNAKE_H
