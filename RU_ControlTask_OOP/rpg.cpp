
#include "RPG.h"

RPG::RPG() :
    Game(),
    SingleplayerGame(),
    MultiplayerGame(),
        numberOfClasses(0), classes(nullptr), numberOfOptions(0), customisationOptions(nullptr) {};

RPG::RPG(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, relDay, relMonth, relYear, version, size, stars),
    SingleplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, objective, downloads, levels),
    MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
        numberOfClasses(classesNum), numberOfOptions(optionsNum)
{
    createValuedStringArray(this->classes, classes, this->numberOfClasses);
    createValuedStringArray(this->customisationOptions, options, this->numberOfOptions);
}

RPG::RPG(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int onlinePlayers, int servers, int downloads, int levels) :
    Game(name, dev, date, version, size, stars),
    SingleplayerGame(name, dev, date, version, size, stars, objective, downloads, levels),
    MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
        numberOfClasses(classesNum), numberOfOptions(optionsNum)
{
    createValuedStringArray(this->classes, classes, this->numberOfClasses);
    createValuedStringArray(this->customisationOptions, options, this->numberOfOptions);
}

RPG::RPG(RPG& rpg) :
    Game(rpg), 
    SingleplayerGame(rpg),
    MultiplayerGame(rpg), 
        numberOfClasses(rpg.numberOfClasses), numberOfOptions(rpg.numberOfOptions)
{
    createValuedStringArray(this->classes, rpg.classes, this->numberOfClasses);
    createValuedStringArray(this->customisationOptions, rpg.customisationOptions, this->numberOfOptions);
};

RPG::~RPG()
{
    delete[] classes;
    delete[] customisationOptions;
}


void RPG::update()
{

    int verPos = rand() % 4;
    int newVersion = this->currentVersion.getVersion() + (int)pow(100, verPos);

    this->currentVersion.changeVersion(newVersion);

    this->onlinePlayers = this->onlinePlayers * (rand() % 150 + 1) / 100;
    calcPing();
}
void RPG::printInfo() const
{
    //SingleplayerGame::printInfo();
    //cout << "Currently it has " << this->numberOfObstacles << " different obstacles being: " << this->obstacles[0];
    //for (int i = 1; i < this->numberOfObstacles; ++i)
    //    cout << ", " << this->obstacles[i];
    //cout << endl;
}
