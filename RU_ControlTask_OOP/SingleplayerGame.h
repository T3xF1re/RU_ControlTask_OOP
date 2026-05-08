#pragma once
#include "Game.h"

class SingleplayerGame : virtual public Game
{
protected:
    string objective;
    int totalDownloads;
    int numberOfLevels;

public:
    SingleplayerGame();
    SingleplayerGame(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int downloads = 0, int levels = 0);
    SingleplayerGame(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int downloads = 0, int levels = 0);
    SingleplayerGame(SingleplayerGame& sngplayer);

    //adding a new level
    virtual void addLevel();
    //virtual void removeLevel();
    
    //refreshing to see new additional downloads
    virtual void refreshDownloads(int newDownloads);

    //randomly changing the version
    void update() override;
    void interact() override = 0;

    void printInfo() const override;
};