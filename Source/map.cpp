#include "../Include/map.h"

Map::Map()
{
    createBoard();
}

void Map::addWalls()
{
    unsigned int numberOfWalls = ((size_x - 2) * (size_y - 2)) / wallsCount;
    for(unsigned int i = numberOfWalls; i > 0; --i)
    {
        Coords wallCoords(0, 0);
        wallCoords.randomCords(size_x - 2, size_y - 2);
        Map::setChar(wallCoords, '#');
    }
}

void Map::addApple()
{
        Coords appleCoords(0, 0);
        appleCoords.randomCords(size_x - 2, size_y - 2);
        while(mapContainer[appleCoords.x][appleCoords.y] != ' ')
        {
           appleCoords.randomCords(size_x - 2, size_y - 2);
        }
        Map::setChar(appleCoords, '@');
}

void Map::setChar(Coords coords, char charToSet)
{
    mapContainer[coords.x][coords.y] = charToSet;
}

void Map::drawMap()
{
    for(unsigned int y = 0; y < size_y; ++y)
    {
        for(unsigned int x = 0; x < size_x; ++x)
        {
            std::cout << mapContainer[x][y];
        }
        std::cout << std::endl;
    }
}

void Map::createBoard()
{
    for(unsigned int y = 0; y < size_y; ++y)
    {
        for(unsigned int x = 0; x < size_x; ++x)
        {
            Map::setChar(Coords(x,y),' ');
        }
    }

    for(unsigned int x = 0; x < size_x; ++x)
    {
        Map::setChar(Coords(x,0),'0');
        Map::setChar(Coords(x,size_y - 1),'0');
    }
     for(unsigned int y = 0; y < size_y; ++y)
    {
        Map::setChar(Coords(0,y),'0');
        Map::setChar(Coords(size_x - 1, y),'0');
    }

    Map::addWalls();
    Map::addApple();
}


void Map::refreshMap(std::vector<Coords> snakeCoords)
{
    system("cls");
    for(unsigned int y = 0; y < size_y; ++y)
    {
        for(unsigned int x = 0; x < size_x; ++x)
        {
            if(mapContainer[x][y] == 'S' || mapContainer[x][y] == 's')
            {
                Map::setChar(Coords(x,y),' ');
            }
        }
    }

    for(auto partOfSnake : snakeCoords)
    {
        Map::setChar(partOfSnake, 's');
    }

    Map::setChar(snakeCoords.at(0), 'S');
    Map::drawMap();
}

void Map::checkStatus(Coords snakeHeadCoords, Snake& snake)
{
    if(mapContainer[snakeHeadCoords.x][snakeHeadCoords.y] == '#' || mapContainer[snakeHeadCoords.x][snakeHeadCoords.y] == 's')
    {
        gameInProgress = false;
    }
    else if(mapContainer[snakeHeadCoords.x][snakeHeadCoords.y] == '@')
    {
        Map::addApple();
        snake.addS();
        if(snake.snakeCoords.size() % 10 == 0)
        {
            snake.score += 250;
        }
        else if(snake.snakeCoords.size() % 5 == 0)
        {
            snake.score += 150;
        }
        else
        {
            snake.score += 50;
        }
    }
}
