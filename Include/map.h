#pragma once

struct Map
{
    void drawMap();
    void createBoard();
    void refreshMap(std::vector<Coords> snakeCoords);
    void setChar(Coords coords, char charToSet);
    void addWalls();
    void addApple();
    void checkStatus(Coords snakeHeadCoords, Snake& snake);
    Map();
};

