#include <ctime>
#include <vector>
#include <array>
#include <windows.h>
#include <conio.h>
#include <string>
#include "../Source/coords.cpp"
#include "../Source/snake.cpp"
#include "../Source/map.cpp"

const static unsigned int size_x = 20;
const static unsigned int size_y = 10;
std::array<std::array<char, size_x>, size_y> mapContainer;
unsigned int wallsCount = 5;
bool gameInProgress = true;
char snakeDirection = '0';
bool playAgain = true;
static unsigned int bestScore = 50;

void printStats(Snake& snake);
void resetStats(Snake& snake);
void settings();
