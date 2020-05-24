#include "../Include/snake.h"

Snake::Snake()
{
    Coords sCoords(0, 0);
    sCoords.randomCords(size_x - 2, size_y - 2);
    snakeCoords.push_back(sCoords);
}

void Snake::rebuild(Coords headCoords)
{
    if(snakeCoords.size() > 1)
    {
        for(unsigned int i = snakeCoords.size() - 1; i > 1; --i)
        {
            snakeCoords.at(i) = snakeCoords.at(i - 1);
        }
        snakeCoords.at(1) = headCoords;
    }
}

void Snake::moveSnake(char direction)
{
    Coords headCoords(snakeCoords.at(0).x, snakeCoords.at(0).y);
    if(direction == 'w')
    {
        snakeCoords.at(0).y -= 1;
        if(snakeCoords.at(0).y == 0)
        {
            snakeCoords.at(0).y = size_y - 2;
        }
        ++moves;
    }
    else if(direction == 's')
    {
        snakeCoords.at(0).y += 1;
        if(snakeCoords.at(0).y == size_y - 1)
        {
            snakeCoords.at(0).y = 1;
        }
        ++moves;
    }
    else if(direction == 'a')
    {
       snakeCoords.at(0).x -= 1;
        if(snakeCoords.at(0).x == 0)
        {
            snakeCoords.at(0).x = size_x - 2;
        }
        ++moves;
    }
    else if(direction == 'd')
    {
        snakeCoords.at(0).x += 1;
        if(snakeCoords.at(0).x == size_x - 1)
        {
            snakeCoords.at(0).x = 1;
        }
        ++moves;
    }

    Snake::rebuild(headCoords);
}

void Snake::addS()
{
    snakeCoords.push_back(Coords(snakeCoords.at(snakeCoords.size() - 1).x, snakeCoords.at(snakeCoords.size() - 1).y));
}
