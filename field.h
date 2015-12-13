#ifndef FIELD_H
#define FIELD_H

#include "enums.h"
#include <stdlib.h>
#include <time.h>
#include <vector>



class field
{
public:

    int fieldLength;
    int fieldWidth;

    //cell **_field;

    std::vector < std::vector<cell> > _field;

    field();

    void spawnFood();

    cell cellType(int i, int j);

    ~field();

};

#endif // FIELD_H
