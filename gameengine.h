#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "snake.h"
#include "field.h"
#include "visual.h"
//#include "ncurses.h"
#include <iostream>


class gameEngine
{
public:
    int caughtKey;

    bool gameOver = 0;

    field myField;

    snake mySnake;

    visual vis;

    gameEngine();

    void startGame();

    void playGame();

};

#endif // GAMEENGINE_H
