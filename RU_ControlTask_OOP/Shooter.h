#pragma once
#include "MultiplayerGame.h"

class Shooter : virtual public MultiplayerGame
{
protected:
	string* gear;
	int numberOfGear;

public:
	Shooter();
	Shooter(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int gearNum, const string* gear, int onlinePlayers, int servers = 1);
	Shooter(string name, string dev, Date& date, Version& version, double size, double stars, int gearNum, const string* gear, int onlinePlayers, int servers = 1);
	Shooter(Shooter& shotr);
	~Shooter();
};
