
#include "Platformer.h"

Platformer::Platformer() :
    Game(),
    SingleplayerGame(),
        numberOfObstacles(0), obstacles(nullptr) {};

Platformer::Platformer(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int obstaclesNum, const string* obstacles, string objective, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    SingleplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, objective, downloads, levels),
        numberOfObstacles(obstaclesNum)
{
    this->obstacles = new string[this->numberOfObstacles];

    for (int i = 0; i < this->numberOfObstacles; ++i)
        this->obstacles[i] = obstacles[i];
}
Platformer::Platformer(string name, string dev, Date& date, Version& version, double size, double stars, int obstaclesNum, const string* obstacles, string objective, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    SingleplayerGame(name, dev, date, version, size, stars, objective, downloads, levels),
        numberOfObstacles(obstaclesNum)
{
    this->obstacles = new string[this->numberOfObstacles];

    for (int i = 0; i < this->numberOfObstacles; ++i)
        this->obstacles[i] = obstacles[i];
}

Platformer::Platformer(Platformer& platformer) :
    Game(platformer),
    SingleplayerGame(platformer),
        numberOfObstacles(platformer.numberOfLevels)
{
    createValuedStringArray(this->obstacles, obstacles, this->numberOfObstacles);
};

Platformer::~Platformer()
{
    delete[] obstacles;
}


void Platformer::addObstacle(string newObstacle)
{
    string* tempObst = this->obstacles;

    this->obstacles = new string[++this->numberOfObstacles];
    for (int i = 0; i < this->numberOfObstacles - 1; ++i)
        this->obstacles[i] = tempObst[i];
    this->obstacles[this->numberOfObstacles - 1] = newObstacle;

    delete[] tempObst;
}
/*void Platformer::removeObstacle(string wasteObstacle, int wastePos)
{
    string* tempObst = this->obstacles;

    this->obstacles = new string[--this->numberOfObstacles];
    for (int i = 0, j = 0; i < this->numberOfObstacles && j < this->numberOfObstacles + 1; ++j)
    {
        if ((wastePos > 0 && wastePos - 1 != j) || (wasteObstacle != "" && tempObst[j] != wasteObstacle))
            this->obstacles[i++] = tempObst[j];
    }

    delete[] tempObst;
}*/

void Platformer::printInfo() const
{
    SingleplayerGame::printInfo();
    cout << "Currently it has " << this->numberOfObstacles << " different obstacles being: " << this->obstacles[0];
    for (int i = 1; i < this->numberOfObstacles; ++i)
        cout << ", " << this->obstacles[i];
    cout << endl;
}