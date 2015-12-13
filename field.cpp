#include "field.h"

field::field()
{
    srand( time( 0 ) );

    fieldLength = 20;
    fieldWidth = 40;

    /*
    _field = new cell*[fieldLength];
    for (int i = 0; i < fieldLength; i++)
        _field[i] = new cell [fieldWidth];
        */

    _field.resize(fieldLength);
    for(int i = 0; i < fieldLength; ++i)
        _field[i].resize(fieldWidth);

    for (int i = 0; i < fieldLength; i++)
        for (int j = 0; j < fieldWidth; j++)
            if(i == 0 || j == 0 || i == fieldLength - 1 || j == fieldWidth - 1)
                _field[i][j] = WALL;
            else
                _field[i][j] = BLANK;

    _field[fieldLength/2 - 1][0] = BLANK;
    _field[fieldLength/2 - 1][fieldWidth - 1] =  BLANK;
    _field[fieldLength/2][0] =  BLANK;
    _field[fieldLength/2][fieldWidth - 1] =  BLANK;
    _field[fieldLength/2 + 1][0] =  BLANK;
    _field[fieldLength/2 + 1][fieldWidth - 1] =  BLANK;

    _field[0][fieldWidth/2 - 1] =  BLANK;
    _field[fieldLength - 1][fieldWidth/2 - 1] =  BLANK;
    _field[0][fieldWidth/2] =  BLANK;
    _field[fieldLength - 1][fieldWidth/2] =  BLANK;
    _field[0][fieldWidth/2 + 1] =  BLANK;
    _field[fieldLength - 1][fieldWidth/2 + 1] =  BLANK;


    _field[1][1] =  SNAKE;
}

void field::spawnFood()
{
    int i;
    int j;

    do
    {
        i = rand() % (fieldLength - 2) + 1;
        j = rand() % (fieldWidth - 2) + 1;
    } while (_field[i][j] == SNAKE || _field[i][j] == SNAKE_TALE || _field[i][j] == SNAKE_HEAD);

     _field[i][j] = FOOD;
}

cell field::cellType(int i, int j)
{
    return _field[i][j];
}

field::~field()
{
    /*
    for (int i = 0; i < fieldLength; i++)
        delete [] _field[i];
    delete [] _field;
    */
}
