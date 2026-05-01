#pragma once
#include "MultiplayerGame.h"

class MOBA : virtual public MultiplayerGame
{
protected:
	string* characters;
	int numberOfCharacters;

public:
	MOBA();
	MOBA(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int charactersNum, const string* characters, int onlinePlayers, int servers = 1);
	MOBA(string name, string dev, Date& date, Version& version, double size, double stars, int charactersNum, const string* characters, int onlinePlayers, int servers = 1);
	MOBA(MOBA& moba);
	~MOBA();
};