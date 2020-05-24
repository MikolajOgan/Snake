#pragma once

struct Snake
{
    unsigned int moves;
    unsigned int score;
    std::vector<Coords> snakeCoords;
    void moveSnake(char direction);
    void addS();
    void rebuild(Coords haedCoords);
    Snake();
};
