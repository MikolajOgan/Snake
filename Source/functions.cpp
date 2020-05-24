void printStats(Snake& snake)
{
    std::cout << "Score:" << snake.score << std::endl;
    std::cout << "Best score:" << bestScore << std::endl;
    std::cout << "Length:" << snake.snakeCoords.size() << std::endl;
    std::cout << "Moves:" << snake.moves << std::endl;
    std::cout << "Apples:" << snake.snakeCoords.size() - 1 << std::endl;
    std::cout << "Position(" << snake.snakeCoords.at(0).x << ',' << snake.snakeCoords.at(0).y << ')' << std::endl;

    if(snake.score > bestScore)
    {
        bestScore = snake.score;
    }

    if(gameInProgress == false)
    {
        if(snake.snakeCoords.size() > 1)
        {
            std::cout << "Avg number of moves to pick one apple:" << snake.moves / (snake.snakeCoords.size() - 1) << std::endl;
        }
    }
}

void resetStats(Snake& snake)
{
    snake.moves = 0;
    snake.score = 0;
}

char getDirection()
{
    char input;
    input = getch();
    return input;
}

void settings() try
{
    std::string respond;
    std::cout << "Number of walls(0-5):";
    std::cin >> respond;
    int respond_int = std::stoi(respond);
    if(respond_int >= 1 && respond_int <= 5 )
    {
        wallsCount =  8 - respond_int;
    }
    else if(respond_int == 0)
    {
         wallsCount =  999;
    }
}

catch (std::invalid_argument& exception)
{
    std::cout << "Enter a number" << std::endl;
    settings();
}
