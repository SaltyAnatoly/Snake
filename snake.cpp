#include "snake.h"




snake::snake()
{
    snakeNode snakeHead;
    snakeHead.iCurrentPosition = 1;
    snakeHead.jCurrentPosition = 1;
    _snake.push_back(snakeHead);
    snakeLength = 1;
}

void snake::snakeMove()
{
    if (snakeLength > 1)
        for (int i = snakeLength - 1; i > 0; i--)
        {
            _snake[i].iCurrentPosition = _snake[i - 1].iCurrentPosition;
            _snake[i].jCurrentPosition = _snake[i - 1].jCurrentPosition;
        }
}

/*
void snake::snakeControls()
{
    std::cout << "Push button which you will use for move up:    ";
    moveUp = getch();
    std::cout << static_cast<char>(moveUp) << std::endl;

    std::cout << "Push button which you will use for move left:  ";
    moveLeft = getch();
    std::cout << static_cast<char>(moveLeft) << std::endl;

    std::cout << "Push button which you will use for move down:  ";
    moveDown = getch();
    std::cout << static_cast<char>(moveDown) << std::endl;

    std::cout << "Push button which you will use for move right: ";
    moveRight = getch();
    std::cout << static_cast<char>(moveRight) << std::endl;
}
*/

bool snake::snakeMoving(int keyButton, field &myField)
{
    if ((keyButton == moveUp || currentDirection == UP) && currentDirection != DOWN)
    {
        if (_snake[0].iCurrentPosition - 1 < 0)
        {
            snakeMove();

            _snake[0].iCurrentPosition = myField.fieldLength - 1;
            currentDirection = UP;
        }
        else if (myField._field[_snake[0].iCurrentPosition - 1][_snake[0].jCurrentPosition] == BLANK)
        {
            snakeMove();

            _snake[0].iCurrentPosition--;
            currentDirection = UP;
        }
        else if (myField._field[_snake[0].iCurrentPosition - 1][_snake[0].jCurrentPosition] == FOOD)
        {
            snakeMove();

            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].iCurrentPosition--;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            myField.spawnFood();

            currentDirection = UP;
        }
        else
            return 0;
    } else if (keyButton == moveUp && currentDirection == DOWN)
        currentDirection = DOWN;


    if ((keyButton == moveDown || currentDirection == DOWN) && currentDirection != UP)
    {
        if (_snake[0].iCurrentPosition + 1 > myField.fieldLength - 1)
        {
            snakeMove();

            _snake[0].iCurrentPosition = 0;
            currentDirection = DOWN;
        }
        else if (myField._field[_snake[0].iCurrentPosition + 1][_snake[0].jCurrentPosition] == BLANK)
        {
            snakeMove();

            _snake[0].iCurrentPosition++;
            currentDirection = DOWN;
        }
        else if (myField._field[_snake[0].iCurrentPosition + 1][_snake[0].jCurrentPosition] == FOOD)
        {
            snakeMove();

            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].iCurrentPosition++;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            myField.spawnFood();

            currentDirection = DOWN;
        }
        else
            return 0;
    } else if (keyButton == moveDown && currentDirection == UP)
        currentDirection = UP;


    if ((keyButton == moveLeft || currentDirection == LEFT)  && currentDirection != RIGHT)
    {
        if (_snake[0].jCurrentPosition - 1 < 0)
        {
            snakeMove();

            _snake[0].jCurrentPosition = myField.fieldWidth - 1;
            currentDirection = LEFT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition - 1] == BLANK)
        {
            snakeMove();

            _snake[0].jCurrentPosition--;
            currentDirection = LEFT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition - 1] == FOOD)
        {
            snakeMove();
            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].jCurrentPosition--;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            myField.spawnFood();

            currentDirection = LEFT;
        }
        else
            return 0;
    } else if (keyButton == moveLeft && currentDirection == RIGHT)
        currentDirection = RIGHT;


    if ((keyButton == moveRight || currentDirection == RIGHT) && currentDirection != LEFT)
    {
        if (_snake[0].jCurrentPosition + 1 > myField.fieldWidth - 1)
        {
            snakeMove();

            _snake[0].jCurrentPosition = 0;
            currentDirection = RIGHT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition + 1] == BLANK)
        {
            snakeMove();

            _snake[0].jCurrentPosition++;
            currentDirection = RIGHT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition + 1] == FOOD)
        {
            snakeMove();
            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].jCurrentPosition++;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            myField.spawnFood();

            currentDirection = RIGHT;
        }
        else
            return 0;
    } else if (keyButton == moveRight && currentDirection == LEFT)
        currentDirection = LEFT;



    for (int i = 0; i < myField.fieldLength; i++)
        for (int j = 0; j < myField.fieldWidth; j++)
            if (myField._field[i][j] != FOOD && myField._field[i][j] != WALL)
                myField._field[i][j] = BLANK;

    for (int s = 0; s < snakeLength; s++)
        myField._field[_snake[s].iCurrentPosition][_snake[s].jCurrentPosition] = SNAKE;
    myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition] = SNAKE_HEAD;

    if (snakeLength > 1)
        myField._field[_snake[snakeLength-1].iCurrentPosition][_snake[snakeLength - 1].jCurrentPosition] = SNAKE_TALE;

    Sleep(waitTime);

    return 1;
}


snake::~snake()
{}


























