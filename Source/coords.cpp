#include "../Include/coords.h"

Coords::Coords(unsigned int _x, unsigned int _y)
:x(_x),
y(_y)
{

}

void Coords::randomCords(unsigned int max_x, unsigned int max_y)
{
    x = ( std::rand() % max_x) + 1;
    y = ( std::rand() % max_y) + 1;
}
