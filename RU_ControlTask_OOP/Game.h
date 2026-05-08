#pragma once
#include <string>
using namespace std;

#include "helpfulClassesAndFunctions.h"

class Game
{
protected:
    string name;
    string developer;
    Date releaseDate;
    Version currentVersion;
    double size;
    double ratingStars;

public:
    Game();
    Game(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars);
    Game(string name, string dev, Date& date, Version& version, double size, double stars);
    Game(Game& game);

    string getName();
    virtual void update() = 0;
    virtual void interact() = 0;

    virtual void printInfo() const;
};

