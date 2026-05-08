#pragma once
#include "Game.h"

class MultiplayerGame : virtual public Game
{
protected:
    int onlinePlayers;
    int availableServers;
    double averagePing;

    //calculating the average ping
    void calcPing();

public:
    MultiplayerGame();
    MultiplayerGame(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int onlinePlayers, int servers = 1);
    MultiplayerGame(string name, string dev, Date& date, Version& version, double size, double stars, int onlinePlayers, int servers = 1);
    MultiplayerGame(MultiplayerGame& mltplayer);

    //randomly changing the version and setting new number of online players
    void update() override;
    void interact() override = 0;

    void printInfo() const override;
};