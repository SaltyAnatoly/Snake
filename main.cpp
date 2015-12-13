//LIBS += -lncurses

#include <iostream>
#include "field.h"
#include "snake.h"
#include "visual.h"
#include "gameengine.h"


int main()
{
    gameEngine game;

    game.playGame();

    system("pause");

    return 0;
}
