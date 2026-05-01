
#include "Shooter.h"

Shooter::Shooter() :
	Game(),
	MultiplayerGame(),
	numberOfGear(0), gear(nullptr) { };

Shooter::Shooter(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int gearNum, const string* gear, int onlinePlayers, int servers) :
	Game(name, dev, relDay, relMonth, relYear, version, size, stars),
	MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
	numberOfGear(gearNum)
{
	createValuedStringArray(this->gear, gear, this->numberOfGear);
}

Shooter::Shooter(string name, string dev, Date& date, Version& version, double size, double stars, int gearNum, const string* gear, int onlinePlayers, int servers) :
	Game(name, dev, date, version, size, stars),
	MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
	numberOfGear(gearNum)
{
	createValuedStringArray(this->gear, gear, this->numberOfGear);
}

Shooter::Shooter(Shooter& shotr) :
	Game(shotr),
	MultiplayerGame(shotr),
	numberOfGear(shotr.numberOfGear)
{
	createValuedStringArray(this->gear, gear, this->numberOfGear);
}

Shooter::~Shooter()
{
	delete[] this->gear;
}