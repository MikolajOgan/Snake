#include <iostream>
#include <ctime>
#include <vector>
#include <array>
#include <windows.h>
#include <conio.h>
#include <string>

#include "Source/coords.cpp"
#include "Source/snake.cpp"
#include "Source/map.cpp"
#include "Source/functions.cpp"

int main()
{
    srand(time(NULL));
    while(playAgain)
    {
        settings();
        Map map1;
        Snake snake;
        map1.refreshMap(snake.snakeCoords);
        snakeDirection = getDirection();
        while(gameInProgress)
        {
            snakeDirection = getDirection();
            snake.moveSnake(snakeDirection);
            map1.checkStatus(snake.snakeCoords.at(0), snake);
            map1.refreshMap(snake.snakeCoords);
            printStats(snake);
        }
        system("cls");
        printStats(snake);
        std::cout << "Game ended. Play again? (y/n):";
        char respond;
        std::cin >>respond;
        if(respond == 'y')
        {
            playAgain = true;
            gameInProgress = true;
            resetStats(snake);
        }else
        {
            playAgain = false;
        }
    }
    return 0;
}

