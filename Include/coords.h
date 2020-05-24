#pragma once

const static unsigned int size_x = 20;
const static unsigned int size_y = 10;
std::array<std::array<char, size_x>, size_y> mapContainer;
unsigned int wallsCount = 5;
bool gameInProgress = true;
char snakeDirection = '0';
bool playAgain = true;
static unsigned int bestScore = 50;

struct Coords
{
    unsigned int x;
    unsigned int y;
    void randomCords(unsigned int max_x, unsigned int max_y);
    Coords(unsigned int _x, unsigned int _y);
};
