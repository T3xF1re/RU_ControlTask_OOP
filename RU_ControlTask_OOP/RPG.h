#pragma once
#include "SingleplayerGame.h"
#include "MultiplayerGame.h"

class RPG : public SingleplayerGame, public MultiplayerGame
{
protected:
    string* classes;
    int numberOfClasses;
    string* customisationOptions;
    int numberOfOptions;

public:
    RPG();
    RPG(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int onlinePlayers, int servers = 1, int downloads = 0, int levels = 1);
    RPG(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int classesNum, const string* classes, int customisationOptionsNum, const string* customisationOptions, int onlinePlayers, int servers = 1, int downloads = 0, int levels = 1);
    RPG(RPG& rpg);
    ~RPG();

    void update() override;
    void printInfo() const override;
};