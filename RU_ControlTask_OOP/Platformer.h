#pragma once
#include "SingleplayerGame.h"

class Platformer : public SingleplayerGame
{
protected:
    int numberOfObstacles;
    string* obstacles;

public:
    Platformer();
    Platformer(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int obstaclesNum, const string* obstacles, string objective, int downloads = 0, int levels = 1);
    Platformer(string name, string dev, Date& date, Version& version, double size, double stars, int obstaclesNum, const string* obstacles, string objective, int downloads = 0, int levels = 1);
    Platformer(Platformer& platformer);
    ~Platformer();

    void addObstacle();
    //void removeObstacle(string wasteObstacle = "", int wastePos = 0);
    void interact() override;

    void printInfo() const override;
};