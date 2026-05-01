
#include "MultiplayerGame.h"


MultiplayerGame::MultiplayerGame() : Game(), onlinePlayers(0), availableServers(0)
{ calcPing(); };

MultiplayerGame::MultiplayerGame(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int onlinePlayers, int servers) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
        onlinePlayers(onlinePlayers), availableServers(servers)
{ calcPing(); };

MultiplayerGame::MultiplayerGame(string name, string dev, Date& date, Version& version, double size, double stars, int onlinePlayers, int servers) :
    Game(name, dev, date, version, size, stars),
        onlinePlayers(onlinePlayers), availableServers(servers)
{ calcPing(); };

MultiplayerGame::MultiplayerGame(MultiplayerGame& mltplayer) :
    Game(mltplayer),
        onlinePlayers(mltplayer.onlinePlayers), availableServers(mltplayer.availableServers)
{ calcPing(); };


void MultiplayerGame::calcPing()
{
    if (this->availableServers != 0)
        this->averagePing = this->onlinePlayers / (this->availableServers * this->availableServers * 100.0);
    else
        this->averagePing = -1.0;
}

void MultiplayerGame::update()
{

    int verPos = rand() % 4;
    int newVersion = this->currentVersion.getVersion() + (int)pow(100, verPos);

    this->currentVersion.changeVersion(newVersion);

    this->onlinePlayers = this->onlinePlayers * (rand() % 150 + 1) / 100;
    calcPing();
}
void MultiplayerGame::printInfo() const
{
    Game::printInfo();
    cout << "Currently it has " << this->onlinePlayers << " players online and " << this->availableServers << " available servers with average ping of " << ceil(this->averagePing * 10) / 10.0 << ".\n";
}