#include "gameengine.h"
#include "windows.h"

gameEngine::gameEngine()
{
}

void gameEngine::updateField()
{
    for (int i = 0; i < myField.fieldLength; i++)
        for (int j = 0; j < myField.fieldWidth; j++)
            if (myField._field[i][j] != cell::FOOD && myField._field[i][j] != cell::WALL)
                myField._field[i][j] = cell::BLANK;

    for (int s = 0; s < mySnake.snakeLength; s++)
        myField._field[mySnake._snake[s].iCurrentPosition][mySnake._snake[s].jCurrentPosition] = cell::SNAKE;
    myField._field[mySnake._snake[0].iCurrentPosition][mySnake._snake[0].jCurrentPosition] = cell::SNAKE_HEAD;

    if (mySnake.snakeLength > 1)
        myField._field[mySnake._snake[mySnake.snakeLength-1].iCurrentPosition][mySnake._snake[mySnake.snakeLength - 1].jCurrentPosition] = cell::SNAKE_TALE;
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

        if (mySnake.isSnakeEatTheFood)
        {
            myField.spawnFood();
            mySnake.isSnakeEatTheFood = 0;
        }

        updateField();

        vis.gameConsoleOut(mySnake, myField);

        Sleep(mySnake.waitTime);
    }

    vis.gameOverScreen(mySnake);
}
