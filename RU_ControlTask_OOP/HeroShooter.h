#pragma once
#include "MOBA.h"
#include "Shooter.h"

class HeroShooter : public MOBA, public Shooter
{
    string* monsters;
    int numberOfMonsters;

public:
    HeroShooter();
    HeroShooter(string name, string dev, int relDay, int relMonth, int relYear, int version, double size, double stars, int charactersNum, const string* characters, int gearNum, const string* gear, int monstersNum, const string* monsters, int onlinePlayers, int servers = 1, int downloads = 0, int levels = 1);
    HeroShooter(string name, string dev, Date& date, Version& version, double size, double stars, int charactersNum, const string* characters, int gearNum, const string* gear, int monstersNum, const string* monsters, int onlinePlayers, int servers = 1, int downloads = 0, int levels = 1);
    HeroShooter(HeroShooter& heroShotr);
    ~HeroShooter();

    void addMonster();
    void interact() override;
    //void update() override;

    void printInfo() const override;
};