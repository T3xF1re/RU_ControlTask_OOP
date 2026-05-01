
#include "SingleplayerGame.h"

SingleplayerGame::SingleplayerGame() :
    Game(),
    objective("Unknown"),totalDownloads(0), numberOfLevels(0) {};

SingleplayerGame::SingleplayerGame(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
		objective(objective), totalDownloads(downloads), numberOfLevels(levels) {};

SingleplayerGame::SingleplayerGame(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
		objective(objective), totalDownloads(downloads), numberOfLevels(levels) {};

SingleplayerGame::SingleplayerGame(SingleplayerGame& sngplayer) :
    Game(sngplayer.name, sngplayer.developer, sngplayer.releaseDate, sngplayer.currentVersion, sngplayer.size, sngplayer.ratingStars), 
        objective(sngplayer.objective), totalDownloads(sngplayer.totalDownloads), numberOfLevels(sngplayer.numberOfLevels) {};


void SingleplayerGame::addLevel()
{
	this->numberOfLevels++;
}
/*virtual void removeLevel()
    {
        this->numberOfLevels--;
    }
*/

void SingleplayerGame::refreshDownloads(int newDownloads)
{
	this->totalDownloads += newDownloads;
}

void SingleplayerGame::update()
{
    int verPos = rand() % 4;
    int newVersion = this->currentVersion.getVersion() + (int)pow(100, verPos);

    this->currentVersion.changeVersion(newVersion);
}

void SingleplayerGame::printInfo() const
{
    Game::printInfo();
    cout << "Until now it has " << this->totalDownloads << " downloads and " << this->numberOfLevels << " levels.\n";
    cout << "The current end objective is: " << this->objective << endl;
}