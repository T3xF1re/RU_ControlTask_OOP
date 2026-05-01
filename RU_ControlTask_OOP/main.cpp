#include <time.h>
#include <string>
#include <iostream>
using namespace std;

#include "helpfulClassesAndFunctions.h"

//Mandatory classes

//Base class
#include "Game.h"

//First inheritor classes:
#include "SingleplayerGame.h"
#include "MultiplayerGame.h"

//Second inheritor classes
#include "Platformer.h"
#include "Sandbox.h"
#include "MOBA.h"
#include "Shooter.h"
#include "RPG.h"

//Third inheritor classes
#include "MMORPG.h"
#include "HeroShooter.h"

int main()
{
    srand(time(0));

    //test Platformer class
    Date date(2009, 5, 17);
    Version version(1210200);
    const string obst[2] = { "Wooden Box", "Rock" };
    Platformer game("Minecraft", "Notch", date, version, 16, 4.9, 2, obst ,"Reach the end", 1001, 1);
    game.printInfo();
    //
    //cout << endl;
    //
    game.update();
    game.printInfo();
}