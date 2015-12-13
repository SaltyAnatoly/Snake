#include "gameengine.h"
#include "windows.h"

gameEngine::gameEngine()
{
}

void gameEngine::startGame()
{

}

void gameEngine::playGame()
{
    int caughtKey = 0;

    myField.spawnFood();

    while (caughtKey != 27 && !gameOver)
    {
        if (kbhit())
        {
            caughtKey = getch();
            if (caughtKey == 0)
                caughtKey = getch();
        }

        if (!mySnake.snakeMoving(caughtKey, myField))
            gameOver = 1;

        vis.gameConsoleOut(mySnake, myField);
    }

    vis.gameOverScreen(mySnake);
}
