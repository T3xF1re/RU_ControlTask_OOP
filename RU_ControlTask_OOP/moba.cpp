
#include "MOBA.h"

MOBA::MOBA() :
	Game(),
	MultiplayerGame(),
		numberOfCharacters(0), characters(nullptr) {};

MOBA::MOBA(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int charactersNum, const string* characters, int onlinePlayers, int servers) :
	Game(name, dev, relDay, relMonth, relYear, version, size, stars),
	MultiplayerGame(name, dev, relDay, relMonth, relYear, version, size, stars, onlinePlayers, servers),
		numberOfCharacters(charactersNum)
{
	createValuedStringArray(this->characters, characters, this->numberOfCharacters);
}

MOBA::MOBA(string name, string dev, Date& date, Version& version, double size, double stars, int charactersNum, const string* characters, int onlinePlayers, int servers) :
	Game(name, dev, date, version, size, stars),
	MultiplayerGame(name, dev, date, version, size, stars, onlinePlayers, servers),
		numberOfCharacters(charactersNum)
{
	createValuedStringArray(this->characters, characters, this->numberOfCharacters);
}

MOBA::MOBA(MOBA& moba) :
	Game(moba),
	MultiplayerGame(moba),
		numberOfCharacters(moba.numberOfCharacters)
{
	createValuedStringArray(this->characters, characters, this->numberOfCharacters);
}
MOBA::~MOBA()
{
	delete[] this->characters;
}
