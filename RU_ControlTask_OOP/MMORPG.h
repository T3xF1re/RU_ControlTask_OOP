#pragma once
#include "RPG.h"

class MMORPG : public RPG
{
	string* npcs;
	int numberOfNPCs;

public:
    MMORPG();
    MMORPG(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int npcsNum, const string* npcs, int onlinePlayers, int servers = 1, int downloads = 0, int levels = 1);
    MMORPG(string name, string dev, Date& date, Version& version, double size, double stars, string objective, int classesNum, const string* classes, int optionsNum, const string* options, int npcsNum, const string* npcs, int onlinePlayers, int servers = 1, int downloads = 0, int levels = 1);
    MMORPG(MMORPG& mmorpg);
    ~MMORPG();

    void addNPC();
    void interact() override;
    //void update() override;

    void printInfo() const override;
};